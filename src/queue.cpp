/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 09:13:48
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#include <iostream>
#include "inc/queue.h"

using namespace std;

int main()
{
    QueueClass<int> *queue = new QueueClass<int>(4);
    {
        QueueClass<int> copyQueue = *queue;
    }
    while (true)
    {
        string operate;
        getline(cin, operate);
        if (cin.fail())
            cin.clear();
        cin.sync();

        if (operate == "e") // 入队一个元素
        {
            int x;
            cin >> x;
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                continue;
            }
            queue->enqueue(x);
        }
        else if (operate == "d") // 出队一个元素，并把这个元素显示出来
        {
            int x;
            queue->dequeue(x);
            cout << x << endl;
        }
        else if (operate == "f") // 显示队首值
        {
            if (!queue->isEmpty())
                cout << queue->getFront() << endl;
        }
        else if (operate == "s")
            queue->show();
        else if (operate == "q")
            break;
    }
    return 0;
}