#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <iostream>
#include <set>

int main(int argc, char **argv)
{
    TextQuery file = get_file(argc, argv);

    do
    {
        string sought1, sought2;
        if (!get_words(sought1, sought2))
            break;

        Query andq = Query(sought1) & Query(sought2);
        cout << "\nExecuting query for: " << andq << endl;
        auto results = andq.eval(file);
        print(cout, results);

        results = Query(sought1).eval(file);
        cout << "\nExecuted query: " << Query(sought1) << endl;
        print(cout, results);

        results = Query(sought2).eval(file);
        cout << "\nExecuted query: " << Query(sought2) << endl;
        print(cout, results);
    } while (true);

    return 0;
}
