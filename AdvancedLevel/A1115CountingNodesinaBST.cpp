#include <iostream>
using namespace std;

struct node {
    int val;
    node *left;
    node *right;
    node(int _val) {
        val = _val;
        left = right = NULL;
    }
};

node* insert(node* root, int val) {
    if (root == NULL) {
        root = new node(val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    } else {
        root->left = insert(root->left, val);
    }
    return root;
}

int num[1000];
int maxDepth = -1;
void DFS(node *root, int depth) {
    if (root == NULL) {
        maxDepth = max(maxDepth, depth);
        //printf("%d\n", maxDepth);
        return;
    }

    num[depth]++;
    DFS(root->left, depth + 1);
    DFS(root->right, depth + 1);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    DFS(root, 1);
    printf("%d + %d = %d", num[maxDepth - 1], num[maxDepth - 2], num[maxDepth - 1] + num[maxDepth - 2]);

    return 0;
}