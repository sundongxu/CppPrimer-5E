#include <iostream>
#include <vector>

using namespace std;
using T = int (*)(int, int);

int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return b != 0 ? a / b : 0;
}

int main()
{
    vector<T> v = {add, subtract, multiply, divide};
    vector<decltype(add) *> v1 = {add, subtract, multiply, divide};
    for (auto f : v)
        cout << f(6, 2) << endl;
    for (auto f : v1)
        cout << f(6, 2) << endl;
    return 0;
}