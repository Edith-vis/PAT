#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, post;
bool isMirror;

void getPost(int root, int tail) {
    if (root > tail) return;
    int i = root+1, j = tail;
    if (!isMirror) {
        while (i <= tail && pre[i] < pre[root]) i++;//左子树
        while (j >= root+1 && pre[j] >= pre[root]) j--;//右子树
    } else {
        while (i <= tail && pre[i] >= pre[root]) i++;
        while (j >= root+1 && pre[j] < pre[root]) j--;
    }

    if (i-j != 1) return;
    getPost(root+1, i-1);//左子树
    getPost(j+1, tail);//右子树
    post.push_back(pre[root]);//根
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    getPost(0, n-1);
    if (post.size() != n) {
        isMirror = true;
        post.clear();
        getPost(0, n-1);
    }

    if (post.size() == n) {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d", post[i]);
            if (i != n-1) printf(" ");
        }
    } else {
        printf("NO");
    }
    return 0;
}