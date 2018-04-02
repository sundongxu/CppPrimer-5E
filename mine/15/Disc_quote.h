#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "Quote.h"
#include <string>

class Disc_quote : public Quote
{
  public:
    Disc_quote() = default;
    Disc_quote(string const &b, double p, size_t q, double d) : Quote(b, p), quantity(q), discount(d) {}
    virtual double net_price(size_t) const = 0; // 纯虚函数，包含纯虚函数的类为抽象基类，不允许定义抽象基类的对象

  protected:
    size_t quantity = 0;
    double discount = 0.0;
};

#endif // DISC_QUOTE_H