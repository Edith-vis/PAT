#include <iostream>
#include <queue>
using namespace std;

const int maxn = 510;
int degree[maxn];
bool G[maxn][maxn];

int n, m;//n-vertices m-edges

int father[maxn];
int findFather(int x) {
    int y = x;
    while (x != father[x]) {
        x = father[x];
    }

    while (y != father[y]) {
        int z = y;
        y = father[y];
        father[z] = x;
    }
    return x;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    cin >> n >> m;
    fill(G[0], G[0] + maxn * maxn, false);
    fill(degree, degree + maxn, 0);
    for (int i = 0; i < maxn; i++) {
        father[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = true;
        degree[a]++;
        degree[b]++;
        int fa = findFather(a);
        int fb = findFather(b);
        if (fa != fb)
            father[fa] = fb;
    }

    bool flag1 = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (father[i] == i)
            cnt++;
    }
    if (cnt != 1)
        flag1 = false;

    bool flag2 = true; //是否所有点的度都为偶数
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i != 1)
            printf(" ");
        printf("%d", degree[i]);
        if (degree[i]%2 == 1) {
            flag2 = false;
            cnt++;
        }
    }
    printf("\n");

    if (flag1 && flag2) {
        printf("Eulerian\n");
    } else if (cnt == 2) {
        printf("Semi-Eulerian\n");
    } else {
        printf("Non-Eulerian\n");
    }

    return 0;
}