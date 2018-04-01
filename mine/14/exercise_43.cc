#include <iostream>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    auto data = {2, 3, 4, 5};
    int input;
    cin >> input;
    modulus<int> mod;
    // 下面的lambda表达式采用引用捕获input
    auto predicator = [&](int i) { return 0 == mod(input, i); };
    auto is_divisible = all_of(data.begin(), data.end(), predicator);
    cout << (is_divisible ? "Yes!" : "No!") << endl;

    return 0;
}