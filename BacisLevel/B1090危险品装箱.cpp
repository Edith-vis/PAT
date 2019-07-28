#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int maxn = 100001;
set<int> s[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        s[id1].insert(id2);
        s[id2].insert(id1);
    }

    while (m--) {
        int k;
        cin >> k;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            //cout << a[i] << endl;
        }

        int flag = true;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                //printf("%d %d\n", a[i], a[j]);
                if (s[a[i]].find(a[j]) != s[a[i]].end()) {
                    printf("No\n");
                    flag = false;
                    break;
                }
            }
            if (flag == false)
                break;
        }
        if (flag)
            printf("Yes\n");
    }

    return 0;
}