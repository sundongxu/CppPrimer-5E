#include "Bulk_quote.h"
#include <vector>
#include <numeric>

int main()
{
    vector<Quote> vec;
    Bulk_quote bulk0("0-201-82470-1", 50, 5, 0.2);
    Bulk_quote bulk1("0-201-82470-1", 50, 3, 0.5);

    // total price should be:
    cout << "bulk_quote's total: " << bulk0.net_price(5) + bulk1.net_price(5) << endl;

    vec.push_back(bulk0);
    vec.push_back(bulk1);

    double total = accumulate(vec.cbegin(), vec.cend(), 0.0, [](double ret, const Quote &obj) {
        return ret += obj.net_price(5);
    });

    // total price in the vector.
    cout << "total in the vector: " << total << endl;
    return 0;
}