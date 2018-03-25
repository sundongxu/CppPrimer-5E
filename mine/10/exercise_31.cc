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

    vector<int> vec(in_iter, eof); // 直接用标准输入流初始化vec

    // copy(in_iter, eof, vec.begin()); // 从标准输入读取整数序列到vector中
    sort(vec.begin(), vec.end());
    unique_copy(vec.cbegin(), vec.cend(), out_iter);

    return 0;
}