#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s("Hello, World!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << " punctuation characters in " << s << endl;

    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;

    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); ++index)
        s[index] = tolower(s[index]);
    cout << s << endl;
    return 0;
}