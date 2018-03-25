#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec(ia, end(ia));
    list<int> lst(vec.begin(), vec.end());

    for (auto it = lst.begin(); it != lst.end();)
    {
        if (*it & 0x1)
            // 与0...01按位与操作，如结果为0...01，即非0，则为奇数，list删掉奇数元素
            it = lst.erase(it);
        else
            ++it;
    }

    for (auto it = vec.begin(); it != vec.end();)
    {
        if (*it & 0x1)
            // 与0...01按位与操作，如结果为0...0，即为0，则为偶数，vector删掉偶数元素
            ++it;
        else
            it = vec.erase(it);
    }

    cout << "list: ";
    for (auto i : lst)
        cout << i << " ";

    cout << endl;

    cout << "vector: ";
    for (auto i : vec)
        cout << i << " ";

    cout << endl;
    return 0;
}