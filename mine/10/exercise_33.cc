#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    // 三个参数，argc=4
    // argv[1]: 输入文件名
    // argv[2]: 输出文件名1
    // argv[3]: 输出文件名2

    ifstream ifs("data/numbers");
    istream_iterator<int> in_iter(ifs), eof;

    ofstream ofs1("data/odds"), ofs2("data/evens");
    ostream_iterator<int> odd_out(ofs1, " "), even_out(ofs2, "\n");
    auto pre_iter = in_iter;

    // while (in_iter != eof)
    // {
    // pre_iter = in_iter;
    // if (*in_iter++ & 0x1)
    //     copy(pre_iter, in_iter, odd_out);
    // else
    //     copy(pre_iter, in_iter, even_out);
    // copy(pre_iter, in_iter, odd_out); // if (*in_iter & 0x1) // 奇数
    //     copy(in_iter, ++in_iter, odd_out);  // 参数计算的先后顺序未指定，会产生未定义的结果
    // else
    //     copy(in_iter, ++in_iter, even_out);
    // }

    // 其中lambda表达式的函数体中的*和++都可以去掉，只是为了与其他iterator用法保持一致，并无实际作用
    for_each(in_iter, eof, [&odd_out, &even_out](const int i) { *(i & 0x1 ? odd_out : even_out)++ = i; });

    return 0;
}