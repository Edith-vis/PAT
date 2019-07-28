#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1001;
struct cat {
    int id, num;
} moonCake[maxn];

bool cmp(cat a, cat b) {
    if (a.num != b.num) {
        return a.num > b.num;
    } else {
        return a.id < b.id;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            int num;
            scanf("%d", &num);
            moonCake[j].id = j;
            moonCake[j].num += num;
        }
    }

    sort(moonCake + 1, moonCake + n + 1, cmp);
    printf("%d\n", moonCake[1].num);
    printf("%d", moonCake[1].id);
    int i = 2;
    while (i <= n && moonCake[i].num == moonCake[1].num) {
        printf(" %d", moonCake[i].id);
        i++;
    }

    return 0;
}