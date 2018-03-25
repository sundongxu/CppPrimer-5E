#include "Screen.h"

inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}

using namespace std;

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.display(cout);
    cout << "\n";
    myScreen.move(1, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}