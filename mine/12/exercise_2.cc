#include <iostream>
#include "StrBlob.h"

int main()
{
    const StrBlob csb{"Hello", "World", "Pezy"};
    StrBlob sb{"Hello", "World", "SunDongxu"};

    cout << csb.front() << " " << csb.back() << endl;
    cout << sb.front() << " " << sb.back() << endl;
    return 0;
}