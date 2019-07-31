#include <iostream>
using namespace std;

const int maxn = 10001;
int father[maxn];
int findFather(int id) {
    int x = id;
    while (id != father[id]) {
        id = father[id];
    }

    while (x != father[x]) {
        int y = x;
        x = father[x];
        father[y] = id;
    }
    return id;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    for (int i = 0; i < maxn; i++) {
        father[i] = i;
    }
    int n;
    cin >> n;
    int maxNum = -1;
    while (n--) {
        int k;
        cin >> k;
        int preID, nowID;
        for (int i = 0; i < k; i++) {
            cin >> nowID;
            if (i == 0)
                preID = nowID;
            if (nowID > maxNum)
                maxNum = nowID;
            int fa = findFather(preID);
            int fb = findFather(nowID);
            if (fa != fb) {
                father[fa] = fb;
            }
            preID = nowID;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= maxNum; i++) {
        if (father[i] == i) {
            cnt++;
        }
    }

    printf("%d %d\n", cnt, maxNum);

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (findFather(a) == findFather(b)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}