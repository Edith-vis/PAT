#include <iostream>
#include <vector>
#include <set>
using namespace std;

//确定图连通后，则确定了树，选择合适根结点使树高最大的做法为： 
//先任意选择一个结点，从该节点开始遍历整棵树，获取能达到的最深的结点，记为集合A；然后从集合A中任意一个结点出发遍历整棵树，获取能达到的最深顶点，记为结点集合B。集合A与B的并集就是所求结果。

int n;//结点个数
int maxHeight = 0;

vector<vector<int>> v;//邻接链表存图
//使用c++中的vector构造邻接表，这样的时间复杂度是o(e+v)(顶点数和边数的和)，当输入较大时，无论时间复杂度还是空间复杂度都比使用邻接矩阵要小。
bool visit[10001];
set<int> s;//存放结果
vector<int> temp;//存放临时结果

void dfs(int node, int height) {//height:当前树的高度
    visit[node] = true;
    if (height > maxHeight) {//更新:高度最大
        temp.clear();
        temp.push_back(node);
        maxHeight = height;
    } else if (height == maxHeight) {//多个使高度最大的节点
        temp.push_back(node);
    }

    for (int i = 0; i < v[node].size(); i++) {//对从node出发可到达的每个节点
        //递归的访问所有的邻接点
        if (visit[v[node][i]] == false) {
            dfs(v[node][i], height+1);
        }
    }

}

int main() {
    freopen("D:/in.txt", "r", stdin);
    cin >> n;
    v.resize(n+1);//节点从1开始编号
    int a, b;
    //
    for (int i = 0; i < n; i++) {//存图
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int cnt = 0, s1 = 0;
    //s1为第一次DFS找到的最深点，也是寻找所有最深点时的起始点 
	//cnt是连通分量的数量，求法是看需要多少次调用DFS才能遍历完所有结点
    for (int i = 1; i <= n; i++) {//节点从1开始编号
        if (visit[i] == false) {
            dfs(i, 1);
            if (i == 1) {//第一个节点开始访问的所有叶子节点
                if (temp.size() != 0) {
                    s1 = temp[0];//随便取一个作为第二次深度优先搜索的起点
                } 
                for (int j = 0; j < temp.size(); j++) {
                    s.insert(temp[j]);//集合A塞进set中
                }
            }
            cnt++;//连通分量的个数
        }
    }

    if (cnt > 1) {
        printf("Error: %d components", cnt);
    } else {
        temp.clear();//清空原来的数组A
        maxHeight = 0;
        fill(visit, visit+10001, false);
        dfs(s1, 1);//从一个叶子开始搜索
        for (int i = 0; i < temp.size(); i++) {
            s.insert(temp[i]);
        }

        for (auto it = s.begin(); it != s.end(); it++) {//集合:默认顺序从小到大
            printf("%d\n", *it);
        }
    }
    return 0;
}