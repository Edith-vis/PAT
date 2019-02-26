#include <iostream>
using namespace std;

int main(){
    freopen("D:/in.txt", "r", stdin);
    int n1, n2, a, cnt = 0;
    double b, arr1[1001] = {0.0}, ans[2001] = {0.0};

    //读取第一个数组
    cin >> n1;
    for (int i = 0; i < n1; i++) {
        scanf("%d %lf", &a, &b);
        arr1[a] = b;
    }

    //读取第二个数组并计算
    cin >> n2;
    for (int i = 0; i < n2; i++) {
        scanf("%d %lf", &a, &b);
        for (int j = 0; j < 1001; j++) {
            ans[j+a] += arr1[j]*b;
        }
    }

    //统计非零项
    for (int i = 0; i < 2001; i++) {
        if (ans[i] != 0.0) {
            cnt++;
        }
    }
    cout << cnt;

    //打印幂和系数
    for (int i = 2000; i >= 0; i--) {
        if (ans[i] != 0.0) {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}