#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs("data/elimDup");
    istream_iterator<string> in(ifs), eof;
    ostream_iterator<string> out(cout, " ");
    vector<string> vec;
    // while (in != eof)
    // {
    //     vec.push_back(*in++);
    // }

    copy(in, eof, back_inserter(vec));
    copy(vec.cbegin(), vec.cend(), out);

    // for (auto s : vec)
    //     cout << s << " ";

    cout << endl;
    return 0;
}