#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxn = 210;
const int INF = 0x3fffffff;

int G[maxn][maxn];
int n, m;//n-vertices m-edges

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    fill(G[0], G[0] + maxn * maxn, INF);
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        scanf("%d", &G[a][b]);
        G[b][a] = G[a][b];
    }
    int k;
    cin >> k;
    int ans = -1, minDis = INF;
    for (int i = 1; i <= k; i++) {
        int num;
        scanf("%d", &num);
        set<int> s;
        vector<int> ve(num);
        int dis = 0;
        for (int j = 0; j < num; j++) {
            scanf("%d", &ve[j]);
            s.insert(ve[j]);
            if (j != 0) {
                if (G[ve[j-1]][ve[j]] == INF) {
                    dis = -1;
                } else if (dis != -1) {
                    dis += G[ve[j - 1]][ve[j]];
                }
            }
        }
        printf("Path %d: ", i);
        if (dis == -1) {
            printf("NA ");
        } else {
            printf("%d ", dis);
        }

        if (ve[0] != ve[num-1] || dis == -1 || s.size() != n) {
            printf("(Not a TS cycle)\n");
            continue;
        } else if (num - 1 > n) {
            printf("(TS cycle)\n");
        } else {
            printf("(TS simple cycle)\n");
        }

        if (dis < minDis) {
            minDis = dis;
            ans = i;
        }
    }
    printf("Shortest Dist(%d) = %d\n", ans, minDis);

    return 0;
}