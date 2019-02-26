#include <iostream>
using namespace std;

int main (){
    freopen("D:/in.txt", "r", stdin);
    char c[4] = {"WTL"};//数组c的长度不是3，而是4，这点请务必记住，因为字符串常量"WTL"的最后由系统自动加上一个'\0'
    double ans = 1.0;
    for (int i = 0; i < 3; i++) {
        double maxValue = 0.0;
        int maxIndex = 0;
        for (int j = 0; j < 3; j++) {
            double a;
            cin >> a;
            if (a > maxValue) {
                maxValue = a;
                maxIndex = j;
            }
        }
        cout << c[maxIndex] << " ";
        ans *= maxValue;
    }
    printf("%.2f", (ans*0.65 - 1)*2);
    return 0;
}