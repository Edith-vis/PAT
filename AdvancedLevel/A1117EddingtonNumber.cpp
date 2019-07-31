#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        if (num > n) {
            a[n]++;
        } else {
            if (num > 0)
                a[num-1]++;
        }
    }

    for (int i = n; i >= 0; i--) {
        if (i != n)
            a[i] += a[i + 1];
        if (a[i] >= i) {
            printf("%d", i);
            break;
        }
    }

        return 0;
}