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

struct Coodinate2f : public Vector2f
{
    float angle; // 平面角(rad)
    float mag;   // 欧氏距离
    float getAngle() const { return angle; }
    float getMag() const { return mag; }
    void calMag() { mag = norm(); }
    void calAngle();
};

#endif
