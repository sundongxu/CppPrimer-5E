#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

using namespace std;

class Sales_data
{
    friend istream &operator>>(istream &, Sales_data &);                 // input
    friend ostream &operator<<(ostream &, const Sales_data &);           // output
    friend Sales_data operator+(const Sales_data &, const Sales_data &); // addition

  public:
    Sales_data(const string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data() : Sales_data("", 0, 0.0f) {}
    Sales_data(const string &s) : Sales_data(s, 0, 0.0f) {}
    Sales_data(istream &is);

    Sales_data &operator+=(const Sales_data &); // compound-assignment
    string isbn() const { return bookNo; }

  private:
    inline double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream &operator>>(istream &, Sales_data &);
ostream &operator<<(ostream &, const Sales_data &);
Sales_data operator+(const Sales_data &, const Sales_data &);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue / units_sold : 0;
}

#endif