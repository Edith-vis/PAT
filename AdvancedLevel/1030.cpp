#include <iostream>
#include <vector>
using namespace std;

int e[501][501];//邻接矩阵存图 distance
int cost[501][501];//         cost

bool visit[501];
const int inf = 99999999;
vector<int> path, temppath;

int dis[501];
vector<int> pre[501];//Dijkstra记录路径pre数组

int minCost = inf;

int n, m, starting, destination;//n个节点，m条路

void dfs(int v) {
    temppath.push_back(v);
    if (v == starting) {
        //算当前路径的cost
        int tempcost = 0;
        for (int i = temppath.size() - 1; i > 0; i--) {
            int id = temppath[i];
            int nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        //更新minCost和path
        if (tempcost < minCost) {
            minCost = tempcost;
            path = temppath;
        }

        temppath.pop_back();
        return;
    }

    for (int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    scanf("%d %d %d %d", &n, &m, &starting, &destination);
    fill(e[0], e[0]+501*501, inf);
    fill(dis, dis+501, inf);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        scanf("%d %d", &e[a][b], &cost[a][b]);
        e[b][a] = e[a][b];
        cost[b][a] = cost[a][b];
    }

    //DIjkstra
    pre[starting].push_back(starting); //起点
    dis[starting] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        int minn = inf;
        for (int j = 0; j < n; j++) {
            if (visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1) {
            break;
        }
        visit[u] = true;
        for (int v = 0; v < n; v++) {
            if (visit[v] == false && e[u][v] != inf) {
                if (dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }

    //DFS
    dfs(destination);//从终点开始深度优先搜索

    for (int i = path.size() - 1; i >= 0; i--) {
        printf("%d ", path[i]);
    }

    printf("%d %d", dis[destination], minCost);


    return 0;
}