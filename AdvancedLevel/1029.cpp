#include <iostream>
using namespace std;

int s1[200001];

int main() {
    freopen("D:/in.txt", "r", stdin);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &s1[i]);
    }
    s1[n] = 0x7fffffff;//???

    int m;
    cin >> m;
    int midPos = (n + m + 1)/2;
    int i = 0;
    int temp;
    int count = 0;
    for (int j = 0; j < m; j++) {
        scanf("%d", &temp);
        while(s1[i] < temp) {
            count++;
            if (midPos == count) {
                printf("%d", s1[i]);
            }
            i++;
        }
        count++;
        if (midPos == count) {
            printf("%d", temp);
        }
    }

    while (i < n) {
        count++;
        if (midPos == count) {
            printf("%d", s1[i]);
        }
        i++;
    }

    return 0;
}