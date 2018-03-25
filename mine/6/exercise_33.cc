#include <iostream>
#include <vector>

using namespace std;
using Iter = vector<int>::iterator;

void print(Iter beg, const Iter &end)
{
    if (beg != end)
    {
        cout << *beg++ << endl;
        print(beg, end);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    print(v.begin(), v.end());
    return 0;
}