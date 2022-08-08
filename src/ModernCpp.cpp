/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-06 09:29:22
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#include <iostream>
#include "inc/MyMath.h"
#include "inc/coodinate.h"

using namespace std;

int main()
{
    Vector2f x(1), y(2);
    Vector2f ans = (x + y).normalize();
    cout << ans << endl;  // 流输出符重载
    Vector2f result = +x; // 重载正号
    ans = -y;             // 重载负号
    cout << result << endl;
    cout << ans << endl;
    Coodinate2f c2f(3);
    c2f += Vector2f(x);
    cout << c2f << endl;

    return 0;
}
