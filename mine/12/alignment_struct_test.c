#include <stdio.h>

// 结构体自身对齐值为其成员中的最大对齐值，即int的对齐值4
// 而8 % 4 = 0，无需补足字节数，最后该结构体所占内存地址为0~7，即size为8字节
struct A
{
    int a;   // 0~3
    char b;  // 4
    short c; // 6~7
};           // 0~7共8个字节，结果也就是8字节

// 结构体自身对齐值为其成员中的最大对齐值，即int的对齐值4
// 故(10+2) % 4 = 0，即10~11位置补足，最后该结构体所占内存地址为0~11，即size为12字节
struct B
{
    char a;  // 0
    int b;   // 4~7
    short c; //8~9
};           // 0~9共10个字节，但是结果为12字节!

// 结构体有效对齐值取自身对齐值与变量最大对齐值两者中较小的，min(2,4) = 2
// 而8 % 2 = 0，无需补足字节数，最后该结构体所占内存地址为0~7，即8字节
#pragma pack(2) /*指定结构体按2字节对齐*/
struct C
{
    // 变量有效对齐值取自身对齐值与指定对齐值两者中较小的
    char a;    // min(1,2) = 1，内存地址0
    int b;     // min(4,2) = 2，内存地址2~5
    short c;   // min(2,2) = 2，内存地址6~7
};             // 0~7共8字节
#pragma pack() /*取消指定对齐，恢复缺省对齐*/

// 结构体有效对齐值取自身对齐值与变量最大对齐值两者中较小的，min(1,4) = 1
// 而7 % 1 = 0，无需补足字节数，最后该结构体所占内存地址为0~6，即7字节
#pragma pack(1) /*指定结构体按1字节对齐*/
struct D
{
    // 变量有效对齐值取自身对齐值与指定对齐值两者中较小的
    char a;    // min(1,1) = 1，内存地址0
    int b;     // min(4,1) = 1，内存地址1~4
    short c;   // min(2,1) = 1，内存地址5~6
};             // 0~6共7字节
#pragma pack() /*取消指定对齐，恢复缺省对齐*/

int main()
{
    struct A a;
    printf("A's size: %ld bytes\n", sizeof(a)); // 8
    struct B b;
    printf("B's size: %ld bytes\n", sizeof(b)); // 12
    struct C c;
    printf("C's size: %ld bytes\n", sizeof(c)); // 8
    struct D d;
    printf("D's size: %ld bytes\n", sizeof(d)); // 7
    return 0;
}