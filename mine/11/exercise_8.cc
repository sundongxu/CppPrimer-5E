#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> exclude = {"aa", "bb", "cc"}; // c++11可以编译通过
    for (string word; cin >> word;)
    {
        // 如果在vector中找到word，重复元素将不再放入
        if (find(exclude.begin(), exclude.end(), word) != exclude.end())
            cout << "word already exists!" << endl;
        else
            exclude.push_back(word);
    }

    for (auto const &s : exclude)
        cout << s << " ";
    cout << endl;
    return 0;
}
