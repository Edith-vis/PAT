#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    //freopen("D:/in.txt", "r", stdin);
    int n;
    long p;
    cin >> n >> p;
    //p与最小数相乘会超出int范围，所以不能用int定义数组
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int len = 0;
    for (int i = 0; i < n; i++) {
        long max = v[i] * p; //所谓的m * p 因为v[i]是当前在扫描的最小值
        for (int j = i + len; j < n; j++) { //从当前的最长长度往后找
            if (v[j] <= max) {//所谓的M <= m * p
                if (j - i + 1 > len) { //如果当前的长度长于之前的最大长度 更新最大长度
                    len = j - i + 1;
                }
            } else {
                break; //不满足M <= m * p则终止内循环
            }
        }
    }

    cout << len;

    return 0;
}