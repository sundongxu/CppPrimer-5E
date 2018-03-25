#include <iostream>
#include "exercise_51.h"

int main()
{
    string s1("January 1, 1990"), s2("13/12/1990"), s3("Feb 23 1990");
    Date d1(s1), d2(s2), d3(s3);
    std::cout << d1.day << " " << d1.month << " " << d1.year << endl;
    std::cout << d2.day << " " << d2.month << " " << d2.year << endl;
    std::cout << d3.day << " " << d3.month << " " << d3.year << endl;

    return 0;
}