#include "exercise_44.h"
#include <algorithm>
#include <iostream>

using namespace std;

ostream &operator<<(ostream &os, const String &s)
{
    auto c = s.c_str();
    while (*c)
        os << *c++;
    return os;
}

pair<char *, char *> String::alloc_n_copy(const char *b, const char *e)
{
    auto str = alloc.allocate(e - b);
    return {str, uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char *first, const char *last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char *s)
{
    char *sl = const_cast<char *>(s);
    while (*sl)
        ++sl;
    range_initializer(s, ++sl);
}

String::String(const String &rhs)
{
    range_initializer(rhs.elements, rhs.end);
    cout << "copy constructor" << endl;
}

String::String(String &&rhs) noexcept : elements(rhs.elements), end(rhs.end)
{
    rhs.elements = rhs.end = nullptr; // 将旧对象置于可析构的状态
    cout << "move constructor" << endl;
}

void String::free()
{
    if (elements)
    {
        for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String &String::operator=(const String &rhs)
{
    auto newstr = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    cout << "copy-assignment" << endl;
    return *this;
}

String &String::operator=(String &&rhs)
{
    if (this != &rhs)
    {
        free(); // 释放旧内存
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    cout << "move-assignment" << endl;
    return *this;
}