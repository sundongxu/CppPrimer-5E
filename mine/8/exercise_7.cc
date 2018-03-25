#include <iostream>
#include <fstream>

#include "../7/Sales_data.h"

int main(int argc, char **argv)
{
    ifstream input(argv[1]); // use "../data/book.txt"
    ofstream output(argv[2], ofstream::app);

    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
}