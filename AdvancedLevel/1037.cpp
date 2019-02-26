#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m;
    scanf("%d", &m);
    vector<int> v1(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v1[i]);
    }

    int n;
    scanf("%d", &n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v2[i]);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int p = 0, q = 0;
    int ans = 0;
    while (p < m && q < n && v1[p] < 0 && v2[p] < 0) {
        ans += v1[p++]*v2[q++];
    }

    p = m-1;
    q = n-1;
    while (p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0) {
        ans += v1[p--]*v2[q--];
    }

    printf("%d", ans);
    
    return 0;
}