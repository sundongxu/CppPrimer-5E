#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3;

    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
    cout << "lst2: ";
    for (int i : lst2)
        cout << i << " ";

    cout << endl;

    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));
    cout << "lst3: ";
    for (int i : lst3)
        cout << i << " ";
    cout << endl;
    return 0;
}