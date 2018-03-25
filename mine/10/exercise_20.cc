#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words{"cppprimer", "pezy", "learncpp",
                         "greater", "rewrite", "programmer"};

    cout << count_if(words.cbegin(), words.cend(), [](const string &word) {
        return word.size() > 6;
    }) << std::endl;
}