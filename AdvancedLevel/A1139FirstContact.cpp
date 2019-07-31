#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10000];
unordered_map<int, bool> friends;

struct node {
    int a, b;
};

bool cmp(node a, node b) {
    if (a.a != b.a)
        return a.a < b.a;
    else
        return a.b < b.b;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    while (m--) {
        string a, b;
        //scanf("%d%d", &a, &b);
        cin >> a >> b;
        if(a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        friends[abs(stoi(a)) * 10000 + abs(stoi(b))] = friends[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }

    int k;
    scanf("%d", &k);
    while (k--) {
        int a, b;
        scanf("%d%d", &a, &b);
        vector<node> ans;
        for (int i = 0; i < v[abs(a)].size(); i++) {
            for (int j = 0; j < v[abs(b)].size(); j++) {
                if (abs(a) == v[abs(b)][j] || abs(b) == v[abs(a)][i])
                    continue;
                if (friends[v[abs(a)][i]*10000+v[abs(b)][j]])
                    ans.push_back(node{v[abs(a)][i], v[abs(b)][j]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); i++) {
            printf("%04d %04d\n", ans[i].a, ans[i].b);
        }
    }
    return 0;
}