#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10010;
int length[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &length[i]);
    }

    sort(length, length+n);

    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (i == 1) {
            ans = (length[0] + length[1]) / 2;
            continue;
        }
        ans = (ans + length[i]) / 2;
    }

    printf("%d\n", ans);

    return 0;
}