#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> dis(n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dis[i]);
        dis[i] += dis[i-1];//dis数组里是第一个节点到第i+1个节点的距离
    }
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; i++) {
        int begin, end;
        scanf("%d %d", &begin, &end);
        if (begin > end) {
            swap(begin, end);
        }
        int sum = dis[end-1]-dis[begin-1];
        sum = min(dis[n]-sum, sum);
        printf("%d\n", sum);
    }

    return 0;
}