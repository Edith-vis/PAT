#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 2; i < n; i++) {
        int j, num;
        cin >> j >> num;
        v[j] += num;
    }

    int maxj = 1, maxnum = v[1];
    for (int i = 0; i < n; i++) {
        if (v[i] >= maxnum) {
            maxj = i;
            maxnum = v[i];
        }
    }

    cout << maxj << " " << maxnum;

    return 0;
}