#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100001;
int a[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);
    if (n % 2 == 0) {
        printf("0 ");
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i >= n/2) {
                sum2 += a[i];
            } else {
                sum1 += a[i];
            }
        }
        printf("%d", sum2 - sum1);
    } else {
        printf("1 ");
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < (n-1)/2) {
                sum1 += a[i];
            } else if (i > (n-1)/2) {
                sum2 += a[i];
            } else {
                if (a[i] > 0) {
                    sum2 += a[i];
                } else {
                    sum1 += a[i];
                }
            }
        }
        printf("%d", sum2 - sum1);
    }

    return 0;
}