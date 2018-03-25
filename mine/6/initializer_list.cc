#include <iostream>
#include <initializer_list>

using namespace std;

void err_msg(initializer_list<string> i1)
{
    for (auto beg = i1.begin(); beg != i1.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

int main()
{
    err_msg({"functionX", "Hello"});
    err_msg({"Sundongxu", "Honey", "darling"});
    return 0;
}