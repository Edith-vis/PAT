#include <iostream>
#include <vector>
using namespace std;

const int maxn = 210;
bool G[maxn][maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int nv, ne, m;
    cin >> nv >> ne;
    fill(G[0], G[0] + maxn * maxn, false);
    for (int i = 0; i < ne; i++) {
        int a, b;
        cin >> a >> b;
        G[a][b] = G[b][a] = true;
    }
    cin >> m;
    bool hasIT[maxn];
    while (m--) {
        int k;
        cin >> k;
        fill(hasIT, hasIT + maxn, false);
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            hasIT[v[i]] = true;
        }

        bool isClique = true;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (G[v[i]][v[j]] == false) {
                    isClique = false;
                    break;
                }
            }
        }

        if (isClique) {
            bool isMaximal = true;
            for (int i = 1; i <= nv; i++) {
                if (hasIT[i] == false) {
                    int cnt = 0;
                    for (int j = 0; j < k; j++) {
                        if (G[i][v[j]] == true) {
                            cnt++;
                        }
                    }
                    if (cnt == k) {
                        isMaximal = false;
                    }
                }
            }
            if (isMaximal) {
                printf("Yes\n");
            } else {
                printf("Not Maximal\n");
            }
        } else {
            printf("Not a Clique\n");
        }
    }

    return 0;
}