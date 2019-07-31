#include <iostream>
#include <set>
using namespace std;

const int maxn = 10010;

struct edge {
    int a, b;
} E[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;//n-vertices m-edges
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> E[i].a >> E[i].b;
    }

    int k;
    cin >> k;
    while (k--) {
        int q;
        cin >> q;
        set<int> v;
        for (int i = 0; i < q; i++) {
            int vi;
            cin >> vi;
            v.insert(vi);
        }

        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (v.find(E[i].a) == v.end() && v.find(E[i].b) == v.end()) {
                flag = false;
            }
        }
        printf("%s\n", flag ? "Yes" : "No");
    }

    return 0;
}