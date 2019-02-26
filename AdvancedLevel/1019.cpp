#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int a, b;
    cin >> a >> b;

    //进制转换
    int len=0;
    int arr[40];
    do {
        arr[len++] = a%b;
        a/=b;
    } while (a != 0);

    //判断是否是回文
    if (len==1) {
        cout << "Yes" << endl;
    } else {
        bool flag = true;
        for (int i = 0; i < len/2; i++) {
            if (arr[i] != arr[len-1-i]) {
                cout << "No" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cout << "Yes" << endl;
        }
    }

    //打印d进制下的a
    cout << arr[len-1];
    for (int i = len-2; i >= 0; i--) {
        printf(" %d", arr[i]);
    }

    return 0;
}