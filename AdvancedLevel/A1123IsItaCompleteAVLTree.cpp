#include <iostream>
#include <queue>
#include <set>
using namespace std;

const int maxn = 22;
int a[maxn];
int cnt = -1;

struct node {
    int data, height;
    node *left, *right;

    node (int x) {
        data = x;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(node * root) {
    if (root == NULL)
        return 0;
    else
        return root->height;
}

int getBalanceFactor(node * root) {
    return getHeight(root->left) - getHeight(root->right);
}

void updateHeight(node * &root) {
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}

void L(node * &root) {
    node *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(node * &root) {
    node *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

node* insert(node * root, int x) {
    if (root == NULL)
        return new node(x);
    if (x < root->data) {
        root->left = insert(root->left, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->left) == 1) {
                R(root);
            } else if (getBalanceFactor(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    } else {
        root->right = insert(root->right, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->right) == -1) {
                L(root);
            } else if (getBalanceFactor(root->right) == 1) {
                R(root->right);
                L(root);
            }
        }
    }
    return root;
}

void dfs(int id, node * root) {
    if (root == NULL)
        return;
    a[id] = root->data;
    if (id > cnt)
        cnt = id;
    dfs(id * 2, root->left);
    dfs(id * 2 + 1, root->right);
}

void level(node root) {
    //set<node> inq;
    queue<node> q;
    bool flag = false;

    q.push(root);
    while (!q.empty()) {
        node now = q.front();
        if (flag) printf(" ");
        printf("%d", now.data);
        flag = true;
        q.pop();
        if (now.left != NULL) {
            q.push(*now.left);
        }
        if (now.right != NULL) {
            q.push(*now.right);
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    level(*root);
    printf("\n");
    dfs(1, root);
    printf("%s\n", cnt > n ? "NO" : "YES");
    return 0;
}