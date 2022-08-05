/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 14:51:54
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#include <iostream>
#include "inc/linklist.h"

using namespace std;

int main()
{
    LinklistClass *linklist = new LinklistClass;
    while (true)
    {
        string operate;
        getline(cin, operate);
        if (cin.fail())
            cin.clear();
        cin.sync();

        bool operateSuccessed = true;
        if (operate == "i") // 在指定位置插入一个元素
        {
            size_t i = 0;
            float x;
            cin >> i >> x;
            if (cin.fail())
            {
                cin.clear();
                cin.sync();
                continue;
            }
            operateSuccessed = linklist->insertNode(new LinklistNodeStruct(x), i);
        }
        else if (operate == "d") // 删除指定位置的一个元素
        {
            size_t i = 0;
            cin >> i;
            if (cin.fail())
            {
                cin.clear();
                continue;
            }
            operateSuccessed = linklist->deleteNode(i);
        }
        else if (operate == "n") // 显示链表内数据总数
            cout << linklist->getDataCounter() << endl;
        else if (operate == "s")
        {
            size_t i = 0;
            cin >> i;
            if (cin.fail())
            {
                cin.clear();
                continue;
            }
            switch (i)
            {
            case LinklistTraversalMethodFrontToEnd:
                operateSuccessed = linklist->show(LinklistTraversalMethodFrontToEnd);
                break;

            case LinklistTraversalMethodEndToFront:
                operateSuccessed = linklist->show(LinklistTraversalMethodEndToFront);
                break;
            }
        }
        else if (operate == "q")
            break;
        else if (operate != "")
            cerr << "Unknown operation: " << operate << endl;

        if (!operateSuccessed)
            cerr << "Operation Failed" << endl;
    }
    return 0;
}
