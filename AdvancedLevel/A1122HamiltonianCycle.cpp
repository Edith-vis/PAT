#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxn = 210;
bool G[maxn][maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;//n-vertices m-edges
    cin >> n >> m;
    fill(G[0], G[0] + maxn * maxn, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = true;
    }

    int k;
    cin >> k;
    while (k--) {
        int num;
        cin >> num;
        //cout << num << endl;
        set<int> vertice;
        vector<int> v(num);
        for (int i = 0; i < num; i++) {
            cin >> v[i];
            vertice.insert(v[i]);
            //cout << v[i] << endl;
        }
        //printf("yes");

        bool flag1 = true, flag2 = true;
        if (vertice.size() != n || v[0] != v[num-1] || num - 1 != n) {
            flag1 = false;
            //printf("1\n");
            //printf("%d %d\n", vertice.size(), n);
            //printf("%d %d %d\n", vertice.size() != n, v[0] != v[num - 1], num - 1 != n);
            //printf("%d %d\n", v[0], v[num - 1]);
            //printf("%d %d\n", num - 1, n);
        }

        for (int i = 0; i < num - 1; i++) {
            if (G[v[i]][v[i+1]] == false) {
                flag2 = false;
                break;
            }
        }

        printf("%s\n", flag1 && flag2 ? "YES" : "NO");
    }

    return 0;
}