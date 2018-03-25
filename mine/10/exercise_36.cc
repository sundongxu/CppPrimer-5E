#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> lst = {1, 2, 3, 4, 0, 5, 0, 8, 9, 11, 0, 12};
    auto it = find(lst.crbegin(), lst.crend(), 0);        // 返回指向最后一个0的反向迭代器
    cout << *it << " in front of " << *it.base() << endl; // 调用base后迭代器指向后一个元素
    return 0;
}
