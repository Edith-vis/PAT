#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 10010;
int n, m;
int color[maxn];

struct V {
    int u, v;
} G[maxn];
int num = 0;
int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        G[num].u = u, G[num].v = v;
        num++;
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        set<int> colors;
        for (int i = 0; i < n; i++) {
            scanf("%d", &color[i]);
            colors.insert(color[i]);
        }

        int flag = true;
        for (int i = 0; i < num; i++) {
            if (color[G[i].u] == color[G[i].v]) {
                flag = false;
                printf("No\n");
                break;
            }
        }

        if (flag) printf("%d-coloring\n", colors.size());
    }

    return 0;
}