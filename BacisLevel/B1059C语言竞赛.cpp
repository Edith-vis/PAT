#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 10010;
int pai[maxn];
int cnt[maxn];
bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt((float)x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int id;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &id);
        pai[id] = i;
    }

    int m;
    scanf("%d", &m);
    while (m--) {
        int id;
        scanf("%d", &id);

        if (pai[id] == 0) {
            printf("%04d: Are you kidding?\n", id);
            continue;
        } 
        if (cnt[id] != 0) {
            printf("%04d: Checked\n", id);
            continue;
        } 
        
        cnt[id]++;
        if (pai[id] == 1) {
            printf("%04d: Mystery Award\n");
        } else if (isPrime(pai[id]) == true) {
            printf("%04d: Minion\n", id);
        } else {
            printf("%04d: Chocolate\n", id);
        }
    }

    return 0;
}