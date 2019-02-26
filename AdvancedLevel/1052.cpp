#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int address;
    int key;
    int next;
    bool useful;
} node[100001];

bool compare (Node a, Node b) {
    return (a.useful == false || b.useful == false) ? a.useful > b.useful : 
    a.key < b.key;
    //有用的往前排 key值小的往前排
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, start;
    scanf("%d %d", &n, &start);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        node[a] = {a, b, c, false};//结点编号为节点地址
    }
    //遍历一遍标记并统计有用节点:在链表内的
    int cnt = 0;
    for (int i = start; i != -1; i = node[i].next) {
        node[i].useful = true;
        cnt++;
    }

    if (cnt == 0) {
        printf("0 -1");
    } else {
        sort(node, node + 100001, compare);//排序后node编号变为0、1、2...
        printf("%d %05d\n", cnt, node[0].address);
        for (int i = 0; i < cnt; i++) {
            printf("%05d %d ", node[i].address, node[i].key);
            if (i != cnt - 1) {
                printf("%05d\n", node[i+1].address);
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}