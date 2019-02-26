#include <iostream>
using namespace std;

int main(){
    freopen("D:/in.txt", "r", stdin);
    int a, now = 0, sum = 0; // a:要去的楼层

    //第一个数没用
    cin >> a;
    while (cin >> a) {
        cout << a << now << endl;
        if (a > now) {
            sum += ((a - now)*6 + 5);
            now = a;
        } else {
            sum += ((now - a)*4 + 5);
            now = a;
        }
    }

    cout << sum;
    return 0;
}