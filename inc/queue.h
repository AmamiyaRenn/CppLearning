/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 09:14:27
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdlib.h>
#include <iostream>

// 循环队列类
template <class T>
class QueueClass
{
public:
    // 构造函数
    QueueClass(size_t capacity) : capacity(capacity), headIndex(0), tailIndex(0), dataCounter(0), data(new T[capacity]){};
    // 拷贝构造函数，实现初始化时深拷贝
    QueueClass(const QueueClass<T> &queueCopied) : capacity(queueCopied.capacity), headIndex(queueCopied.headIndex), tailIndex(queueCopied.tailIndex), dataCounter(queueCopied.dataCounter), data(new T[capacity])
    {
        for (size_t i = 0; i < dataCounter; i++)
            data[(headIndex + i) % capacity] = queueCopied.data[(headIndex + i) % capacity];
    }
    // 析构函数
    ~QueueClass() { delete[] data; }
    // 拷贝赋值函数，实现赋值时深拷贝
    QueueClass &operator=(const QueueClass &queueCopied)
    {
        if (this == &queueCopied) // 检查是否是自己
            return *this;
        delete[] data;
        capacity = queueCopied.capacity;
        headIndex = queueCopied.headIndex;
        tailIndex = queueCopied.tailIndex;
        dataCounter = queueCopied.dataCounter;
        data = new T[capacity];
        memcpy(data, queueCopied.data, dataCounter * sizeof(T)); // 用memcpy快一点
        return *this;
    }
    // 队空
    bool isEmpty() const { return dataCounter <= 0; }
    // 队满
    bool isFull() const { return dataCounter >= capacity; }
    // 获得队首值
    T &getFront() const { return data[headIndex]; }
    /**
     * @brief 入队
     * @param value 入队的值
     * @return true 入队成功
     * @return false 入队失败
     */
    bool enqueue(const T &value)
    {
        if (isFull())
            return false;
        else
        {
            data[tailIndex] = value;
            tailIndex = (tailIndex + 1) % capacity;
            dataCounter++;
        }
        return true;
    }
    /**
     * @brief 批量入队
     * @param valueAddress 被拷贝的值的首地址
     * @param len 长度
     * @return true 入队成功
     * @return false 入队失败
     */
    bool enqueue(T *valueAddress, size_t len)
    {
        if (tailIndex < capacity - len && dataCounter < capacity - len) // 如果剩余内存连续并且剩余长度大于数据长度
        {
            memcpy(&data[tailIndex], valueAddress, len * sizeof(T)); // 用memcpy快一点
            tailIndex = (tailIndex + 1) % capacity;
            dataCounter += len;
            return true;
        }
        else
        {
            for (size_t i = 0; i < capacity; i++)
                if (!enqueue(*(valueAddress + i)))
                    return false;
            return true;
        }
    }
    /**
     * @brief 出队并记录出队值
     * @param value 记录出队值的值
     * @return true 出队成功
     * @return false 出队失败
     */
    bool dequeue(T &value)
    {
        if (isEmpty())
            return false;
        else
        {
            value = data[headIndex];
            headIndex = (headIndex + 1) % capacity;
            dataCounter--;
        }
        return true;
    }
    /**
     * @brief 出队并记录出队值
     * @param valueAddress 被拷贝的值的首地址
     * @param len 长度
     * @return true 出队成功
     * @return false 出队失败
     */
    bool dequeue(T *valueAddress, size_t len)
    {
        for (size_t i = 0; i < len; i++)
            if (!dequeue(*(valueAddress + i)))
                return false;
        return true;
    }
    // 展示队内元素
    void show()
    {
        for (size_t i = 0; i < dataCounter; i++)
            std::cout << data[(headIndex + i) % capacity] << " ";
        std::cout << std::endl;
    }

private:
    size_t capacity;    // 数据容量
    size_t headIndex;   // 队首索引
    size_t tailIndex;   // 队尾索引
    size_t dataCounter; // 数据计数器
    T *data;            // 数据，动态申请
};

#endif
