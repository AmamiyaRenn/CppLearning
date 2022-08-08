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
#include <iostream>

struct Vector2f
{
    float x, y;
    Vector2f() : x(0), y(0){};
    Vector2f(float x) : x(x), y(x){};
    Vector2f(float x, float y) : x(x), y(y){};
    // 重载流输出符
    friend std::ostream &operator<<(std::ostream &os, const Vector2f &u) { return os << "(" << u.x << ", " << u.y << ")"; }
    // 正号
    friend Vector2f operator+(const Vector2f &u) { return u; }
    // 负号
    friend Vector2f operator-(const Vector2f &u) { return Vector2f(-u.x, -u.y); }
    // 加法
    friend Vector2f operator+(const Vector2f &u, const Vector2f &v) { return Vector2f(u.x + v.x, u.y + v.y); }
    // 减法
    friend Vector2f operator-(const Vector2f &u, const Vector2f &v) { return Vector2f(u.x - v.x, u.y - v.y); }
    Vector2f operator*(const float r) const { return Vector2f(x * r, y * r); }
    // 自加
    Vector2f &operator+=(const Vector2f &v)
    {
        x += v.x, y += v.y;
        return *this;
    }
    // 自减
    Vector2f &operator-=(const Vector2f &v)
    {
        x -= v.x, y -= v.y;
        return *this;
    }
    // 自乘
    Vector2f &operator*=(const Vector2f &v)
    {
        x *= v.x, y *= v.y;
        return *this;
    }
    // 相同
    bool operator==(const Vector2f &v) const { return x == v.x && y == v.y; }
    // 不同
    bool operator!=(const Vector2f &v) const { return x != v.x || y != v.y; }
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
    float norm() const { return sqrt(x * x + y * y); }
    // 点积
    float dot(const Vector2f &v) const { return x * v.x + y * v.y; }
    // 投影
    float projection(const Vector2f &v) const { return this->dot(v) / v.dot(v); }
};

#endif
