#include <iostream>
using namespace std;

const int maxn = 33;
int in[maxn], post[maxn];
int level[maxn];

struct node {
    int data;
    node *left, *right;
    int height;
    node (int x) {
        data = x;
        left = right = NULL;
    }
};

node* create(int inL, int inR, int postL, int postR) {
    if (postL > postR)
        return NULL;
    if (postL == postR)
        return new node(post[postR]);
    node *root = new node(post[postR]);
    int index = inL;
    while (index <= inR && in[index] != post[postR]) {
        index++;
    }

    int num = index - inL;

    root->left = create(inL, index - 1, postL, postL + num -1);
    root->right = create(index + 1, inR, postL + num, postR - 1);
    return root;
}

int cnt = -1;
void DFS(node * root, int height, int id) {
    if (root == NULL)
        return;
    root->height = height;
    level[id] = root->data;
    if (id > cnt)
        cnt = id;
    DFS(root->left, height + 1, id * 2);
    DFS(root->right, height + 1, id * 2 + 1);
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> post[i];
    }

    node *root = NULL;
    root = create(0, n - 1, 0, n - 1);
    //printf("%d", root->data);
    DFS(root, 1, 1);

    // for (int i = 1; i < maxn; i++) {
    //     printf("%d ", level[i]);
    // }

    int start = 1, end = 1, step = 1;
    bool flag = false;
    for (int i = 1; start <= cnt; i++) {
        end = start + step - 1;
        if (i % 2 == 1) {
            for (int j = end; j >= start; j--) {
                if (level[j] != 0) {
                    if (flag)
                        printf(" ");
                    printf("%d", level[j]);
                    flag = true;
                }
            }
        } else {
            for (int j = start; j <= end; j++) {
                if (level[j] != 0) {
                    if (flag)
                        printf(" ");
                    printf("%d", level[j]);
                    flag = true;
                }
            }
        }

        step *= 2;
        start = end + 1;
    }

    return 0;
}