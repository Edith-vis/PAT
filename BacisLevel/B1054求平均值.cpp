#include <iostream>
#include <cstring>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);//从字符串a中读取浮点型数字到temp中
        sprintf(b, "%.2lf", temp);//将精度未知的浮点型数字temp标准化保留两位数字打印到字符串b中

        int flag = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != b[i]) flag = 1;
        }

        if (flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }

        cnt++;
        sum += temp;
    }

    if (cnt == 1) {
        printf("The average of 1 number is %.2lf\n", sum/cnt);
    } else if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else {
        printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
    }

    return 0;
}