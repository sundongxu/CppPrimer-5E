#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<string, vector<string>> families;
    string lastName, chldName;

    auto f = [&]() {
        return cin >> lastName && lastName != "@q";
    };

    while (f())
    {
        cout << "Please Enter children's name:\n";
        while (cin >> chldName && chldName != "@q")
        {
            //! add new items into the vector
            families[lastName].push_back(chldName);
        }
    }

    //! iterate through the map.
    for (auto e : families)
    {
        cout << e.first << ":\n";

        //! iterate through the vector.
        for (auto c : e.second)
            cout << c << " ";
        cout << "\n";
    }
    return 0;
}
