#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IsEqual
{
    int value;

  public:
    IsEqual(int v) : value(v) {}
    bool operator()(int elem) { return elem == value; }
};

int main()
{
    vector<int> vec = {3, 7, 7, 4, 3, 7, 8, 6};
    replace_if(vec.begin(), vec.end(), IsEqual(7), 777);
    for (int i : vec)
        cout << i << " ";
    cout << endl;
}