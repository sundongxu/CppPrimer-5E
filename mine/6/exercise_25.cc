#include <iostream>
#include <string>

using namespace std;

// int main(int argc, char *argv[]) 等价下一句
int main(int argc, char **argv)
{
    string s1(argv[1]);
    string s2(argv[2]);
    string rel = s1 + s2;
    cout << rel << endl;
    return 0;
}