/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-05 08:27:57
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _STACK_H
#define _STACK_H

#include <iostream>

class StackClass
{
public:
    StackClass(size_t capacity) : capacity(capacity), topPointer(0), data(new float[capacity]){};
    ~StackClass() { delete[] data; }
    // 栈空
    bool isEmpty() const { return topPointer <= 0; }
    // 栈满
    bool isFull() const { return topPointer >= capacity; }
    // 获得栈顶值
    float top() const { return data[topPointer - 1]; }
    // 入栈
    bool push(float value)
    {
        if (isFull())
            return false;
        else
            data[topPointer++] = value;
        return true;
    }
    // 出栈
    bool pop(float &value)
    {
        if (isEmpty())
            return false;
        else
            value = data[--topPointer];
        return true;
    }
    // 展示栈内元素
    void show()
    {
        for (int i = topPointer - 1; i >= 0; i--) // for (size_t i = 0; i < topPointer; i++)
            std::cout << data[i] << " ";
        std::cout << std::endl;
    }

private:
    size_t capacity;   // 数据容量
    size_t topPointer; // 栈顶计数器
    float *data;       // 数据，动态申请
};

#endif
