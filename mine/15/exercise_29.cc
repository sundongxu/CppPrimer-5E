#include "Bulk_quote.h"
#include <vector>
#include <numeric>
#include <memory>

using namespace std;

int main()
{
    vector<shared_ptr<Quote>> vec;
    shared_ptr<Bulk_quote> spBulk0 = make_shared<Bulk_quote>("0-201-82470-1", 50, 5, 0.2);
    shared_ptr<Bulk_quote> spBulk1 = make_shared<Bulk_quote>("0-201-82470-1", 50, 3, 0.5);

    // total price should be:
    cout << "bulk_quote's total: " << spBulk0->net_price(5) + spBulk1->net_price(5) << endl;

    vec.push_back(spBulk0);
    vec.push_back(spBulk1);

    double total = accumulate(vec.cbegin(), vec.cend(), 0.0, [](double ret, shared_ptr<Quote> sp) {
        return ret += sp->net_price(5);
    });

    // total price in the vector.
    cout << "total in the vector: " << total << endl;
    return 0;
}