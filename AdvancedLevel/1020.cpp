#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int index;
    int value;
};

bool compare (node a, node b) {
    return a.index < b.index;
}

vector<int> post, in;
vector<node> ans;

void pre (int root, int start, int end, int index) {
    if (start > end) {
        return;
    }
    int i = start;
    while (i < end && in[i] != post[root]) {//在中序遍历结果中找根节点
        i++;
    }
    ans.push_back({index, post[root]});
    pre(root-1-end+i, start, i-1, 2*index+1);//左子树 
    pre(root-1, i+1, end, 2*index+2);//右子树
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        post.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        in.push_back(temp);
    }
    pre(n-1, 0, n-1, 0);
    sort(ans.begin(), ans.end(), compare);
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << ans[i].value;
    }

    return 0;
}