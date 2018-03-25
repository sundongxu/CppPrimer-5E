#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

//! Exercise 11.4
void word_count_pro(std::map<std::string, int> &m)
{
    std::string word;
    while (std::cin >> word)
    {
        for (auto &ch : word)
            ch = tolower(ch);
        word.erase(std::remove_if(word.begin(), word.end(), ispunct),
                   word.end()); // 删掉全部标点符号
        ++m[word];
    }
    for (const auto &e : m)
        std::cout << e.first << " : " << e.second << "\n";
}

int main()
{
    std::map<std::string, int> m;
    word_count_pro(m);

    return 0;
}