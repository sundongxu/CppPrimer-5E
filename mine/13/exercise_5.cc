#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
public:
  HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
  HasPtr(const HasPtr &hasPtr) : ps(new string(*hasPtr.ps)), i(hasPtr.i) {} // 拷贝构造

  HasPtr &operator=(const HasPtr &hasPtr) // 拷贝赋值
  {
    // 有指针成员的拷贝赋值特别小心，对于指针成员的复制步骤如下：
    // （1）先申请一片新内存空间，用参数对象指针成员初始化
    // （2）delete掉原有指针成员指向内存空间，即释放旧空间
    // （3）令指针成员指向（1）中新申请并已经初始化好的新内存空间
    // 以上算深复制嘛？？？
    string *new_ps = new string(*hasPtr.ps); // 新开辟一片内存空间，并用参数对象指针成员初始化
    delete ps;                               // 先释放原来的内存空间
    ps = new_ps;                             // 指针成员指向新的内存空间
    i = hasPtr.i;                            // 内置成员直接赋值即可
    return *this;
  }

  ~HasPtr()
  {
    delete ps;
  }

private:
  string *ps;
  int i;
};
