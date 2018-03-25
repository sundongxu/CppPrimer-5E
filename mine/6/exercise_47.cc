#include <iostream>
#include <vector>

// 增加编译选项 -D NDEBUG，效果等价下面定义预处理变量NDEBUG，即关闭调试状态
// #define NDEBUG

using namespace std;

void print(vector<int> &v)
{
#ifndef NDEBUG // 未定义NDEBUG
    cout << "vector size:" << v.size() << endl;
#endif
    if (!v.empty())
    {
        auto tmp = v.back();
        v.pop_back();
        print(v);
        cout << tmp << endl;
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    print(v);
    return 0;
}
