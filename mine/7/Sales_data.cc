#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else
    {
        cerr << "No data ?!" << endl;
        return -1;
    }
    return 0;
}