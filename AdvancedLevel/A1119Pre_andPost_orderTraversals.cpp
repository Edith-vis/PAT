#include <iostream>
using namespace std;

const int maxn = 35;
int pre[maxn], post[maxn], in[maxn], k = 0;
bool flag = true;

struct node {
    int data;
    node *left;
    node *right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node* create(int preL, int preR, int postL, int postR) {
    if (preL > preR) {
        return NULL;
    }
    node *root = new node(pre[preL]);
    if (preL == preR) {
        return root;
    }
    int index = postL;
    while (index <= preR - 1 && post[index] != pre[preL+1]) {
        index++;
    }
    int num = index - postL;//左子树节点个数
    if (num == preR - (preL + 1)) {
        flag = false;
        root->left = create(preL + 1, preR, postL, postR - 1);
    } else {
        root->left = create(preL + 1, preL + 1 + num, postL, index);
        root->right = create(preL + 1 + num + 1, preR, index + 1, postR - 1);
    }
    return root;
}

void inOrder(node * root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    if (k)
        cout << " ";
    cout << root->data;
    k++;
    inOrder(root->right);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    node *root = create(0, n - 1, 0, n - 1);
    //puts(flag ? "Yes" : "No");
    printf("%s\n", flag ? "Yes" : "No");
    inOrder(root);
    printf("\n");

    return 0;
}