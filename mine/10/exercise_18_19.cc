// 用 partition 代替 find_if

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// 返回复数形式
string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

// 给words去重
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// 打印words中长度不小于sz的元素值
void biggies_partition(vector<string> &words, vector<string>::size_type sz)
{
    // 将words去重，并按字典序排序
    elimDups(words);
    // 将words按长度排序，长度相同的保持上一步排序好的字典序，后面的lambda表达式相当于isShorter的作用
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    // 获取指向第一个长度不小于sz的元素迭代器
    // auto pivot = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });

    auto pivot = partition(words.begin(), words.end(), [sz](const string &s) { return s.size() < sz; });

    // 计算满足size >= sz 的元素个数
    auto count = pivot - words.end();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    // 打印从pivot开始直到words末尾的word
    for_each(pivot, words.end(), [](const string &s) { cout << s << endl; });
    cout << endl;
}

// 打印words中长度不小于sz的元素值
void biggies_stable_partition(vector<string> &words, vector<string>::size_type sz)
{
    // 将words去重，并按字典序排序
    elimDups(words);
    // 将words按长度排序，长度相同的保持上一步排序好的字典序，后面的lambda表达式相当于isShorter的作用
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) { return a.size() < b.size(); });
    // 获取指向第一个长度不小于sz的元素迭代器
    // auto pivot = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });

    auto pivot = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() < sz; });

    // 计算满足size >= sz 的元素个数
    auto count = pivot - words.end();
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << endl;
    // 打印从pivot开始直到words末尾的word
    for_each(pivot, words.end(), [](const string &s) { cout << s << endl; });
    cout << endl;
}

int main()
{
    vector<string> vec;
    ifstream ifs("data/elimDup");
    string s;
    while (ifs >> s)
        vec.push_back(s);
    // biggies_partition(vec, 4);
    biggies_stable_partition(vec, 4);
    return 0;
}