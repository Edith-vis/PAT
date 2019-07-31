#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int st, en;
bool vis[10000];
int minCnt, minTransfer;
unordered_map<int, int> line;// station1station2-lineID
vector<int> v[10000];
vector<int> tmpPath, path;

int countTransfer(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine)
            cnt++;
        preLine = line[a[i - 1] * 10000 + a[i]];
    }
    return cnt;
}

void DFS(int u, int cnt) {
    if (u == en) {
        if (cnt < minCnt || (cnt == minCnt && countTransfer(tmpPath) < minTransfer)) {
            minCnt = cnt;
            minTransfer = countTransfer(tmpPath);
            path = tmpPath;
        }
        return;
    }

    
    for (int i = 0; i < v[u].size(); i++) {
        if (vis[v[u][i]] == false) {
            vis[v[u][i]] = true;
            tmpPath.push_back(v[u][i]);
            DFS(v[u][i], cnt + 1);
            tmpPath.pop_back();
            vis[v[u][i]] = false;
        } 
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;//number of subway lines
    scanf("%d", &n);
    int m, pre, now;
    for (int lineID = 1; lineID <= n; lineID++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &now);
            v[pre].push_back(now);
            v[now].push_back(pre);
            line[pre*10000+now] = line[now*10000+pre] = lineID;
            pre = now;
        }
    }

    int k;
    scanf("%d", &k);
    while(k--) {
        scanf("%d%d", &st, &en);
        fill(vis, vis + 10000, false);
        minCnt = 99999, minTransfer = 99999;
        tmpPath.clear();
        tmpPath.push_back(st);
        vis[st] = true;
        DFS(st, 0);
        vis[st] = false;
        printf("%d\n", minCnt);

        int preLine = 0, preTransfer = st;
        for (int i = 1; i < path.size(); i++) {
            if (line[path[i-1]*10000+path[i]] != preLine) {
                if (preLine != 0)
                    printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[i - 1]);
                preLine = line[path[i - 1] * 10000 + path[i]];
                preTransfer = path[i - 1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, en);
    }

    return 0;
}