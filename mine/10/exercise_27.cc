#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec{3, 5, 1, 5, 1, 7, 3, 7, 9};
    list<int> lst;
    sort(vec.begin(), vec.end());
    // 居然还必须先sort一下，使得大小相同的元素相邻...
    unique_copy(vec.cbegin(), vec.cend(), inserter(lst, lst.begin()));
    for (int i : lst)
        cout << i << " ";
    cout << endl;
    return 0;
}