#include <string>

using namespace std;

class HasPtr
{
  public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)){};
    HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use)
    {
        ++*use; // 递增计数器值
    }
    HasPtr &operator=(const HasPtr &p);
    ~HasPtr();

  private:
    string *ps;
    int i;
    size_t *use; // 用来记录有多少个对象共享*ps的成员
};

HasPtr &HasPtr::operator=(const HasPtr &p)
{
    ++*p.use; // 递增右侧对象的计数器值

    if (--*use == 0) // 递减左侧对象计数器值
    {
        // 递减至0则释放该对象ps指向内存和计数器内存
        delete ps;
        delete use;
    }
    ps = p.ps;
    i = p.i;
    use = p.use;
    return *this;
}

HasPtr::~HasPtr()
{
    if (--*use == 0)
    {
        // 引用计数为0，释放ps指向内存，也释放计数器use内存
        delete ps;
        delete use;
    }
}