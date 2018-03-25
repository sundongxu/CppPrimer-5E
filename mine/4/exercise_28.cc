#include <iostream>

using namespace std;

int main()
{
    cout << "bool:\t\t" << sizeof(bool) << " bytes" << endl
         << endl; // 1

    cout << "char:\t\t" << sizeof(char) << " bytes" << endl;       // 1
    cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes" << endl;   // 4
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes" << endl; // 2
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes" << endl
         << endl; // 4

    cout << "short:\t\t" << sizeof(short) << " bytes" << endl; // 2
    cout << "int:\t\t" << sizeof(int) << " bytes" << endl;     // 4
    cout << "long:\t\t" << sizeof(long) << " bytes" << endl;   // 8
    cout << "long long:\t" << sizeof(long long) << " bytes" << endl
         << endl; // 8

    cout << "float:\t\t" << sizeof(float) << " bytes" << endl;   // 4
    cout << "double:\t\t" << sizeof(double) << " bytes" << endl; // 8
    cout << "long double:\t" << sizeof(long double) << " bytes" << endl
         << endl; // 16

    cout << "int8_t:\t\t" << sizeof(int8_t) << " bytes" << endl;     // 1
    cout << "uint8_t:\t\t" << sizeof(uint8_t) << " bytes" << endl;   // 1
    cout << "int16_t:\t\t" << sizeof(int16_t) << " bytes" << endl;   // 2
    cout << "uint16_t:\t\t" << sizeof(uint16_t) << " bytes" << endl; // 2
    cout << "int32_t:\t\t" << sizeof(int32_t) << " bytes" << endl;   // 4
    cout << "uint32_t:\t\t" << sizeof(uint32_t) << " bytes" << endl; // 4
    cout << "int64_t:\t\t" << sizeof(int64_t) << " bytes" << endl;   // 8
    cout << "uint64_t:\t\t" << sizeof(uint64_t) << " bytes" << endl; // 8

    return 0;
}