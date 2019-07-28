#include <iostream>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int d, n;
    cin >> d >> n;

    string pre = to_string(d);
    for (int i = 2; i <= n; i++) {
        string now = "";
        for (int j = 0; j < pre.length(); j++) {
            int cnt = 1;
            while (pre[j+1] == pre[j]) {
                cnt++;
                j++;
            }
            now += (pre[j] + to_string(cnt));
        }
        pre = now;
    }
    cout << pre;
    return 0;
}