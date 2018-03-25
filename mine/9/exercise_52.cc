#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    auto &expr = "(x + (y + z)) * a";
    auto repl = '#';
    auto seen = 0;

    stack<char> stk;

    for (auto c : expr) // 循环遍历表达式
    {
        stk.push(c);
        if (c == '(')
            ++seen; // 表示栈中有未匹配的左括号需要处理
        if (seen && c == ')')
        { // pop elements down to the stack
            while (stk.top() != '(')
                stk.pop();
            stk.pop();      // 弹出左括号
            stk.push(repl); // 用repl(#)代替括号表达式的求值结果入栈
            --seen;         // 关闭
        }
    }

    // Test
    string output;
    for (; !stk.empty(); stk.pop())
        output.insert(output.begin(), stk.top());
    cout << output << endl; // "This is # and # over"
}