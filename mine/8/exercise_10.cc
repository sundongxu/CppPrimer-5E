#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream ifs("data/e10");
    if (!ifs)
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    string line;
    vector<string> v;
    while (getline(ifs, line)) // 以换行为分隔符
        v.push_back(line);

    for (string &l : v)
    {
        istringstream iss(l);
        while (iss >> line) // 以空格为分隔符
            cout << line << endl;
    }

    return 0;
}