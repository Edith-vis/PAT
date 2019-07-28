#include <iostream>
//using namespace std;

const int maxm = 101;
int total[maxm];
int right[maxm];
int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &total[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &right[i]);
    }

    for (int i = 0; i < n; i++) {
        int score = 0, ans;
        for (int j = 0; j < m; j++) {
            scanf("%d", &ans);
            if (ans == right[j]) {
                score += total[j];
            }
        }
        printf("%d\n", score);
    }

    return 0;
}