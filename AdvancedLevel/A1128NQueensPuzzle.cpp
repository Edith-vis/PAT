#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        vector<int> a(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                //printf("%d %d\n", j - i, abs(a[i] - a[j]));
                if (abs(a[i]-a[j]) == (j-i) || a[i] == a[j]) {
                    printf("NO\n");
                    flag = false;
                    break;
                }
            }
            if (flag == false)
                break;
        }
        if (flag)
            printf("YES\n");
    }
    return 0;
}