#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    string s = "";
    int i = 0;
    vector<pair<string, int>> vec;
    while (cin >> s >> i)
        // vec.push_back(make_pair(s, i));
        // vec.push_back({s, i});
        // vec.push_back(pair<string, int>(s, i));
        vec.emplace_back(s, i);

    for (auto p : vec)
        cout << p.first << ":" << p.second << endl;
    return 0;
}