
#ifndef EXERCISE_5_H
#define EXERCISE_5_H

#include <iostream>
#include <string>

using namespace std;

class Book
{
  // 一般输入输出运算符都会定义成非成员，但要是友元
  // 第一个参数一定是流对象
  friend istream &operator>>(istream &, Book &);
  friend ostream &operator<<(ostream &, const Book &);
  friend bool operator==(const Book &, const Book &);
  friend bool operator!=(const Book &, const Book &);

public:
  Book() = default;
  Book(unsigned no, string name, string author, string pubdate)
      : no_(no), name_(name), author_(author), pubdate_(pubdate)
  {
  }
  Book(istream &in) { in >> *this; }

private:
  unsigned no_;
  string name_;
  string author_;
  string pubdate_;
};

istream &operator>>(istream &, Book &);
ostream &operator<<(ostream &, const Book &);
bool operator==(const Book &, const Book &);
bool operator!=(const Book &, const Book &);

#endif // EXERCISE_5_H