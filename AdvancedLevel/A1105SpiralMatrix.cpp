#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10000;
int N;
int in[maxn];

int result[maxn][maxn];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &in[i]);
    }
    sort(in, in+N, cmp);

    int n = 1, m = 1;
    for (n = (int)sqrt((double)N); n > 0; n--) {
        if (N % n == 0) {
            m = N / n;
            break;
        }
    }
    //printf("%d--%d\n", f_n, f_m);

    int p = 0;//指向in数组元素的下标
    int level = m / 2 + m % 2;
    for (int k = 0; k < level; k++) {
        //从左到右
        for (int i = k; i < n - k && p < N; i++) {
            result[k][i] = in[p++];
        }

        //从上往下
        for (int i = k + 1; i < m - k - 1 && p < N; i++) {
            result[i][n - k - 1] = in[p++];
        }

        //从右往左
        for (int i = n - k - 1; i >= k && p < N; i--) {
            result[m - k - 1][i] = in[p++];
        }

        //从下往上
        for (int i = m - k - 2; i >= k + 1 && p < N; i--) {
            result[i][k] = in[p++];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j != 0) printf(" ");
            printf("%d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}