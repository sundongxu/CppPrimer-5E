#include <iostream>
using namespace std;

using st = size_t;
using int_array4 = int[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    // 1. range for
    for (int_array4 &row : ia) // 得到一个行数组的引用
        for (int col : row)
            cout << col << endl;

    // 2. for + index
    for (st i = 0; i != 3; i++)
        for (st j = 0; j != 4; j++)
            cout << ia[i][j] << endl;

    // 3. for +_pointer
    for (int_array4 *p = ia; p != ia + 3; p++) // 得到一个行数组的指针
        for (int *q = *p; q != *p + 4; q++)
            cout << *q << endl;

    return 0;
}