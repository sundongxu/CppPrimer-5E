#include <iostream>
#include "../2/Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue)
    {
        Sales_data trans;
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue)
        {
            if (trans.bookNo == total.bookNo)
                total.AddData(trans);
            else
            {
                total.Print();
                total = trans;
            }
        }
        total.Print();
    }
    else
    {
        cerr << "No data ?!" << endl;
        return -1;
    }
    return 0;
}