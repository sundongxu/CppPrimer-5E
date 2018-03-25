#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream os("data/test", ofstream::out | ofstream::app);
    os.close();
    ifstream is("data/test");
    string s;
    is >> s;
    cout << s << endl;
    return 0;
}