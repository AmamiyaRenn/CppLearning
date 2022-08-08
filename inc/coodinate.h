/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-06 10:02:47
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#ifndef _COODINATE_H
#define _COODINATE_H

#include "vector.h"

struct Coodinate2f : Vector2f
{
    using Vector2f::Vector2f; // 使用基类的构造函数
    Coodinate2f(const Vector2f &vector) : Vector2f(vector){};
    friend std::ostream &operator<<(std::ostream &os, const Coodinate2f &u) { return os << "(" << u.x << ", " << u.y << ") "
                                                                                        << "angle = " << u.angle << "rad magnitude = " << u.mag; }
    float angle; // 平面角(rad)
    float mag;   // 欧氏距离
    float getAngle() const { return angle; }
    float getMag() const { return mag; }
    void calMag() { mag = norm(); }
    void calAngle();
};

#endif
