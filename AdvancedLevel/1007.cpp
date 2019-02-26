#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v(n);

    int sum = -1, temp = 0, leftindex = 0, rightindex = n - 1, tempindex = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        temp = temp + v[i];

        if (temp < 0) {
            temp = 0;
            tempindex = i + 1;
        } else if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
    }
    if (sum < 0) {
            sum = 0;
    }

    cout << sum << " " << v[leftindex] << " " << v[rightindex];
    return 0;
}