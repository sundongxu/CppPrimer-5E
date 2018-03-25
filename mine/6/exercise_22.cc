#include <iostream>
using namespace std;

void swap(const int *&lhs, const int *&rhs)
{
    auto tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main()
{
    const int i = 1, j = 2;
    auto lhs = &i;
    auto rhs = &j;
    cout << "before pointer swap: lhs=" << lhs << ", rhs=" << rhs << endl;
    swap(lhs, rhs);
    cout << "after pointer swap: lhs=" << lhs << ", rhs=" << rhs << endl;
    return 0;
}