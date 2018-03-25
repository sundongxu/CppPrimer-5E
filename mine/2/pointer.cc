#include <iostream>
#include <cstdlib>

int main()
{
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    if (p1 == nullptr)
        std::cout << "p1: " << p1 << std::endl;
    if (p2 == 0)
        std::cout << "p2: " << p2 << std::endl;
    if (p3 == NULL)
        std::cout << "p3: " << p3 << std::endl;

    return 0;
}