#include <iostream>
using namespace std;

struct Node {
    char c;
    int next;
    bool flag;
} node[100001];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int start1, start2, n;
    scanf("%d %d %d", &start1, &start2, &n);
    char data;
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d %c %d", &a, &data, &b);
        node[a] = {data, b, false};//a:Address作为node的编号
    }

    //遍历第一条
    for (int i = start1; i != -1; i = node[i].next) {
        node[i].flag = true;
    }
    //遍历第二条
    for (int i = start2; i != -1; i = node[i].next) {
        if (node[i].flag == true) {
            printf("%05d", i);
            return 0;
        }
    }

    printf("-1");

    return 0;
}