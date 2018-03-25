#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<char> vec{'p', 'e', 'z', 'y'};
    string str(vec.begin(), vec.end());

    cout << str << endl;
    return 0;
}