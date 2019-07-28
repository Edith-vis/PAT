#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    //printf("%d", gcd(1, 3));
    int a1, b1, a2, b2, k;
    scanf("%d/%d %d/%d %d", &a1, &b1, &a2, &b2, &k);

    if (a1 * b2 > a2 * b1) {
        swap(a1, a2);
        swap(b1, b2);
    }

    int cnt = 0;
    int i = 1;
    while (a1*k >= b1*i) i++;
    while (a1*k < b1*i && i*b2 < k*a2) {
        if (gcd(i, k) == 1) {
            if (cnt != 0) printf(" ");
            printf("%d/%d", i, k);
            cnt++;
        }
        i++;
    }

    return 0;
}