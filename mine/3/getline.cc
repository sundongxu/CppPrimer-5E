#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) // getline读取一整行，换行符执行循环
        cout << line << endl;
    return 0;
}