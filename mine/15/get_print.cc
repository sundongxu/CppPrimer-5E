#include "Query.h"
#include "TextQuery.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

TextQuery get_file(int argc, char **argv)
{
    ifstream infile;
    if (argc == 2)
        infile.open(argv[1]);
    if (!infile)
    {
        throw runtime_error("No input file!");
    }

    return TextQuery(infile);
}

bool get_word(string &s1)
{
    cout << "enter a word to search for, or q to quit: ";
    cin >> s1;
    if (!cin || s1 == "q")
        return false;
    else
        return true;
}

bool get_words(string &s1, string &s2)
{

    cout << "enter two words to search for, or q to quit: ";
    cin >> s1;

    if (!cin || s1 == "q")
        return false;
    cin >> s2;
    return true;
}
