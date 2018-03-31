#include <iostream>
#include <string>

using namespace std;

class Employee
{
    string _name;
    string _id;
    static int s_increment;

  public:
    Employee();
    Employee(const string &name);
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;

    const int id() const { return _id; }
};

Employee::Employee()
{
    _id = s_increment++;
}

Employee::Employee(const string &name)
{
    _id = s_increment++;
    _name = name;
}