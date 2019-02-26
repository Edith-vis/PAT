#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int target;

struct node
{
    int weight;
    vector<int> child;//里面存结点编号
};

vector<node> v;
vector<int> path;

bool compare(int a, int b) {
    return v[a].weight > v[b].weight;//非递增
}

void DFS(int index, int nodeNum, int sum) {
    if (sum > target) return;
    if (sum == target) {
        if (v[index].child.size() != 0) return;//到达非叶子结点时已经=target了
        for (int i = 0; i < nodeNum; i++) {
            printf("%d%c", v[path[i]].weight, i != nodeNum-1 ? ' ' : '\n');
        }
        return;
    }
    for (int i = 0; i < v[index].child.size(); i++) {
        int node = v[index].child[i];
        path[nodeNum] = node;
        DFS(node, nodeNum+1, sum+v[node].weight);
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;//n个结点，m个非叶子结点，目标weight为target
    scanf("%d %d %d", &n, &m, &target);
    v.resize(n);
    path.resize(n);
    for (int i = 0; i < n; i++) {//读入每一个结点的weight
        scanf("%d", &v[i].weight);
    }
    int node, number;
    for (int i = 0; i < m; i++) {//读入非叶子结点和它的子结点
        scanf("%d %d", &node, &number);
        v[node].child.resize(number);
        for (int j = 0; j < number; j++) {
            scanf("%d", &v[node].child[j]);
        }
        sort(v[node].child.begin(), v[node].child.end(), compare);
    }

    DFS(0, 1, v[0].weight);

    return 0;
}