#include <iostream>
#include <string>

using namespace std;

// void replace_all(string &s, const string &oldVal, const string &newVal)
// {
//     auto curr = s.begin();
//     auto sizeOld = oldVal.size();
//     while (distance(curr, s.end()) >= distance(oldVal.begin(), oldVal.end()))
//     {
//         if (oldVal == string(curr, curr + sizeOld))
//         {
//             // 替换 = 删除 +　插入
//             // cout << "replace happened..." << endl;
//             // erase后，返回的迭代器指向被删除元素的下一个元素
//             curr = s.erase(curr, curr + sizeOld);
//             // insert后，返回的迭代器指向新插入的第一个元素
//             curr = s.insert(curr, newVal.begin(), newVal.end());
//             curr += newVal.size(); //　这一步尤其重要，跳过新插入的元素
//         }
//         else
//         {
//             ++curr;
//         }
//     }
// }

void replace_all(string &s, const string &oldVal, const string &newVal)
{
    // for (auto i = 0; i != s.size(); ++i)
    //     if (s.substr(i, oldVal.size()) == oldVal)
    //     {
    //         s.replace(i, oldVal.size(), newVal);
    //         i += (newVal.size() - 1); // 为什么要-1??? 因为执行完了这里i还会递增++，在for中的第三个表达式体现！！！
    //     }
    decltype(s.size()) i = 0;
    while (i != s.size())
    {
        if (s.substr(i, oldVal.size()) == oldVal)
        {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        }
        else
            ++i;
    }
}

int main()
{
    {
        string str{"To drive straight thru is a foolish, thru tho courageous act."};
        replace_all(str, "thru", "through");
        replace_all(str, "tho", "though");
        std::cout << str << std::endl;
    }
    {
        string str{"To drive straight thruthru is a foolish, thotho courageous act."};
        replace_all(str, "thru", "through");
        replace_all(str, "tho", "though");
        std::cout << str << std::endl;
    }
    {
        string str{"To drive straight thru is a foolish, tho courageous act."};
        replace_all(str, "thru", "thruthru");
        replace_all(str, "tho", "though");
        std::cout << str << std::endl;
    }
    {
        string str{"my world is a big world"};
        replace_all(str, "world",
                    "worldddddddddddddddddddddddddddddddddddddddddddddddd");
        std::cout << str << std::endl;
    }
    return 0;
}