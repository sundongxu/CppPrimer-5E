#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    vector<int> vec;
    for (vector<int>::size_type i = 0; i != 10; i++)
    {
        vec.push_back(i);
        vec.push_back(i);
    }

    set<int> iset(vec.begin(), vec.end());
    multiset<int> miset(vec.begin(), vec.end());

    cout << vec.size() << endl;
    cout << iset.size() << endl;
    cout << miset.size() << endl;

    return 0;
}