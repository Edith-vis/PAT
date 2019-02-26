#include <iostream>
using namespace std;

int main(){
    freopen("D:/in.txt", "r", stdin);
    float c[1001] = {0};//系数
    int m;
    scanf("%d", &m);
    int t;
    float num;
    for (int i = 0; i < m; i++){
        scanf("%d %f", &t, &num);
        c[t] += num;
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %f", &t, &num);
        c[t] += num;
    }

    int cnt = 0;
    for (int i = 0; i < 1001; i++){
        if (c[i] != 0){
            cnt++;
        }
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--){
        if(c[i] != 0){
            printf(" %d %.1f", i, c[i]);
        }
    }

    return 0;
}