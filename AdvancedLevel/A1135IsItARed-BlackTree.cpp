#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
    node (int x) {
        data = x;
        left = right = NULL;
    }
};

const int maxn = 31;
int pre[maxn];

node* create(int preL, int preR) {
    if (preL > preR)
        return NULL;
    if (preL == preR)
        return new node(pre[preL]);
    node *root = new node(pre[preL]);
    int index = preL + 1;
    while (index <= preR && abs(pre[index]) < abs(pre[preL])) {
        index++;
    }
    root->left = create(preL + 1, index - 1);
    root->right = create(index, preR);
    return root;
}

bool judge1(node *root) {
    if (root == NULL)
        return true;
    if (root->data < 0) {
        if (root->left != NULL && root->left->data < 0)
            return false;
        if (root->right != NULL && root->right->data < 0)
            return false;
    }
    return judge1(root->left) && judge1(root->right);
}

int getNum(node *root) {
    if (root == NULL)
        return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->data > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(node *root) {
    if (root == NULL)
        return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if (l != r)
        return false;
    return judge2(root->left) && judge2(root->right);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int k;
    cin >> k;
    while (k--) {
        int n;
        cin >> n;
        fill(pre, pre + maxn, -1);
        for (int i = 0; i < n; i++) {
            cin >> pre[i];
        }
        node *root = create(0, n - 1);
        if (root->data < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}