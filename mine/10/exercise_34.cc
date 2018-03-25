#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i = vec.crbegin(); i != vec.crend(); ++i)
        cout << *i << " ";
    return 0;
}
