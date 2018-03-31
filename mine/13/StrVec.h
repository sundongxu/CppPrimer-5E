#ifndef STR_VEC_H
#define STR_VEC_H

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>
#include <initializer_list>

using namespace std;

class StrVec
{
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr)
    {
        cout << "call default constructor" << endl;
    }
    StrVec(initializer_list<string> il)
    {
        range_initialize(il.begin(), il.end());
        cout << "call range constructor" << endl;
    };
    StrVec(const StrVec &rhs)
    {
        range_initialize(rhs.begin(), rhs.end());
        cout << "call copy contructor" << endl;
    }

    // 移动操作不应抛出任何异常
    StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap)
    {
        // 令s进入这样的状态——对其运行析构函数是安全的
        s.elements = s.first_free = s.cap = nullptr;
        cout << "call move constructor" << endl;
    }

    StrVec &operator=(const StrVec &);

    StrVec &operator=(StrVec &&rhs) noexcept
    {
        if (this != &rhs) // 检查自赋值
        {
            // 非自赋值
            free();                  // 释放已有元素
            elements = rhs.elements; // 从rhs接管资源
            first_free = rhs.first_free;
            cap - rhs.cap;
            rhs.elements = rhs.first_free = rhs.cap = nullptr; // 将rhs置于可析构状态
        }
        cout << "move assignment" << endl;
        return *this;
    }

    ~StrVec();

    void push_back(const string &); // 拷贝元素
    void push_back(string &&);      // 移动元素
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string &);

  private:
    static allocator<string> alloc; // 内存分配器
    void chk_n_alloc()              // 确保有容纳一个新元素的空间
    {
        if (size() == capacity())
            reallocate();
    }

    // 工具函数，被拷贝构造、赋值运算符和析构函数使用
    pair<string *, string *> alloc_n_copy(const string *, const string *);
    void alloc_n_move(size_t new_cap);
    void free();       // 销毁元素并释放内存
    void reallocate(); // 获取更多内存并拷贝已有元素
    void range_initialize(const string *, const string *);

    string *elements;   // 指向数组首元素指针
    string *first_free; // 指向数组最后一个空闲元素的指针
    string *cap;        // 指向数组尾后位置的指针
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    // construct过程调用了拷贝构造函数
    alloc.construct(first_free++, s); // 在第一个空闲位置构造一个新元素，并后移指针
    cout << "call push_back(copy)" << endl;
}

void StrVec::push_back(string &&s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
    cout << "call push_back(move)" << endl;
}

void StrVec::reserve(size_t new_cap)
{
    if (new_cap <= capacity())
        return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, string());
}

void StrVec::resize(size_t count, const string &s)
{
    if (count > size())
    {
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, s);
    }
    else if (count < size())
    {
        while (first_free != elements + count)
            alloc.destroy(--first_free); // 逆序销毁元素，这样销毁完了之后就把数据成员直接全更新好了
    }
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);             // 分配空间保存给定范围内的元素
    return {data, uninitialized_copy(b, e, data)}; // 初始化，并返回一个pair
    // 该pair由data和uninitialized_copy的返回值构成
    // uninitialized_copy返回的是尾后元素的位置，也就是第一个空闲元素的位置
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::free()
{
    if (elements)
    {
        // for (auto p = first_free; p != elements;)
        //     //  逆序销毁元素
        //     alloc.destroy(--p);
        for_each(elements, first_free, [](string &rhs) { alloc.destroy(&rhs); });
        alloc.deallocate(elements, cap - elements); // 一次性必须把之前申请的全部的空间都释放
    }
}

// StrVec::StrVec(const StrVec &s)
// {
//     auto newdata = alloc_n_copy(s.begin(), s.end());
//     elements = newdata.first;
//     first_free = cap = newdata.second;
// }

StrVec::~StrVec()
{
    free();
}

StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    cout << "copy assignment" << endl;
    return *this;
}

void StrVec::reallocate()
{
    // 分配当前size的两倍大小
    auto newcapacity = size() ? 2 * size() : 1;
    // 分配新内存
    auto first = alloc.allocate(newcapacity);
    // 将数据从旧内存移动到新内存

    // auto last = first;    // 指向新数组中的下一个空闲位置
    // auto elem = elements; // 指向旧数组中下一个元素
    // for (size_t i = 0; i != size(); i++)
    //     alloc.construct(last++, std::move(*elem++));

    // 用移动迭代器，解引用运算符生成一个右值引用
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);

    free(); // 一旦我们移动完旧数组的元素就释放旧内存空间
    // 更新数据结构，用新数组的指针
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::range_initialize(const string *first, const string *last)
{
    auto newdata = alloc_n_copy(first, last);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

#endif