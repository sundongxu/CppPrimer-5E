#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> v2; // 空vector，一个元素都没有！size=0
    for (int i = 0; i != 100; ++i)
        v2.push_back(i);
    for (int i : v2)
        cout << i << endl;
    return 0;
}