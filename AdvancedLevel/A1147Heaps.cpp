#include <iostream>
using namespace std;

const int maxn = 1010;
int level[maxn];
int n, m;

bool isMIN(int id) {
    if (id > n)
        return true;
    if (id * 2 <= n && level[id] > level[id*2])
        return false;
    if (id * 2 + 1 <= n && level[id] > level[id*2+1])
        return false;
    return isMIN(id * 2) && isMIN(id * 2 + 1);
}

bool isMAX(int id) {
    if (id > n)
        return true;
    if (id * 2 <= n && level[id] < level[id*2])
        return false;
    if (id * 2 + 1 <= n && level[id] < level[id*2+1])
        return false;
    return isMAX(id * 2) && isMAX(id * 2 + 1);
}

void postOrder(int id) {
    if (id > n)
        return;
    postOrder(id * 2);
    postOrder(id * 2 + 1);
    
    printf("%d", level[id]);
    if (id != 1) printf(" ");
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &m, &n);

    while (m--) {
        fill(level, level + maxn, -1);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &level[i]);
        }
        if (isMAX(1) == false && isMIN(1) == false) {
            printf("Not Heap\n");
        } else {
            printf("%s\n", isMAX(1) ? "Max Heap" : "Min Heap");
        }
        postOrder(1);
        printf("\n");
    }

    return 0;
}