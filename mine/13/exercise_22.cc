#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);
    friend bool operator<(const HasPtr &lhs, const HasPtr &rhs);

  public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &hasPtr) : ps(new string(*hasPtr.ps)), i(hasPtr.i) {} // 拷贝构造
    HasPtr(HasPtr &&hasPtr) noexcept : ps(hasPtr.ps), i(hasPtr.i)             // 移动构造
    {
        hasPtr.ps = 0;
        cout << "call move contructor" << endl;
    }

    HasPtr &operator=(HasPtr hasPtr) // 用了swap以后，这里就不能传引用了
    {
        cout << "copy assignment" << endl;
        this->swap(hasPtr);
        return *this;
    }

    // HasPtr &operator=(HasPtr &&rhs) noexcept
    // {
    //     if (this != &rhs)
    //     {
    //         delete ps;
    //         ps = rhs.ps;
    //         i = rhs.i;
    //         rhs.ps = nullptr;
    //         std::cout << "call move assignment" << std::endl;
    //     }
    //     return *this;
    // }
    ~HasPtr()
    {
        delete ps;
    }

    void show() const
    {
        cout << *ps << endl;
    }

    void swap(HasPtr &rhs)
    {
        using std::swap;
        swap(ps, rhs.ps);
        swap(i, rhs.i);
        cout << "call swap(HasPtr& rhs)" << endl;
    }

  private:
    string *ps;
    int i;
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    lhs.swap(rhs);
}

bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

int main()
{
    vector<HasPtr> v;
    v.push_back(HasPtr("c"));
    v.push_back(HasPtr("b"));
    v.push_back(HasPtr("a"));
    cout << "before sort:" << endl;
    for (auto hp : v)
        hp.show();
    sort(v.begin(), v.end());
    cout << "after sort:" << endl;
    for (auto hp : v)
        hp.show();
    return 0;
}
