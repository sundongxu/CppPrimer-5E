#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "", pres = "";
    bool no_twice = true;
    while (cin >> s)
    {
        if (!isupper(s[0]))
            continue;
        if (s == pres)
        {
            cout << s << " occurs twice in succession." << endl;
            no_twice = false;
            break;
        }
        else
            pres = s;
    }

    if (no_twice)
        cout << "no repeat words.";

    return 0;
}