#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        a[abs(i - num)]++;
    }

    for (int i = n; i >= 0; i--) {
        if (a[i] > 1) {
            printf("%d %d\n", i, a[i]);
        }
    }
        return 0;
}