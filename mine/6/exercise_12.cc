#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int i = 1, j = 2;
    cout << "before swap(): i=" << i << ", j=" << j << endl;
    swap(i, j);
    cout << "after swap(): i=" << i << ", j=" << j << endl;
    return 0;
}