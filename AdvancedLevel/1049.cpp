#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int left = 0, now = 0, right = 0;
    int ans = 0;
    int a = 1;
    while (n/a != 0) {
        left = n/(a*10);
        now = n/a%10;
        right = n%a;
        if (now == 0) {
            ans += left*a;
        } else if (now == 1) {
            ans += left*a + right + 1;
        } else {
            ans += (left+1)*a;
        }
        a *= 10;
    }
    printf("%d", ans);
    return 0;
}