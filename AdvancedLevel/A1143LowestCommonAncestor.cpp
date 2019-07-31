#include <iostream>
#include <set>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

const int maxn = 10000;
int pre[maxn];
set<int> s;

node* create(int preL, int preR) {
    if (preL > preR) return NULL;
    if (preL == preR)
        return new node(pre[preL]);
    node *root = new node(pre[preL]);
    int index = preL + 1;
    while (index <= preR && pre[index] < pre[preL]) {
        index++;
    }
    root->left = create(preL + 1, index - 1);
    root->right = create(index, preR);
    return root;
}

int a, b;

void DFS(node *root) {
    if (root == NULL)
        return;
    if ((a - root->data)*(b - root->data) < 0) {
        printf("LCA of %d and %d is %d.\n", a, b, root->data);
        return;
    }
    if (root->data == a || root->data == b) {
        printf("%d is an ancestor of %d.\n", root->data == a ? a : b, root->data == a ? b : a);
        return;
    }
    if (a < root->data && b < root->data) {
        DFS(root->left);
        return;
    }
    if (a >= root->data && b >= root->data) {
        DFS(root->right);
        return;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        s.insert(pre[i]);
    }

    node *root = NULL;
    root = create(0, n - 1);

    while (m--) {
        scanf("%d%d", &a, &b);
        if (s.find(a) == s.end() && s.find(b) == s.end()) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (s.find(a) == s.end() || s.find(b) == s.end()) {
            printf("ERROR: %d is not found.\n", s.find(a) == s.end() ? a : b);
        } else {
            DFS(root);
        }
    }

    return 0;
}