#include <iostream>

using namespace std;

int main()
{
    int i = 0;
    cin >> i;
    // 实际没有参数，直接捕获i和j进行函数体内运算
    auto sum = [i](int j) { return i + j; };

    // lambda表达式本身没有参数列表，故调用时只是空实参列表
    cout << sum(22) << endl;

    return 0;
}