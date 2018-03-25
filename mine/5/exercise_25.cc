#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    int i, j;
    cout << "Enter two integers: ";
    while (cin >> i >> j)
    {
        try
        {
            if (j == 0)
                throw runtime_error("divisor cannot be zero!");
            cout << static_cast<double>(i) / j << endl;
            cout << "Enter two integers: ";
        }
        catch (runtime_error err)
        {
            cout << err.what();
            cout << "\nTry Again? Enter y or n:" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
            else if (c == 'y')
                cout << "Enter two integers: " << endl;
        }
    }

    return 0;
}