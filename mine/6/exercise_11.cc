#include <iostream>

using namespace std;

void reset(int &n)
{
    n = 0;
}

int main()
{
    int j = 24;
    cout << "before reset, j=" << j << endl;
    reset(j);
    cout << "after reset, j=" << j << endl;
    return 0;
}