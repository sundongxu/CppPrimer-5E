#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "Disc_quote.h"
#include <string>

class Bulk_quote : public Disc_quote
{
  public:
    Bulk_quote() = default;
    Bulk_quote(string const &book, double p, size_t qty, double disc) : Disc_quote(book, p, qty, disc) {}

    Bulk_quote *clone() const & { return new Bulk_quote(*this); };
    Bulk_quote *clone() && { return new Bulk_quote(std::move(*this)); }

    virtual double net_price(size_t cnt) const override
    {
        if (cnt >= quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
};

#endif // BULK_QUOTE_H