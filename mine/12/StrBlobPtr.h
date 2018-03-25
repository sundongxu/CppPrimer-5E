#ifndef STR_BLOB_PTR_H
#define STR_BLOB_PTR_H

#include <vector>
#include <string>
#include <memory>
#include "StrBlob.h"

using namespace std;

class StrBlobPtr
{
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incr(); // 前缀递增

  private:
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr; // 保存一个weak_ptr，意味着底层vector可能会被销毁
    size_t curr;                   // 在数组中的当前位置
};

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, string &msg)
{
    auto ret = wptr.lock(); // vector还存在吗？
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}

#endif