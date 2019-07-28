#include <iostream>
#include <cstring>
using namespace std;

int n;
int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d", &n);

    int cnt = 0;
    double temp;
    double sum = 0.0;
    char a[50], b[50];
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);

        int flag = 0;
        for (int i = 0; i < strlen(a); i++) {
            if (a[i] != b[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 1 || temp > 1000 || temp < -1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }

        cnt++;
        sum += temp;
    }

    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if (cnt == 1) {
        printf("The average of 1 number is %.2lf\n", sum);
    } else {
        printf("The average of %d numbers is %.2lf\n", cnt, sum/cnt);
    }
    return 0;
}