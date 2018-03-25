#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> vs = {"1", "10", "100", "1000.5"};
    int isum = 0;
    float fsum = 0;
    for (auto const &s : vs)
        isum += stoi(s);
    cout << isum << endl;

    for (auto const &s : vs)
        fsum += stof(s);
    cout << fsum << endl;
    return 0;
}