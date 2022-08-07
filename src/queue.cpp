/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 09:13:48
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#include <iostream>
#include "inc/queue.h"

using dataX = int;

using namespace std;

int main()
{
    QueueClass<dataX> *queue = new QueueClass<dataX>(4);
    {
        QueueClass<dataX> copyQueue = *queue;
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
            dataX x;
            cin >> x;
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                continue;
            }
            queue->enqueue(x);
        }
        else if (operate == "em") // 入队n个元素
        {
            size_t n;
            cin >> n;
            if (cin.fail())
            {
                cin.clear();
                continue;
            }
            float x;
            for (size_t i = 0; i < n; i++)
            {
                cin >> x;
                if (cin.fail())
                {
                    cin.clear();
                    break;
                }
                queue->enqueue(x);
            }
        }
        else if (operate == "d") // 出队一个元素，并把这个元素显示出来
        {
            dataX x;
            queue->dequeue(x);
            cout << x << endl;
        }
        else if (operate == "dm") // 出队n个元素，并显示最后一个出队的元素
        {
            size_t n;
            cin >> n;
            if (cin.fail())
            {
                cin.clear();
                continue;
            }
            dataX *x = new dataX[n];
            queue->dequeue(x, n);
            for (size_t i = 0; i < n; i++)
                cout << x[i] << " ";
            cout << endl;
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