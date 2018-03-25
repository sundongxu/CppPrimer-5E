#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 3, 4, 5, 7, 9, 10, 13};
    int sought;
    cout << "input the number you want to search:\n"
         << endl;
    cin >> sought;
    auto beg = v.cbegin(), end = v.cend();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != sought)
    {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg) / 2;
    }
    if (mid != end)
        cout << "Found " << *mid << endl;
    else
        cout << "Not Found!";
    return 0;
}