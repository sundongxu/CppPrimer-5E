#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> vec;
    ifstream ifs("data/elimDup");
    string s;
    while (ifs >> s)
        vec.push_back(s);

    // ex_9
    // cout << "before eliminating the duplications: " << endl;
    // for (string ss : vec)
    //     cout << ss << " ";
    // cout << endl
    //      << endl;
    // elimDups(vec);
    // cout << "after eliminating the duplications: " << endl;
    // for (string ss : vec)
    //     cout << ss << " ";
    // cout << endl;

    // test stable_sort
    elimDups(vec);
    stable_sort(vec.begin(), vec.end(), isShorter);
    for (auto ss : vec)
        cout << ss << " ";
    cout << endl;
    return 0;
}