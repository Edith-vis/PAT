#include <iostream>
#include <math.h> /* round, floor, ceil, trunc */

using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    char c;
    cin >> n >> c;
    int x = floor(sqrt((n - 1) / 2));
    //int row = 2 * x - 1; //第一行的符号数=最后一行的符号数=总行数
    //cout << first;
    int remain = n - 2 * x * x + 1;
    //cout << remain;
    for (int i = x; i >= 1; i--) {//打印上半部分 步数为1
        //空格
        for (int j = 0; j < x - i; j++) {
            cout << " ";
        }
        //字符
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << c;
        }
        cout << endl;
    }

    for (int i = 2; i <= x; i++) {//打印下半部分
        //空格
        for (int j = 0; j < x - i; j++) {
            cout << " ";
        }
        //字符
        for (int j = 0; j < 2 * i - 1; j++) {
            cout << c;
        }
        cout << endl;
    }

        cout << remain;
    return 0;
}