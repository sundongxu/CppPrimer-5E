#include "exercise_5.h"

istream &operator>>(istream &in, Book &book)
{
    in >> book.no_ >> book.name_ >> book.author_ >> book.pubdate_;
    if (!in)
        book = Book();
    return in;
}

ostream &operator<<(ostream &out, const Book &book)
{
    out << book.no_ << " " << book.name_ << " " << book.author_ << " "
        << book.pubdate_;
    return out;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.no_ == rhs.no_;
}

bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}