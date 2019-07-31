#include <iostream>
using namespace std;

const int maxn = 50010;
int n;
int in[maxn], pre[maxn];

struct node {
    int data;
    node * left;
    node * right;
    node (int x) {
        data = x;
        left = right = NULL;
    }
};

node * create(int inL, int inR, int preL, int preR) {
    if (preL > preR)
        return NULL;
    node * root = new node(pre[preL]);
    int index = inL;
    while (in[index] != pre[preL] && index <= inR)
        index++;
    root->left = create(inL, index - 1, preL + 1, preL + 1 + index - 1 - inL);
    root->right = create(index + 1, inR, preL + 1 + index - 1 - inL + 1, preR);
    return root;
}

int post[maxn];
int cnt = 0;
void postOrder(node * root) {
    if (root->left != NULL)
        postOrder(root->left);
    if (root->right != NULL)
        postOrder(root->right);
    post[cnt++] = root->data;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &in[i]);

    node *root = create(0, n - 1, 0, n - 1);
    //printf("%d\n", root->data);
    postOrder(root);
    printf("%d", post[0]);
    return 0;
}

//法二
// #include <iostream>
// using namespace std;

// const int maxn = 50010;
// int n;
// int in[maxn], pre[maxn];

// bool flag = false;
// void create(int inL, int inR, int preL, int preR) {
//     if (preL > preR || flag == true)
//         return;
//     int index = inL;
//     while (in[index] != pre[preL] && index <= inR)
//         index++;
//     create(inL, index - 1, preL + 1, preL + 1 + index - 1 - inL);
//     create(index + 1, inR, preL + 1 + index - 1 - inL + 1, preR);
//     if (flag == false) {
//         printf("%d", pre[preL]);
//         flag = true;
//     }
// }

// int main() {
//   //  freopen("D:/in.txt", "r", stdin);
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &pre[i]);
//     for (int i = 0; i < n; i++)
//         scanf("%d", &in[i]);

//     create(0, n - 1, 0, n - 1);

//     return 0;
// }