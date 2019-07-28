#include <iostream>
#include <map>
using namespace std;

const int maxn = 1010;
int n, m, k;//m:列 n:行
int v[maxn][maxn];
map<int, int> num;

int direction[8][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};

bool judge(int x, int y) {
    for (int i = 0; i < 8; i++) {
        int newx = x + direction[i][0];
        int newy = y + direction[i][1];
        if (newx >= 0 && newx < n && newy >= 0 && newy < m) {
            if (v[newx][newy] - v[x][y] <= k &&  v[newx][newy] - v[x][y] >= -k) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    scanf("%d%d%d", &m, &n, &k);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &v[i][j]);
            num[v[i][j]]++;
        }
    }

    int cnt = 0;
    int x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (num[v[i][j]] == 1 && judge(i, j) == true) {
                cnt ++;
                x = j+1;
                y = i+1;
            }
        }
    }

    if (cnt == 0) {
        printf("Not Exist\n");
    } else if (cnt > 1) {
        printf("Not Unique\n");
    } else {
        printf("(%d, %d): %d\n", x, y, v[y-1][x-1]);
    }

    return 0;
}