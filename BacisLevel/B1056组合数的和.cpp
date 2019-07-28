#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int num;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        sum += num;
    }

    printf("%d", sum*11*(n-1));
    return 0;
}