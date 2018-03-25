#include <iostream>
#include <string>

using namespace std;

// string func(string &name, const string &prefix, const string &suffix)
// {
//     string ret = name;
//     ret.insert(ret.begin(), prefix.begin(), prefix.end());
//     ret.append(suffix);

//     return ret;
// }

string func(string &name, const string &prefix, const string &suffix)
{
    string ret = name;
    // 只使用insert
    ret.insert(0, prefix);
    ret.insert(ret.size(), suffix);
    return ret;
}

int main()
{
    string prefix("Mr."), suffix(" Jr."), name("Nance");
    string ret = func(name, prefix, suffix);
    cout << ret << endl;
    return 0;
}