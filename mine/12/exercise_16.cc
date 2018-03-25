#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<string> p1(new string("pezy"));
    // unique_ptr<string> p2(p1); // copy
    // my error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]’
    // Error: Call to implicitly-deleted copy constructor of
    // 'unique_ptr<string>'

    // unique_ptr<string> p3 = p1; // assign
    // my error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = std::__cxx11::basic_string<char>; _Dp = std::default_delete<std::__cxx11::basic_string<char> >]’
    // Error: Call to implicitly-deleted copy constructor of'unique_ptr<string>'

    cout << *p1 << endl;
    p1.reset(nullptr);
}