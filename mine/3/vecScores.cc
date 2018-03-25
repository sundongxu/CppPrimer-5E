#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> scores(11, 0); // 11个分数段，全都初始化为0
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
            ++scores[grade / 10];
    }
    return 0;
}