#include <iostream>
#include <vector>
using namespace std;

vector<int> v[100];
int book[100], maxdepth = -1;

//图的深度优先搜索 递归
void dfs(int index, int depth) {
    if(v[index].size() == 0) {//递归出口：找到一个子结点
        book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
    }

    for (int i = 0; i < v[index].size(); i++) {
        dfs(v[index][i], depth + 1);
    }
}

int main(){
    freopen("D:/in.txt", "r", stdin);
    int n, m; //n：树的所有结点的个数  m：树的非叶子结点的个数
    scanf("%d %d", &n, &m);

    int node, k;//node:结点标号 k：子结点个数
    int c;//子结点的标号
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &node, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);//存下该结点的所有子结点编号
        }
    }

    dfs(1, 0);//根节点即起点
    printf("%d", book[0]);//打印每层的叶子结点个数
    for (int i = 1; i <= maxdepth; i++) {
        printf(" %d", book[i]);
    }

    return 0;
}