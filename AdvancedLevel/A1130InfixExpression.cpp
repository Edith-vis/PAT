#include <iostream>
using namespace std;

const int maxn = 22;

struct node {
    string data;
    int left, right;
}v[maxn];

bool isRoot[maxn];

string DFS(int root) {
    if (v[root].left == -1 && v[root].right == -1)
        return v[root].data;
    if (v[root].left == -1 && v[root].right != -1)
        return "(" + v[root].data + DFS(v[root].right) + ")";
    if (v[root].left != -1 && v[root].right != -1)
        return "(" + DFS(v[root].left) + v[root].data + DFS(v[root].right) + ")";
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;

    fill(isRoot, isRoot + maxn, true);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].data >> v[i].left >> v[i].right;
        if (v[i].left != -1)
            isRoot[v[i].left] = false;
        if (v[i].right != -1)
            isRoot[v[i].right] = false;
    }

    int root = 1;
    while (isRoot[root] == false)
        root++;

    string ans = DFS(root);
    if (ans[0] == '(')
        ans = ans.substr(1, ans.size() - 2);
    cout << ans;
    return 0;
}