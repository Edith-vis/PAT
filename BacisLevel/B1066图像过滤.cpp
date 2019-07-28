#include <iostream>
using namespace std;

const int maxn = 510;

int pic[maxn][maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m, a, b, k;
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            scanf("%d", &num);
            if (num >= a && num <= b) {
                pic[i][j] = k;
            } else {
                pic[i][j] = num;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0) printf(" ");
            printf("%03d", pic[i][j]);
        }
        printf("\n");
    }


    return 0;
}