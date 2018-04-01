#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class BoundTest
{
  public:
    BoundTest(size_t l = 0, size_t u = 0) : lower(l), upper(u) {}
    bool operator()(const string &s)
    {
        return lower <= s.length() && s.length() <= upper;
    }

  private:
    size_t lower;
    size_t upper;
};

int main()
{
    ifstream fin("data/storyDataFile");

    size_t quantity3 = 0, quantity5 = 0;
    BoundTest test3(1, 3);
    BoundTest test5(1, 5);
    string word;
    while (fin >> word)
    {
        if (test3(word))
            ++quantity3;
        if (test5(word))
            ++quantity5;
    }

    cout << quantity3 << ", " << quantity5 << endl;
}