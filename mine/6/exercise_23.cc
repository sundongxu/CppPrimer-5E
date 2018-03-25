#include <iostream>

using namespace std;

void print(const int *pi)
{
    if (pi)
        cout << *pi << endl;
}

void print(const int *ai, const size_t n)
{
    if (ai)
    {
        for (auto i = 0; i != n; i++)
            cout << ai[i] << endl;
    }
}

// 与上函数重复定义，不算重载，形参类型完全一样
// void print(const int ai[], const size_t n)
// {
//     if (ai)
//     {
//         for (auto i = 0; i != n; i++)
//             cout << ai[i] << endl;
//     }
// }

void print(const int *beg, const int *end)
{
    while (beg != end)
        cout << *beg++ << endl;
}

// 数组的引用
void print(const int (&arr)[2])
{
    for (auto i : arr)
        cout << i << endl;
}

int main()
{
    int i = 1, j[2] = {2, 3};
    print(&i);
    print(j, 2);
    print(begin(j), end(j));
    print(j);
    return 0;
}