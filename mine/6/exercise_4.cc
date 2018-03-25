#include <iostream>

using namespace std;

int fact(int n)
{
    if (n == 1 | n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int f()
{
    cout << "Enter one number(0<n<12, 13 is a magic number...): ";
    int n = 0;
    cin >> n;
    return fact(n);
}

int main()
{
    int rel = f();
    cout << rel << endl;
    return 0;
}