#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst(5); // 未指定大小时不能复制到list，为什么？？？
    reverse_copy(vec.cbegin() + 3, vec.cbegin() + 8, lst.begin());
    for (auto i : lst)
        cout << i << " ";

    return 0;
}
