#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        int tmp = a*a + b*b;
        if (tmp > ans) {
            ans = tmp;
        }
    }

    printf("%.2lf", sqrt((double)ans));

    return 0;
}