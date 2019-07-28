#include <iostream>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int product = a * b;
    string ans = "";
    do {
        //printf("%d", product % 10);
        ans += product % 10 + '0';
        product /= 10;
    } while (product != 0);

    while (ans[0] == '0' && ans.size() > 1) {
        ans.erase(ans.begin());
    }

    cout << ans;

    return 0;
}