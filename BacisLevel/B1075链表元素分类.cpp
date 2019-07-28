#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    int data;
    int rank = -1;
    int address;
    int next;
} nodes[100010];

vector<node> a, b, c;

int addr, n, k;

bool cmp(node a, node b) {
    return a.rank < b.rank;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    cin >> addr >> n >> k;
    for (int i = 0; i < n; i++) {
        int address, data, next;
        cin >> address >> data >> next;
        nodes[address].address = address;
        nodes[address].next = next;
        nodes[address].data = data;
        nodes[address].rank = i;
    }

    int now = addr;
    int cnt = 1;
    do {
        nodes[now].rank = cnt;
        if (nodes[now].data < 0) {
            a.push_back(nodes[now]);
        } else if (nodes[now].data <= k) {
            b.push_back(nodes[now]);
        } else {
            c.push_back(nodes[now]);
        }
        cnt++;
        now = nodes[now].next;
    } while (now != -1);

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    sort(c.begin(), c.end(), cmp);

    for (int i = 0; i < a.size(); i++) {
        if(i == 0) {
            printf("%05d %d ", a[i].address, a[i].data);
        } else {
            printf("%05d\n%05d %d ", a[i].address, a[i].address, a[i].data);
        }
    }

    for (int i = 0; i < b.size(); i++) {
        if (i == 0) {
            if (a.size() == 0) {
                printf("%05d %d ", b[i].address, b[i].data);
            } else {
                printf("%05d\n%05d %d ", b[i].address, b[i].address, b[i].data);
            }
        } else {
            printf("%05d\n%05d %d ", b[i].address, b[i].address, b[i].data);
        }
    }

    for (int i = 0; i < c.size(); i++) {
        if (i == 0) {
            if (a.size() == 0 && b.size() == 0) {
                printf("%05d %d ", c[i].address, c[i].data);
            } else {
                printf("%05d\n%05d %d ", c[i].address, c[i].address, c[i].data);
            }
        } else {
            printf("%05d\n%05d %d ", c[i].address, c[i].address, c[i].data);
        }
    }
    printf("-1\n");

    return 0;
}