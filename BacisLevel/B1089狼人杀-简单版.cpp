#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 110;
int vote[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &vote[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            //设i，j号玩家是狼人
            vector<int> lie;
            vector<int> a(n+1, 1); //好人为1，狼人为-1
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++) {
                if (vote[k] * a[abs(vote[k])] < 0) {
                    lie.push_back(k);
                }
            }
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }

    printf("No Solution\n");

    return 0;
}