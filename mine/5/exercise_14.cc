#include <iostream>

using namespace std;

int main()
{
    string now = "", pre = now, result = "";
    int count = 0, maxCount = 0;
    while (cin >> now)
    {
        if (now == pre)
            count++;
        else
        {
            if (count > maxCount)
            {
                maxCount = count;
                result = pre;
            }
            count = 1;
        }
        pre = now;
    }

    if (maxCount > 1)
        cout << result << ": " << maxCount << " times.";
    else
        cout << "no such words.";

    return 0;
}