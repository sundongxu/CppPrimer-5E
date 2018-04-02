#include "Bulk_quote.h"

int main()
{
    Quote quote("0-201-78345-X", 23.8);
    print_total(cout, quote, 3);

    Bulk_quote bquote("0-201-78345-X", 23.8, 3, 0.5);
    print_total(cout, bquote, 4);
    return 0;
}