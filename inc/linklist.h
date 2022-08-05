/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 14:52:03
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <iostream>

enum LinklistTraversalMethodEnum
{
    LinklistTraversalMethodFrontToEnd, // 从前向后遍历
    LinklistTraversalMethodEndToFront, // 从后向前遍历
};

// 双向链表结点类
struct LinklistNodeStruct
{
    float data;               // 数据
    LinklistNodeStruct *next; // 下一个结点的位置
    LinklistNodeStruct *prev; // 上一个结点的位置
    LinklistNodeStruct(float data) : data(data), next(nullptr), prev(nullptr){};
};

// 双向链表类
class LinklistClass
{
public:
    LinklistClass() : head(nullptr), dataCounter(0){};
    ~LinklistClass()
    {
        if (head == nullptr)
            return;
        LinklistNodeStruct *currentNode = head->next; // 定义当前结点指针(从头开始遍历)
        head->next = nullptr;
        LinklistNodeStruct *deleteNode;
        while (currentNode != nullptr)
        {
            deleteNode = currentNode;
            currentNode = currentNode->next;
            delete deleteNode;
        }
    }
    // 表空
    bool isEmpty() const { return dataCounter <= 0; }
    bool insertNode(LinklistNodeStruct *NewNode, size_t index);
    bool deleteNode(size_t index);
    size_t getDataCounter() const { return dataCounter; }
    bool show(LinklistTraversalMethodEnum TraversalMethod);

private:
    LinklistNodeStruct *head; // 头结点
    size_t dataCounter;       // 数据计数器
};

/**
 * @brief 在指定位置插入一个结点
 * @param NewNode 被插入的结点
 * @param index 索引位置
 * @return true 插入成功
 * @return false 插入失败
 */
bool LinklistClass::insertNode(LinklistNodeStruct *NewNode, size_t index)
{
    if (isEmpty())
    {
        if (index != 0)
            return false;
        head = NewNode;
        head->next = head->prev = head;
        dataCounter++;
        return true;
    }
    if (index == 0)
    {
        NewNode->next = head->next;
        NewNode->prev = head;
        head->next->prev = NewNode;
        head->next = NewNode;
        dataCounter++;
        return true;
    }
    LinklistNodeStruct *currentNode = head->next;
    size_t i = 0;
    while (currentNode != head && i < index - 1)
    {
        currentNode = currentNode->next;
        i++;
    }
    if (i == index - 1)
    {
        NewNode->next = currentNode->next;
        NewNode->prev = currentNode;
        currentNode->next->prev = NewNode;
        currentNode->next = NewNode;
        dataCounter++;
        return true;
    }
    return false;
}

/**
 * @brief 删除对应索引的结点
 * @param index
 * @return true 删除成功
 * @return false 删除失败
 */
bool LinklistClass::deleteNode(size_t index)
{
    if (isEmpty())
        return false;
    if (index == 0)
    {
        LinklistNodeStruct *deleteNode = head;
        if (dataCounter == 1)
        {
            delete deleteNode;
            head = nullptr;
        }
        else
        {
            head->prev->next = deleteNode->next;
            deleteNode->next->prev = head->prev; // 头结点的下一结点前指向尾结点
            head = head->next;
        }
        dataCounter--;
        delete deleteNode;
        return true;
    }
    LinklistNodeStruct *currentNode = head->next;
    size_t i = 0;
    while (currentNode != head && i < index - 1)
    {
        currentNode = currentNode->next;
        i++;
    }
    if (currentNode != head && i == index - 1)
    {
        LinklistNodeStruct *deleteNode = currentNode->next;
        currentNode->next = deleteNode->next;
        deleteNode->prev->next = currentNode;
        if (deleteNode == head)
            head = currentNode;
        dataCounter--;
        delete deleteNode;
        return true;
    }
    return false;
}

/**
 * @brief 遍历元素并输出
 * @param TraversalMethod 遍历方法
 * @return true 遍历成功
 * @return false 插入失败
 */
bool LinklistClass::show(LinklistTraversalMethodEnum TraversalMethod = LinklistTraversalMethodFrontToEnd)
{
    if (!dataCounter)
        return false;
    switch (TraversalMethod)
    {
    case LinklistTraversalMethodFrontToEnd:
    {
        LinklistNodeStruct *currentNode = head;
        do
        {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->next;
        } while (currentNode != head);
        std::cout << std::endl;
        break;
    }
    case LinklistTraversalMethodEndToFront:
    {
        LinklistNodeStruct *currentNode = head->prev;
        while (currentNode != head)
        {
            std::cout << currentNode->data << " ";
            currentNode = currentNode->prev;
        }
        std::cout << currentNode->data << std::endl;
    }
    break;

    default:
        return false;
    }
    return true;
}

#endif
