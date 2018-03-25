#include <iostream>
#include <forward_list>

using namespace std;

// my version
void find_and_insert(forward_list<string> &flst, const string &s1, const string &s2)
{
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr == s1)
        {
            prev = curr;
            curr = flst.insert_after(curr, s2); // 将s2插入到s1之后的位置，并返回指向s2的迭代器
            break;
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
    if (curr == flst.end())
        curr = flst.insert_after(prev, s2);
}

// answer version
// void find_and_insert(forward_list<string> &list, const string &to_find, const string &to_add)
// {
//     auto prev = list.before_begin();
//     auto size = std::distance(list.begin(), list.end());
//     for (auto curr = list.begin(); curr != list.end(); prev = curr++)
//         if (*curr == to_find)
//             list.insert_after(curr, to_add);
// forward_list 大小没有变化说明没有在之前找到to_find并插入to_add成功，则应在末尾插入to_add
//     if (size == std::distance(list.begin(), list.end()))
//         list.insert_after(prev, to_add);
// }

int main()
{
    forward_list<string> flst = {"abc", "def", "mmmm", "kobe", "lebron"};
    string s1("kobe");
    string s2("durant");
    find_and_insert(flst, s1, s2);
    for (auto s : flst)
        cout << s << " ";
    cout << endl;
    string s3("steph");
    string s4("drozan");
    find_and_insert(flst, s3, s4);
    for (auto s : flst)
        cout << s << " ";
    cout << endl;
    return 0;
}