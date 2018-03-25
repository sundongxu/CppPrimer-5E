#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

void word_counting()
{
    unordered_map<string, size_t> word_count;
    for (string word; cin >> word; ++word_count[word])
        ;
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
}

void wordTransformation()
{
    ifstream ifs_map("data/rules"), ifs_content("data/text");
    if (!ifs_map || !ifs_content)
        cerr << "can't find the documents." << endl;

    // buildMap
    unordered_map<string, string> trans_map;
    for (string key, value; ifs_map >> key && getline(ifs_map, value);)
    {
        if (value.size() > 1)
            trans_map[key] = value.substr(1).substr(0, value.find_last_not_of(" "));
    }

    // tranformation
    for (string text, word; getline(ifs_content, text); cout << endl)
        for (istringstream iss(text); iss >> word;)
        {
            auto map_it = trans_map.find(word);
            cout << (map_it == trans_map.cend() ? word : map_it->second) << " ";
        }
}

int main()
{
    // word_counting();
    wordTransformation();
    return 0;
}