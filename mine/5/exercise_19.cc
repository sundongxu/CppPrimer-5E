#include <iostream>
#include <string>

using namespace std;

int main()
{
    string rsp;
    do
    {
        cout << "Enter two strings: ";
        string str1, str2;
        cin >> str1 >> str2;
        cout << ((str1.size() <= str2.size()) ? str1 : str2) << " is less than the other."
             << "\n\n"
             << "More? Enter y for yes or n for no:";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] == 'y');
    return 0;
}