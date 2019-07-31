#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1010;
vector<int> v[maxn];
vector<int> degree(maxn);

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        degree[b]++;
    }

    int k;
    cin >> k;
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        bool flag = true;
        vector<int> in = degree;

        for (int j = 0; j < n; j++) {
            int p;
            cin >> p;
            if (in[p] != 0) {
                flag = false;
                //break;
            }
            for (int l = 0; l < v[p].size(); l++) {
                in[v[p][l]]--;
            }
        }

        if (flag == false)
            ans.push_back(i);
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i != 0)
            printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}