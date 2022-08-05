/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 09:14:27
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>

// 循环队列类
class QueueClass
{
public:
    QueueClass(size_t capacity) : capacity(capacity), headIndex(0), tailIndex(0), dataCounter(0) { data = new float[capacity]; }
    ~QueueClass() { delete[] data; }
    // 队空
    bool isEmpty() const { return dataCounter <= 0; }
    // 队满
    bool isFull() const { return dataCounter >= capacity; }
    // 获得队首值
    float getFront() const { return data[headIndex]; }
    /**
     * @brief 入队
     * @param value 入队的值
     * @return true 入队成功
     * @return false 入队失败
     */
    bool enqueue(float value)
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
     * @brief 出队并记录出队值
     * @param value 记录出队值的值
     * @return true 出队成功
     * @return false 出队失败
     */
    bool dequeue(float &value)
    {
        if (isEmpty())
            return false;
        else
        {
            value = data[headIndex];
            headIndex = (headIndex + 1) % capacity;
            dataCounter--;
        }
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
    float *data;        // 数据，动态申请
};

#endif
