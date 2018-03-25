#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <typename Sequence>
void print(Sequence const &seq)
{
    for (const auto &i : seq)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1, lst2, lst3;

    copy(vec.cbegin(), vec.cend(), front_inserter(lst1));
    print(lst1);

    copy(vec.cbegin(), vec.cend(), back_inserter(lst2));
    print(lst2);

    copy(vec.cbegin(), vec.cend(), inserter(lst3, lst3.begin()));
    print(lst3);

    return 0;
}