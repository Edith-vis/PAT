#include <iostream>
#include <vector>
using namespace std;

const int maxn = 510;
const int INF = 0x3fffffff;
int g_length[maxn][maxn]; vector<int> pre_shortest[maxn]; vector<int> path_shortest;
int g_time[maxn][maxn]; vector<int> pre_fastest[maxn]; vector<int> path_fastest;
int n, m;
int source, des;
vector<int> tmpPath;

int d[maxn];
int t[maxn];
bool vis[maxn] = {false};

void Dijkstra_fastest(int s) {
    fill(t, t + maxn, INF);
    fill(vis, vis + maxn, false);
    t[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && g_time[u][v] != INF) {
                if (t[u] + g_time[u][v] < t[v]) {
                    t[v] = t[u] + g_time[u][v];
                    pre_fastest[v].clear();
                    pre_fastest[v].push_back(u);
                    //printf("t[%d] = %d\n", v, t[v]);
                } else if (t[u] + g_time[u][v] == t[v]) {
                    pre_fastest[v].push_back(u);
                }
            }
        }
    }
}

void DFS_fastest(int v) {
    if (v == source) {
        tmpPath.push_back(v);
        if (path_fastest.empty()) {
            path_fastest = tmpPath;
        } else if (tmpPath.size() < path_fastest.size()) {
            path_fastest = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }

    tmpPath.push_back(v);
    for (int i = 0; i < pre_fastest[v].size(); i++) {
        DFS_fastest(pre_fastest[v][i]);
    }
    tmpPath.pop_back();
}

void Dijkstra_shortest(int s) {//s为起点
    fill(d, d + maxn, INF);
    fill(vis, vis + maxn, false);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && g_length[u][v] != INF) {
                if (d[u] + g_length[u][v] < d[v]) {
                    d[v] = d[u] + g_length[u][v];
                    pre_shortest[v].clear();
                    pre_shortest[v].push_back(u);
                    //printf("d[%d] = %d\n", v, d[v]);
                } else if (d[u] + g_length[u][v] == d[v]) {
                    pre_shortest[v].push_back(u);
                }
            }
        }
    }
}

int minTime = INF;
void DFS_shortest(int v) {//v为当前结点
    if (v == source) {
        tmpPath.push_back(v);
        int tmpTime = 0;
        for (int i = tmpPath.size() - 1; i > 0; i--) {
            int id = tmpPath[i], idNext = tmpPath[i - 1];
            tmpTime += g_time[id][idNext];
        }
        if (tmpTime < minTime) {
            minTime = tmpTime;
            path_shortest = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }

    tmpPath.push_back(v);
    for (int i = 0; i < pre_shortest[v].size(); i++) {
        DFS_shortest(pre_shortest[v][i]);
    }
    tmpPath.pop_back();
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    fill(g_length[0], g_length[0] + maxn * maxn, INF);
    fill(g_time[0], g_time[0] + maxn * maxn, INF);
    int v1, v2, one_way, length, time;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d %d", &v1, &v2, &one_way, &length, &time);
        g_length[v1][v2] = length;
        g_time[v1][v2] = time;
        if (one_way == 1) continue;
        g_length[v2][v1] = length;
        g_time[v2][v1] = time;
    }
    
    scanf("%d %d", &source, &des);
    //printf("%d %d\n", source, des);
    Dijkstra_shortest(source);
    DFS_shortest(des);
    tmpPath.clear();
    Dijkstra_fastest(source);
    DFS_fastest(des);
    printf("Distance = %d", d[des]);
    if (path_fastest != path_shortest) {
        for (int i = path_shortest.size() - 1; i >= 0; i--) {
            if (i != path_shortest.size() - 1) {
                printf(" -> ");
            } else {
                printf(": ");
            }
            printf("%d", path_shortest[i]);
        }
        printf("\n");
        printf("Time = %d: ", t[des]);
        for (int i = path_fastest.size() - 1; i >= 0; i--) {
            if (i != path_fastest.size() - 1) {
                printf(" -> ");
            }
            printf("%d", path_fastest[i]);
        }
    } else {
        printf("; Time = %d: ", t[des]);
        for (int i = path_fastest.size() - 1; i >= 0; i--) {
            if (i != path_fastest.size() - 1) {
                printf(" -> ");
            }
            printf("%d", path_fastest[i]);
        }
    }
    return 0;
}