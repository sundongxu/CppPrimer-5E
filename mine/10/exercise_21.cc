#include <iostream>

using namespace std;

int main()
{
    int i = 5;
    auto subUntilZero = [&i]() { 
        if (i == 0) 
        return true; 
        else {
            --i;
            return false;
        }; };

    while (!subUntilZero())
        cout << i << endl;

    return 0;
}