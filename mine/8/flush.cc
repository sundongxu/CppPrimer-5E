#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    // cout << "hi" << endl;  // 刷新cout并在末尾追加一个换行符'\n'
    // cout << "hi" << ends;  // 刷新cout并在末尾追加一个空字符'\0'
    // cout << "hi" << flush; // 刷新cout并不会在末尾追加任何额外字符

    // cout << unitbuf;   // 设置此后cout的输出操作之后立即刷新
    // cout << nounitbuf; // 还原上一语句，默认不立即刷新
    // cout << "hi";      // 不使用任何操作符，并在之后挂起进程几秒，发现cout并没有立即刷新
    // usleep(5000000);

    int i = 5;
    cout << i;
    cin >> i;
    cout << i;
    usleep(5 * 1000 * 1000); // 1000*1000 us -> 1000 ms -> s
    return 0;
}