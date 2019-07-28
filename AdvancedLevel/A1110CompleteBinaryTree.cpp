#include <iostream>
using namespace std;

struct node {
    int left, right;
} nodes[100];

int n;
int root;
int maxn = -1;
int ans;
bool isRoot[100];//初始化为true
//int tree[101];

void DFS(int now_root, int index) {
    if (index > maxn) {
        maxn = index;
        ans = now_root;
    }

    //tree[index] = now_root;

    if (nodes[now_root].left != -1)
        DFS(nodes[now_root].left, index * 2);
    if (nodes[now_root].right != -1)
        DFS(nodes[now_root].right, index * 2 + 1);
}
int main() {
    freopen("D:/in.txt", "r", stdin);
    cin >> n;
    string a, b;
    fill(isRoot, isRoot + 100, true);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        //printf("%c %c\n", a, b);
        if (a == "-") {
            nodes[i].left = -1;
        } else {
            nodes[i].left = stoi(a);
            //printf("%d\n", a-'0');
            isRoot[stoi(a)] = false;
        }

        if (b == "-") {
            nodes[i].right = -1;
        } else {
            nodes[i].right = stoi(b);
            //printf("%d\n", b-'0');
            isRoot[stoi(b)] = false;
        }
    }

    root = 0;
    while (isRoot[root] != true) {
        root++;
    }

    DFS(root, 1);

    if (maxn == n) {
        cout << "YES " << ans << endl;
    } else {
        cout << "NO " << root << endl;
    }

    return 0;
}