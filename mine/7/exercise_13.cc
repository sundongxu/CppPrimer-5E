#include <iostream>
#include "Sales_data.h"

using namespace std;

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this; // 返回调用对象自身
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

int main()
{
    Sales_data total(cin);
    if (!total.isbn().empty())
    {
        istream &is = cin;
        while (is)
        {
            Sales_data trans(is);
            if (trans.isbn() == total.isbn())
                total.combine(trans);
            else
            {
                print(cout, total) << endl;
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

    // for debug test
    // cout << "Hello World!" << endl;
    // cout << "Hello C++ Primer!" << endl;
    return 0;
}