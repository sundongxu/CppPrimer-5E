#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin(); // 返回首前元素
    auto curr = flst.begin();

    while (curr != flst.end())
    {
        if (*curr & 0x1) // 条件非0则curr指向一个奇数元素，删除之
            // 删除curr指向的元素，并将curr重新赋值为指向被删除元素之后的元素的迭代器
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : flst)
        cout << i << " ";

    return 0;
}