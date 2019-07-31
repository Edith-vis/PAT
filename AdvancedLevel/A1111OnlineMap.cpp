#include <iostream>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 0x3fffffff;

int n, m, s, d;

int len[maxn][maxn], tim[maxn][maxn];
int dis[maxn];
vector<int> pre[maxn];
vector<int> tmpPath, shortest, fastest;

void Dijkstra(int G[maxn][maxn]) {
    fill(dis, dis + maxn, INF);
    bool vis[maxn] = {false};

    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && dis[j] < MIN) {
                u = j;
                MIN = dis[j];
            }
        }
        if (u == -1)
            return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && G[u][v] != INF) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int minT = INF;
void dfs(int v) {
    if (v == s) {
        tmpPath.push_back(v);
        int totalTime = 0;
        for (int i = tmpPath.size() - 1; i > 0; i--) {
            int id = tmpPath[i], idNext = tmpPath[i - 1];
            totalTime += tim[id][idNext];
        }
        if (totalTime < minT) {
            minT = totalTime;
            shortest = tmpPath;
        }
        tmpPath.pop_back();
    }

    tmpPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        int u = pre[v][i];
        dfs(u);
    }
    tmpPath.pop_back();
}

void dfs1(int v) {
    if (v == s) {
        tmpPath.push_back(v);
        if(fastest.empty() || tmpPath.size() < fastest.size()) {
            fastest = tmpPath;
        }
        tmpPath.pop_back();
    }

    tmpPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++) {
        int u = pre[v][i];
        dfs1(u);
    }
    tmpPath.pop_back();
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    cin >> n >> m;
    fill(len[0], len[0] + maxn * maxn, INF);
    fill(tim[0], tim[0] + maxn * maxn, INF);

    int length, time, a, b, one_way;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> one_way >> length >> time;
        len[a][b] = length;
        tim[a][b] = time;
        if (one_way == 0) {
            len[b][a] = length;
            tim[b][a] = time;
        }
    }

    //int s, d;
    cin >> s >> d;
    Dijkstra(len);
    int Distance = dis[d];
    dfs(d);
    tmpPath.clear();
    for (int i = 0; i < maxn; i++)
        pre[i].clear();
    Dijkstra(tim);
    int Time = dis[d];
    dfs1(d);

    printf("Distance = %d", Distance);
    if (fastest != shortest) {
        for (int i = shortest.size() - 1; i >= 0; i--) {
            if (i != shortest.size() - 1) {
                printf(" -> ");
            } else {
                printf(": ");
            }
            printf("%d", shortest[i]);
        }
        printf("\n");
        printf("Time = %d: ", Time);
        for (int i = fastest.size() - 1; i >= 0; i--) {
            if (i != fastest.size() - 1) {
                printf(" -> ");
            }
            printf("%d", fastest[i]);
        }
    } else {
        printf("; Time = %d: ", Time);
        for (int i = fastest.size() - 1; i >= 0; i--) {
            if (i != fastest.size() - 1) {
                printf(" -> ");
            }
            printf("%d", fastest[i]);
        }
    }

    return 0;
}