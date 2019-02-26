#include <iostream>
#include <algorithm>
using namespace std;

//全局变量
int v[1001][1001];
bool visited[1001];
int n;

//深度优先搜索
void dfs(int node){
    visited[node] = true;
    for (int i = 1; i <= n; i++) {//题中city是从1开始编号的
        if (visited[i] == false && v[node][i] == 1) {//深度优先
            dfs(i);
        }
    }
}

int main(){
    freopen("D:/in.txt", "r", stdin);
    int m, k;
    scanf("%d %d %d", &n, &m, &k);
    //转为邻接矩阵(对称)
    int a, b;
    for (int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    //对每个K中的城市
    for (int i = 0; i < k; i++) {
        fill(visited, visited+1001, false);//用false填充visited数组 <algorithm>
        int city;
        scanf("%d", &city);
        int cnt = 0;//连通分量的个数
        visited[city] = true;//去除被占领的城市节点
        //深度优先搜索
        for (int j = 1; j <= n; j++) {//题中city是从1开始编号的
            if (visited[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt-1); //至少需要的线路是连通分量数-1
    }
    return 0;
}
//用scanf和printf替代cin和cout解决超时问题