#include <fstream>
#include <iostream>
#include "exercise_19.h"

using namespace std;

int main()
{
    ifstream ifs("data/text");
    StrBlob blob;
    for (string str; getline(ifs, str);)
        blob.push_back(str);
    for (StrBlobPtr pbeg(blob.begin()), pend(blob.end()); pbeg != pend;
         pbeg.incr())
        cout << pbeg.deref() << endl;
}