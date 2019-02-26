#include <iostream>
using namespace std;

int book[201], a[10001], dp[10001];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m, l;
    int no, temp;
    scanf("%d", &n);//所涉及到的所有颜色 颜色编号:1-n
    scanf("%d", &m);//喜欢的颜色个数
    for (int i = 1; i <= m; i++) {
        scanf("%d", &no);
        book[no] = i;//编号为no的颜色的位置为i
    }
    scanf("%d", &l);//stripe的长度为l
    int num = 0;
    for (int i = 1; i <= l; i++) {
        scanf("%d", &temp);
        if (book[temp] > 0) {
            a[num++] = book[temp];//保留下该颜色在喜欢序列的位置
        }
    }
    //a数组的长度0-(num-1)
    //找最长的
    int maxL = 0;
    for (int i = 0; i < num; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[i] >= a[j]) {//i的位置比j靠后
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxL = max(maxL, dp[i]);
    }

    printf("%d", maxL);

    return 0;
}