#include <iostream>
#include <string>

using namespace std;

int main()
{
    string longestWord;
    for (string word; cin >> word;)
    {
        if (word.find_first_not_of("aceimnorsuvwxz") == string::npos && word.size() > longestWord.size())
            longestWord = word;
    }

    cout << longestWord << endl;
    return 0;
}