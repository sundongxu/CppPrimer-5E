#include "StrVec.h"

allocator<string> StrVec::alloc;

int main()
{
    StrVec vec;
    string s = "some string of another";
    vec.push_back(s);      // copy construct
    vec.push_back("done"); // move construct
    return 0;
}