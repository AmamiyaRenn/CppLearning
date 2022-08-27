/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-06 09:28:47
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _MYMATH_H
#define _MYMATH_H

#define PI 3.14159265f
constexpr float PIfunc(float x) { return x *PI; }

template <class T>
void Swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif
