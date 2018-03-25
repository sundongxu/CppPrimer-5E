#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

string format(const string &s) { return s; }

bool valid(const string &s)
{
    // we'll see how to validate phone numbers
    // in chapter 17, for now just return true
    return true;
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    ifstream is("data/sstream");
    ofstream os("data/sstream-valid-content");
    istringstream record;
    while (getline(is, line))
    {
        PersonInfo info;
        // istringstream record(line);
        record.clear();
        record.str(line); // 将record这个istringstream字符串流对象与line字符串的一个拷贝绑定！
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    // for (auto &p : people)
    // // 注意除了简单内置类型int double等等这些类型变量以外，其它都是用引用类型作为当前元素类型
    // {
    //     cout << p.name << ":";
    //     for (auto &phone : p.phones)
    //         cout << phone << " ";
    //     cout << endl;
    // }

    for (const auto &p : people)
    {
        ostringstream formatted, badNums;
        for (const auto &phone : p.phones)
        {
            if (!valid(phone))
                badNums << phone << " ";
            else
                formatted << format(phone) << " ";
        }
        if (badNums.str().empty())
            os << p.name << ":" << formatted.str() << endl;
        else
            cerr << "input error: " << p.name << " invalid number(s) " << badNums.str() << endl;
    }

    return 0;
}