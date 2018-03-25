#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool fiveOrMore(const string &word)
{
    return word.size() >= 5;
}

int main()
{
    vector<string> vec{"a", "as", "aasss",
                       "aaaaassaa", "aaaaaabba", "aaa"};
    auto pivot = partition(vec.begin(), vec.end(), fiveOrMore);
    for (auto it = vec.begin(); it != pivot; ++it)
        cout << *it << endl;

    return 0;
}