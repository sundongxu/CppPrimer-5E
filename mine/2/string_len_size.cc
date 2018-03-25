#include <iostream>
#include <cstring>
int main()
{
    // 编译器会给每个字符串结尾处添加结束符 '\0'
    std::cout << "real length: " << sizeof("aaa") << std::endl;
    std::cout << "real size: " << strlen("aaa") << std::endl;
}