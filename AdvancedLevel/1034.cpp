#include <iostream>
#include <map>
using namespace std;

map<string, int> stringToInt;
map<int, string> intToString;

map<string, int> ans;

int k;//阈值

//从1开始排列命名所有不同的⼈的id:避免初始化为0的干扰
int id = 1;
int stoiF(string s) {
    if (stringToInt[s] == 0) {
        stringToInt[s] = id;
        intToString[id] = s;
        return id++;
    } else {
        return stringToInt[s];
    }
}

int G[2001][2001];//图的边权
int W[2001];//结点的权重
bool vis[2001];

//⽤传递引⽤的⽅法深度优先dfs，这样传⼊的参数在dfs后还能保存想要求得的值
void DFS(int u, int &head, int &num, int &totalweight) {
    vis[u] = true;
    num++;//团伙成员个数
    if (W[u] > W[head]) {
        head = u;
    }

    for (int v = 1; v < id; v++) {
        if (G[u][v] > 0) {
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;//遍历过⼀条边之后就把这条边的权值设为0（G[u][v] = G[v][u] = 0;）防⽌出现回路遍历死循环
            if (vis[v] == false) {
                DFS(v, head, num, totalweight);
            }
        }
    }
}

void dfsTrave() {
    for (int i = 1; i < id; i++) {
        if (vis[i] == false) {
            int head = i;
            int num = 0;
            int totalweight = 0;
            DFS(i, head, num, totalweight);
            if (num > 2 && totalweight > k) {
                ans[intToString[head]] = num;
            }
        }
    }
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;//n条通话记录
    scanf("%d %d", &n, &k);
    string s1, s2;
    int time;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> time;
        int id1 = stoiF(s1);
        int id2 = stoiF(s2);
        W[id1] += time;
        W[id2] += time;
        G[id1][id2] += time;
        G[id2][id1] += time;
    }

    dfsTrave();

    cout << ans.size() << endl;
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }


    return 0;
}