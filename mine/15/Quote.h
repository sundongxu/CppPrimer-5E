#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

using namespace std;

class Quote
{
public:
  Quote() = default;
  Quote(string const &b, double p) : bookNo(b), price(p) {}

  virtual Quote *clone() const & { return new Quote(*this); };
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

  string isbn() const { return bookNo; }
  virtual double net_price(size_t n) const { return n * price; }
  virtual void debug() const { cout << "data members: \n"
                                    << "\tbookNo: " << bookNo << "\tprice: " << price << endl; }
  virtual ~Quote() = default;

private:
  string bookNo;

protected:
  double price = 0.0;
};

double print_total(ostream &os, Quote const &item, size_t n)
{
  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
  return ret;
}

#endif // QUOTE_H