#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    multimap<string, string> authors{
        {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"}, {"wang", "FTP"}, {"pezy", "CP5"}, {"wang", "CPP-Concurrency"}, {"pezy", "CP5"}};
    // want to delete an element that author is [pezy], work is [CP5].
    string author = "pezy";
    string work = "CP5";

    for (auto found = authors.find(author);
         found != authors.end() && found->first == author;)
    {
        if (found->second == work)
            found = authors.erase(found); // 指向被删除元素之后一个位置的迭代器
        else
            ++found;
    }

    for (const auto &author : authors)
        cout << author.first << " " << author.second << endl;
}