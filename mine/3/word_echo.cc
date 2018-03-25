#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    while (cin >> word) // 一次读取全部数据，但按空格分隔，换行符执行循环
        cout << word << endl;
    return 0;
}