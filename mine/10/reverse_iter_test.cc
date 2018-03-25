#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    // vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); r_iter++)
    //     cout << *r_iter << " ";

    string s("FIRST,MIDDLE,LAST");
    auto comma = find(s.cbegin(), s.cend(), ','); // 第三个参数不能是字符串"xxx"，只能是字符'x'
    cout << string(s.cbegin(), comma) << endl;    // comma 比 cbegin() 要大，必须在后一个位置
    auto rcomma = find(s.crbegin(), s.crend(), ',');
    cout << string(s.crbegin(), rcomma) << endl; // rcomma 比 crbegin() 要大，必须在后一个参数位置

    cout << "use base(): ";
    cout << string(rcomma.base(), s.cend()) << endl;

    return 0;
}