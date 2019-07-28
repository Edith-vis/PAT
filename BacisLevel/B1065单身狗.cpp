#include <iostream>
#include <set>
using namespace std;

const int maxn = 100010;
int Pair[maxn];
bool inParty[maxn];
set<int> alone;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        Pair[a] = b;
        Pair[b] = a;
    }

    fill(inParty, inParty + maxn, false);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a;
        scanf("%d", &a);
        inParty[a] = true;
        alone.insert(a);
    }

    for (auto it = alone.begin(); it != alone.end(); it++) {
        if (Pair[*it] != 0 && inParty[Pair[*it]] == true) {
            alone.erase(alone.find(Pair[*it]));
            alone.erase(it);
        }
    }

    printf("%d\n", alone.size());
    for (auto it = alone.begin(); it != alone.end(); it++) {
        if (it != alone.begin()) printf(" ");
        printf("%05d", *it);
    }

    return 0;
}