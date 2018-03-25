#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int i, j;
    std::cin >> i >> j;
    if (j == 0)
        throw runtime_error("divisor cannot be zero!");
    cout << static_cast<double>(i) / j << endl;
    return 0;
}