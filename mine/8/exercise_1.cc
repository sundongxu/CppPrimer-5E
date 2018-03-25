#include <iostream>
#include <sstream>
#include <string>

using namespace std;

istream &func(istream &is)
{
    string s;
    // int s; // 输入的却是字符类型时，会将is的failbit置位

    // while (!is.eof())
    // {
    //     // 输入未开始就已经先进入循环体了
    //     cout << "loop running..." << endl;
    //     is >> s; //
    //     cout << s << endl;
    //     // is.setstate(ios_base::badbit);
    // }

    while (is >> s)
    {
        // 先输入再进入循环体
        // cout << "loop running..." << endl;
        cout << s << endl;
    }
    is.clear();
    return is;
}

int main()
{
    istringstream iss("hello world !!!"); // 练习8.9
    func(iss);

    // func(cin);  // 练习8.1
    return 0;
}