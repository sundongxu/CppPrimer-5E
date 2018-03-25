#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(10, 42);
    auto i1 = v.begin();
    auto i2 = v.end();
    cout << i1 - i2 << endl; // 指向后面元素的迭代器大些
    // cout << i1 + i2 << endl;
    return 0;
}