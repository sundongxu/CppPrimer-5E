#include <iostream>
#include <string>

using namespace std;

// 判断两个字符串是否其中一个是另一个的子串
bool str_subrange(const string &str1, const string &str2)
{
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size() ? str1.size() : str2.size());
    for (decltype(size) i = 0; i != size; i++)
        if (str1[i] != str2[i])
            return false;
    // return true; // 缺失该处返回值，编译器并不会报错，但运行时行为未定义
}

int main()
{
    bool b = str_subrange("abc", "abcdasdsa");
    cout << b << endl;
    return 0;
}