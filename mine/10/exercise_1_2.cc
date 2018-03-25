#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

int main()
{
    // vector<int> vec{1, 2, 34, 34, 65, 12, 34, 65, 90, 100, 34};
    // cout << "34 appears " << count(vec.cbegin(), vec.cend(), 34) << " times" << endl;
    // cout << "100 appears " << count(vec.cbegin(), vec.cend(), 100) << " times" << endl;
    // cout << "65 appears " << count(vec.cbegin(), vec.cend(), 65) << " times" << endl;

    list<string> li;
    string s;
    ifstream ifs("data/count_string");
    // while (cin >> s)
    while (ifs >> s)
    {
        li.push_back(s);
    }

    for (auto ss : li)
        cout << ss << " ";

    cout << endl;
    cout << "abc appears " << count(li.cbegin(), li.cend(), "abc") << " times" << endl;
    cout << "xyz appears " << count(li.cbegin(), li.cend(), "xyz") << " times" << endl;
    cout << "defg appears " << count(li.cbegin(), li.cend(), "defg") << " times" << endl;

    return 0;
}