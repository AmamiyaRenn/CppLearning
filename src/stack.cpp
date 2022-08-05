/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 08:28:20
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#include <iostream>
#include <string>
#include "inc/stack.h"

using namespace std;

int main()
{
    StackClass *stack = new StackClass(4);
    while (true)
    {
        string operate;
        getline(cin, operate);
        if (cin.fail())
            cin.clear();
        cin.sync();

        if (operate == "ps") // 入栈
        {
            float x;
            cin >> x;
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                continue;
            }
            stack->push(x);
        }
        else if (operate == "pp") // 出栈
        {
            float x;
            stack->pop(x);
            cout << x << endl;
        }
        else if (operate == "t") // 显示栈顶值
        {
            if (!stack->isEmpty())
                cout << stack->top() << endl;
        }
        else if (operate == "s") // 展示栈内元素
            stack->show();
        else if (operate == "q") // 退出
            break;
    }
    return 0;
}
