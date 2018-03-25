#include <iostream>
#include <string>

using namespace std;

int main()
{
    string numbers("0123456789"), alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string s("ab2c3d7R4E6");

    for (string::size_type pos = 0; (pos = s.find_first_of(numbers, pos)) != string::npos; ++pos)
        cout << s[pos] << endl;

    for (string::size_type pos = 0; (pos = s.find_first_of(alphabet, pos)) != string::npos; ++pos)
        cout << s[pos] << endl;

    return 0;
}