#include <vector>
#include <iostream>
#include <algorithm>

using std::sort;
using std::vector;

class Foo
{
  public:
    Foo sorted() &&;
    Foo sorted() const &;

  private:
    vector<int> data;
};

Foo Foo::sorted() &&
{
    sort(data.begin(), data.end());
    std::cout << "&&" << std::endl; // debug
    return *this;
}

Foo Foo::sorted() const &
{
    //    Foo ret(*this);
    //    sort(ret.data.begin(), ret.data.end());
    //    return ret;

    std::cout << "const &" << std::endl; // debug

    //    Foo ret(*this);
    //    ret.sorted();     // Exercise 13.56
    //    return ret;

    return Foo(*this).sorted(); // Exercise 13.57
}

int main()
{
    Foo().sorted(); // call "&&"
    Foo f;          // f is a lvalue
    f.sorted();     // first call "const &" and then call "&&" inside the "const & " version
}