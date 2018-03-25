#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> v;
    string s;
    ifstream is("data/test");
    if (is)
        // while (getline(is, s))  // 每一行为一个元素，以换行符分隔元素
        while (is >> s) // 每一个单词未一个元素，以空格符分隔元素
            v.push_back(s);

    for (string ss : v)
        cout << ss << endl;
    return 0;
}