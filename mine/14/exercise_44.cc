#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

int add(int i, int j)
{
    return i + j;
}

auto mod = [](int i, int j) { return i % j; };

struct divide
{
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};

map<string, function<int(int, int)>> binops =
    {
        {"+", add},
        {"-", minus<int>()},
        {"/", divide()},
        {"*", [](int i, int j) { return i * j; }},
        {"%", mod},
};

int main()
{
    while (1)
    {
        cout << "\nplease enter: num operator num: \n";
        int n1, n2;
        string s;
        cin >> n1 >> s >> n2;
        cout << binops[s](n1, n2);
    }
    return 0;
}