#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    ostream_iterator<int> out_iter(cout, " ");

    vector<int> vec; // 直接用标准输入流初始化vec
    // vector<int> vec(in_iter, eof);
    copy(in_iter, eof, back_inserter(vec)); // 从标准输入读取整数序列到vector中
    // copy(in_iter, eof, vec.begin()); // 会报段错误！！！

    sort(vec.begin(), vec.end());
    copy(vec.cbegin(), vec.cend(), out_iter);

    return 0;
}