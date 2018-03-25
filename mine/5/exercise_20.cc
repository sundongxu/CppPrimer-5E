#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "", pres = "";
    while (cin >> s)
        if (s == pres)
            break;
        else
            pres = s;

    if (s == pres)
        cout << s << " occurs twice in succession." << endl;
    else
        cout << "no repeat words.";
    return 0;
}