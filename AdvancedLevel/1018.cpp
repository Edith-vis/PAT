#include <iostream>
#include <vector>
using namespace std;

const int inf = 99999999;
int cmax;//偶数，station的最大容量
int n;//station个数
int sp;//有问题的节点编号
int m;//路径个数

int e[501][501];//邻接矩阵:边的长度
int w[501];//节点的权重：-缺少的车辆 +多余的车辆

bool visited[501];
int dis[501];//起点到各个顶点的最短路径长度

vector<int> pre[501];//从源点到i点的最短路径上i的前一个节点编号:for dijkstra
vector<int> temppath, path;//for DFS

int minNeed = inf, minBack = inf;

void dfs(int v) {
    temppath.push_back(v);
    if (v==0) {//如果当前点是源点:出口
        int need = 0;
        int back = 0;
        for (int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];//沿着路径深度优先搜索
            //沿路上的调度
            if (w[id] > 0) {//车多余
                back += w[id];
            } else {
                if (back > -w[id]) {
                    back += w[id];
                } else {
                    need = need - w[id] - back;
                    back = 0;
                }
            }
        }

        if (need < minNeed || (need == minNeed && back < minBack)) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } 
        temppath.pop_back();//删除temppath的最后一个元素
        return;
    }

    for (int i = 0; i < pre[v].size(); i++) {//沿着pre[v]:从源点0到v的最短路径的前一个点的集合
        dfs(pre[v][i]);//对每一个节点
    }
    temppath.pop_back();
}

int main(){
    freopen("D:/in.txt", "r", stdin);

    fill(e[0], e[0]+501*501, inf);
    fill(dis, dis+501, inf);

    scanf("%d %d %d %d", &cmax, &n, &sp, &m);//input的第一行
    for (int i = 1; i <= n; i++) {//input的第二行
        cin >> w[i];
        w[i] = w[i] - cmax/2;
    }
    //输入的后面m行:路径及路径长度
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cin >> e[a][b];
        e[b][a] = e[a][b];
    }

    //Dijkstra
    dis[0] = 0;//0为源点
    for (int i = 0; i <= n; i++) {//对每一点
        int u = -1, minn = inf;
        for (int j = 0; j <= n; j++) {//找距离起点(i)最近的点u
            if (visited[j]==false && dis[j]<minn) {
                u = j;
                minn = dis[j];
            }
        }
        if (u==-1) {//没找到这样的点
            break;
        }
        visited[u] = true;
        for (int v = 0; v <= n; v++) {
            if (visited[v] == false && e[u][v] != inf) {//u,v之间有路
                if (dis[v] > dis[u]+e[u][v]) {//v原先的最短路径长度没有从源点到u到v的短
                    dis[v] = dis[u]+e[u][v];
                    pre[v].clear();//清空原先的路径
                    pre[v].push_back(u);//代表最短路径上前一个节点是u
                } else if (dis[v] == dis[u]+e[u][v]) {//有两条最短路
                    pre[v].push_back(u);//两条路都记录下来
                }
            }
        }
    }

    //dfs:从有问题的点开始深度优先搜索
    dfs(sp);
    printf("%d 0", minNeed);
    for (int i = path.size() - 2; i >= 0; i--) {
        printf("->%d", path[i]);
    }
    printf(" %d", minBack);

    return 0;
}

