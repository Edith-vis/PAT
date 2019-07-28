#include <iostream>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int T, k;
    scanf("%d%d", &T, &k);

    int total = T;
    while (k--) {
        int n1, b, t, n2;
        scanf("%d%d%d%d", &n1, &b, &t, &n2);
        
        if (t > total) {
            printf("Not enough tokens.  Total = %d.\n", total);
            continue;
        }
        if ((b == 0 && n1 > n2) || (b == 1 && n1 < n2)) {
            total += t;
            printf("Win %d!  Total = %d.\n", t, total);
        } else {
            total -= t;
            printf("Lose %d.  Total = %d.\n", t, total);
            if (total == 0) {
                printf("Game Over.\n");
                return 0;
            }
        }
    }

    return 0;
}