/***
 * @Description:
 * @Author: Amamiya
 * @Date: 2022-08-06 09:29:22
 * @TechChangeTheWorld
 * @WHUROBOCON_Alright_Reserved
 */
#include <iostream>
#include "inc/MyMath.h"
#include "inc/vector.h"

using namespace std;

int main()
{
    Vector2f x(1), y(2);
    Vector2f ans = (x + y).normalize();
    // cout << x.x << " " << y.x << endl;
    cout << ans.x << " " << ans.y << endl;
    // ans += y;
    // cout << ans.x << " " << ans.y << endl;
    return 0;
}
