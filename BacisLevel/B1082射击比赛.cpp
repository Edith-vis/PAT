#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int id;
    int x, y;
};

bool cmp(node a, node b) {
    return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<node> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].id >> a[i].x >> a[i].y;
    }

    sort(a.begin(), a.end(), cmp);

    printf("%04d %04d", a[0].id, a[n - 1].id);

    return 0;
}