#include <iostream>
#include <vector>
#include "Sales_data.h"
#include <fstream>
#include <algorithm>

using namespace std;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

int main()
{
    vector<Sales_data> vec;
    Sales_data sd;
    ifstream ifs("data/book_sales");
    while (read(ifs, sd))
        vec.push_back(sd);

    cout << "before sorting:" << endl;
    for (const auto &s : vec)
    {
        print(cout, s);
        cout << endl;
    }
    cout << endl;

    stable_sort(vec.begin(), vec.end(), compareIsbn);

    cout << "after sorting" << endl;
    for (const auto &s : vec)
    {
        print(cout, s);
        cout << endl;
    }

    return 0;
}