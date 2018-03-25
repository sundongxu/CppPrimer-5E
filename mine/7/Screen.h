#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

using namespace std;

class Screen
{
    friend class Window_mgr;
    // friend void Window_mgr::clear(ScreenIndex);

  public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r * width + c]; }

    Screen &move(pos r, pos c);
    Screen &set(char);
    Screen &set(pos, pos, char);

    Screen &display(ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(ostream &os) const
    {
        do_display(os);
        return *this;
    }

  private:
    void do_display(ostream &os) const
    {
        os << contents;
    }
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

#endif