#include <iostream>

using namespace std;

size_t count_add(int n)
{
    static size_t ctr = 0;
    ctr += n;
    return ctr;
}

int main()
{
    for (size_t i = 0; i != 10; i++)
        cout << count_add(i) << endl;
    return 0;
}