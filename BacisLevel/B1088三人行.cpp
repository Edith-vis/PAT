#include <iostream>
#include <cmath>
using namespace std;

int m, x, y;

void print(double t) {
    if (t > m)
        printf(" Cong");
    else if (t == m)
        printf(" Ping");
    else
        printf(" Gai");
}

int main() {
    //freopen("D:/in.txt", "r", stdin);
    cin >> m >> x >> y;

    for (int i = 99; i >= 10; i--) {
        int j = i % 10 * 10 + i / 10;
        if (abs(i-j)*y == j*x) {
            printf("%d", i);
            print(i);
            print(j);
            print(j * 1.0 / y);
            return 0;
        }
    }

    printf("No Solution");

    return 0;
}