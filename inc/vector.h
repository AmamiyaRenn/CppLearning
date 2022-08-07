/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-06 09:35:19
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _VECTOR_H
#define _VECTOR_H

#include <math.h>

struct Vector2f
{
    float x, y;
    Vector2f() : x(0), y(0){};
    Vector2f(float x) : x(x), y(x){};
    Vector2f(float x, float y) : x(x), y(y){};
    Vector2f operator+(const Vector2f &v) const { return Vector2f(x + v.x, y + v.y); }
    Vector2f operator-(const Vector2f &v) const { return Vector2f(x - v.x, y - v.y); }
    Vector2f operator*(const float r) const { return Vector2f(x * r, y * r); }
    // 自加
    void operator+=(const Vector2f &v) { x += v.x, y += v.y; }
    // 自减
    void operator-=(const Vector2f &v) { x -= v.x, y -= v.y; }
    // 自乘
    void operator*=(const Vector2f &v) { x *= v.x, y *= v.y; }
    // 返回自身的标准化值
    Vector2f normalize() const
    {
        const float magnitude = norm();
        const float invMag = 1 / magnitude;
        return Vector2f(x * invMag, y * invMag);
    }
    // 将自身标准化（化为单位向量）
    void normalized()
    {
        const float magnitude = norm();
        const float invMag = 1 / magnitude;
        x = x * invMag;
        y = y * invMag;
    }
    // 二范数
    float norm() const { sqrt(x * x + y * y); }
    // 点积
    float dot(const Vector2f &v) const { return x * v.x + y * v.y; }
    // 投影
    float projection(const Vector2f &v) const { return this->dot(v) / v.dot(v); }
};

#endif
