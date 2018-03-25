#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    std::multimap<string, string> families;
    for (string lastName, childName; std::cin >> childName >> lastName;
         families.emplace(lastName, childName))
        ;
    for (const auto &s : families)
        std::cout << s.second << " " << s.first << std::endl;
}