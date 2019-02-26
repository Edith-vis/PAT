#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 0; i < k; i++) {
        stack<int> s;
        vector<int> v(n+1);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &v[j]);
        }
        int current = 1;
        for (int j = 1; j <= n; j++) {
            s.push(j);
            if (s.size() > m) {
                break;
            }
            while (s.empty() != true && s.top() == v[current]) {
                s.pop();
                current++;
            }
        }
        if (current == n+1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}