#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    string a;
    int b;
    cin >> a >> b;
    int t = 0;
    int temp = 0;
    int len = a.length();

    if (!b)
        return -1;

    t = (a[0] - '0') / b;
    temp = (a[0] - '0') % b;
    if ((t != 0 && len > 1) || len == 1) {
        cout << t;
    }

    for (int i = 1; i < len; i++) {
        t = (temp * 10 + (a[i] - '0')) / b;
        cout << t;
        temp = (temp * 10 + (a[i] - '0')) % b;
    }

    printf(" %d", temp);
    return 0;
}