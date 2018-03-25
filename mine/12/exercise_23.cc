#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    const char *c1 = "Hello ";
    const char *c2 = "World";
    unsigned len = strlen(c1) + strlen(c2) + 1;
    char *r = new char[len]();
    strcat(r, c1);
    strcat(r, c2);
    cout << r << endl;

    string s1 = "Hello ";
    string s2 = "World";
    strcpy(r, (s1 + s2).c_str());
    cout << r << endl;

    delete[] r;

    return 0;
}