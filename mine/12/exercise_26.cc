#include <iostream>
#include <string>
#include <memory>

using namespace std;

void input_reverse_output_string(int n)
{
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    auto q = p;
    while (cin >> s && q != p + n)
        alloc.construct(q++, s);
    while (q != p)
    {
        cout << *--q << " ";
        // 销毁元素，内存不释放，而是归还到allocator分配的未初始化内存，又可以在这部分内存上面重新构造新元素
        alloc.destroy(q);
    }
    cout << endl;
    alloc.deallocate(p, n); // 释放内存，当初allocate了多少，就要deallocate多少，不支持部分释放
}

int main()
{
    input_reverse_output_string(5);
    return 0;
}