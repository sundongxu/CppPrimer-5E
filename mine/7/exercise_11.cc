#include "Sales_data.h"

Sales_data::Sales_data(istream &is)
{
    read(is, *this); // 从is输入流中读取内容存放至本对象(初始化本对象->构造)
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
    Sales_data item1;
    print(cout, item1) << endl;

    Sales_data item2("0-201-78345-X");
    print(cout, item2) << endl;

    Sales_data item3("0-201-78345-X", 3, 20.0);
    print(cout, item3) << endl;

    Sales_data item4(cin);
    print(cout, item4) << endl;

    return 0;
}