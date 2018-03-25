#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {0, 1, 1, 2};
    vector<int> v2 = {0, 1, 1, 2, 3, 5, 8};

    auto size = v1.size() < v2.size() ? v1.size() : v2.size();
    for (decltype(v1.size()) i = 0; i != v1.size(); i++)
    {
        if (v1[i] != v2[i])
        {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;

    return 0;
}