#include <iostream>
#include <math.h> /* round, floor, ceil, trunc */

using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    float c1, c2;
    cin >> c1 >> c2;
    const float CLK_TCK = 100;
    int seconds = round((c2 - c1) / CLK_TCK);
    //Floor()	不大于自变量的最大整数	
    //Ceil()	不小于自变量的最大整数	
    //Round()	四舍五入到最邻近的整数

    int h, m, s;
    h = seconds / 3600;
    seconds %= 3600;
    m = seconds / 60;
    s = seconds % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}