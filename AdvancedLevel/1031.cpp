#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    char c[81];
    scanf("%s", &c);

    char u[30][30];
    memset(u, ' ', sizeof(u));

    int n = strlen(c) + 2;//n = N+2
    int n1 = n / 3;
    int n3 = n1;
    int n2 = n / 3 + n % 3;
    int index = 0;

    for (int i = 0; i < n1; i++) {
        u[i][0] = c[index++];
    }
    for (int i = 1; i < n2 - 1; i++) {//从第1个位置到倒数第一个位置 0-(n-1)编号
        u[n1-1][i] = c[index++];
    }
    for (int i = n3 - 1; i >= 0; i--) {
        u[i][n2-1] = c[index++];
    }

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            printf("%c", u[i][j]);
        }
        printf("\n");
    }

    return 0;
}