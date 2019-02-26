#include <iostream>
using namespace std;

int a[1001];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }
    for (int i = 0; i < 1001 && m > i; i++) {
        if (a[i] != 0) {
            a[i]--;
            if (a[m-i] != 0) {
                if (i <= m-i) {
                    printf("%d %d", i, m-i);
                } else {
                    printf("%d %d", m-i, i);
                }
                return 0;
            }
            a[i]++;
        }
    }
    printf("No Solution");
    return 0;
}