#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GetInput
{
  public:
    GetInput(istream &i = cin) : is(cin) {}
    string operator()() const
    {
        string str;
        getline(is, str);
        return is ? str : string();
    }

  private:
    istream &is;
};

int main()
{
    GetInput getInput;
    vector<string> vec;
    for (string tmp; !(tmp = getInput()).empty();)
        vec.push_back(tmp);
    for (const auto &str : vec)
        cout << str << " ";
    cout << endl;
}