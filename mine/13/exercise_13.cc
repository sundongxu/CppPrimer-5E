#include <iostream>

using namespace std;

struct X
{
    X() { cout << "X()" << endl; }                                     // 默认构造
    X(const X &) { cout << "X(const X&)" << endl; }                    // 拷贝构造
    X &operator=(const X &) { cout << "operator=(const X&)" << endl; } // 赋值运算符
    ~X() { cout << "~X()" << endl; }
};

int main()
{
    X x1;      // 默认构造
    X x2(x1);  // 拷贝构造
    X x3 = x1; // 拷贝构造
    X x4;      // 默认构造
    x4 = x1;   // 赋值运算
    return 0;
}
// 依次析构