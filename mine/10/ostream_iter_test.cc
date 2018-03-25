#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    ostream_iterator<int> out_iter(cout, "\n"); // 默认间隔符为""
    vector<int> vec(10, 1);                     // 10个元素，值均为1
    copy(vec.cbegin(), vec.cend(), out_iter);
    cout << endl;
}