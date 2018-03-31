#include "exercise_44.h"
#include <vector>
#include <iostream>

using namespace std;

void foo(String x)
{
    cout << x.c_str() << endl;
}

void bar(const String &x)
{
    cout << x.c_str() << endl;
}

String baz()
{
    String ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    String s0;
    String s1("hello");
    String s2(s0);  // copy-construct
    String s3 = s1; // copy-construct
    String s4(text);
    s2 = s1; // copy-assignment

    foo(s1);           // copy-construct + hello
    bar(s1);           // hello
    foo("temporary");  // temporary
    bar("temporary");  // temporary
    String s5 = baz(); // 并未调用拷贝构造
    // baz()返回一个临时String对象，用于初始化s5，但是没有调用拷贝构造，那是怎么初始化的？？？

    vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());      // move construct
    svec.push_back("good job"); // move construct

    for (const auto &s : svec)
    {
        cout << s.c_str() << endl;
    }
}