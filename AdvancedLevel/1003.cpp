#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c1, c2;
int e[510][510];//两个城市间的路径长度
int weight[510];//点的权重
int dis[510];//dis[i]从出发点到i结点的最短路径的长度
int num[510];//num[i]从出发点到i结点的最短路径的条数
int w[510];//w[i]从出发点到i结点的救援队的数目之和
bool visit[510];//是否访问过i结点
const int inf = 99999999;

int main(){
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for (int i = 0; i < n; i++) {//n个城市
        scanf("%d", &weight[i]);//读取输入第二行：城市（点）的权重
    }

    fill(e[0], e[0] + 510*510, inf);//初始化路径权重矩阵
    fill(dis, dis + 510, inf);//初始化话最短路径矩阵

    int a, b, c;
    for (int i = 0; i < m; i++) {//m条路径
        scanf("%d%d%d", &a, &b, &c);
        e[a][b] = e[b][a] = c;//填入路径矩阵
    }

    //起点
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;

    //Dijkstra算法求最短路径
    for (int i = 0; i < n; i++) {
        int u = -1;
        int minn = inf;
        //找到u = 使dis[u]最小的还未被访问的顶点的标号;
        for (int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }

        if(u == -1) break;//没找到
        visit[u] = true;//记u已被访问
        for (int v = 0; v < n; v++) {//从u出发能到达的所有顶点v
            if(visit[v] == false && e[u][v] != inf) {
                //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
                if (dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                } else if (dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }

    printf("%d %d", num[c2], w[c2]);
    return 0;
}