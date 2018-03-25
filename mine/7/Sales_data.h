#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using namespace std;

// own Sales_data
class Sales_data
{
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend ostream &print(ostream &, const Sales_data &);
  friend istream &read(istream &, Sales_data &);

public:
  // 受委托的构造函数
  Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p)
  {
    cout << "Sales_data(const std::string&, unsigned, double)"
         << std::endl;
  }

  // 委托构造函数
  Sales_data() : Sales_data("", 0, 0)
  {
    std::cout << "Sales_data()" << std::endl;
  }
  Sales_data(const string &s) : Sales_data(s, 0, 0)
  {
    std::cout << "Sales_data(const std::string&)" << std::endl;
  }
  Sales_data(istream &);

  string isbn() const
  {
    return bookNo;
  };
  Sales_data &combine(const Sales_data &);

private:
  double avg_price() const;

  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

Sales_data::Sales_data(istream &is) : Sales_data()
{
  std::cout << "Sales_data(istream &is)" << std::endl;
  read(cin, *this);
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this; // 返回调用对象自身
}

inline double Sales_data::avg_price() const
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

#endif