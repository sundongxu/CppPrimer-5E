#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}

int main()
{
    vector<int> vec{1, 2, 3, 6, 7, 8};
    string s("abc");
    // _1实际就是从vec的首元素一直到尾元素的迭代变量
    // 故check_size定义的时候判断 s的长度是否小于_1代表的元素的int值，这样才能找到第一个比s长度大的元素 auto it = find_if(vec.cbegin(), vec.cend(), bind(check_size, s, _1));
    // 谓词条件第一次满足时候find_if即返回指向该元素的迭代器
    auto it = find_if(vec.cbegin(), vec.cend(), bind(check_size, s, _1));
    cout << *it << endl;
    return 0;
}