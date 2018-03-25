#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

struct Person
{
    friend istream &read(istream &is, Person &p); // 友元函数可以直接访问类的私有成员
    friend ostream &print(ostream &os, const Person &p);

  private:
    string name;
    string addr;

  public:
    Person() = default;
    Person(const string &sname, const string &saddr) : name(sname), addr(saddr) {}
    Person(istream &is) { read(is, *this); }

    const string &getName() const { return name; }
    const string &getAddr() const { return addr; }
};

istream &read(istream &is, Person &p)
{
    is >> p.name >> p.addr;
    return is;
}

ostream &print(ostream &os, const Person &p)
{
    os << p.name << "" << p.addr;
    return os;
}

#endif