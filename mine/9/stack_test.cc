#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> intStack;
    for (size_t i = 0; i != 10; ++i)
        intStack.push(i);
    while (!intStack.empty())
    {
        int value = intStack.top();
        intStack.pop();
        cout << value << endl;
    }
    return 0;
}