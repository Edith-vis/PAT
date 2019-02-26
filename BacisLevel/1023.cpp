#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int a[10] = {0};
    for (int i = 0; i < 10; i++){
        cin >> a[i];
    }

    //找到最高位的最小值输出
    int t = 0;
    for (int i = 1; i < 10; i++) {
        if (a[i] != 0) {
            cout << i;
            t = i;
            break;
        }
    }

    for (int i = 0; i < a[0]; i++)
        cout << 0;
    for (int i = 1; i < a[t]; i++)
        cout << t;
    for (int i = t + 1; i < 10; i++)
        for (int j = 0; j < a[i]; j++)
            cout << i;
    
    return 0;
}