#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>
#include <initializer_list>
#include "StrBlobPtr.h"

using namespace std;

class StrBlob
{
    friend class StrBlobPtr;
    StrBlobPtr begin() { return StrBlobPtr(*this); }
    StrBlobPtr end()
    {
        auto ret = StrBlobPtr(*this, data->size());
        return ret;
    }

  public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // 添加、删除元素
    void push_back(const string &t) { data->push_back(t); } // 不用检查边界条件:vector是否为空
    void pop_back();
    // 访问元素
    string &front();
    string &back();

    const string &front() const;
    const string &back() const;

  private:
    shared_ptr<vector<string>> data;
    // 如果data[i]不合法，抛出一个异常
    void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    // 如果vector未空，check抛出一个异常：试图在空StrBlob中进行front操作
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const string &StrBlob::front() const
{
    // 如果vector未空，check抛出一个异常：试图在空StrBlob中进行front操作
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

#endif