#include <iostream>
#include <vector>
using namespace std;

vector<int> prime(500000, 1);//默认500000个数全是素数

int main() {
    freopen("D:/in.txt", "r", stdin);
    long int n;
    scanf("%ld", &n);
    printf("%ld=", n);
    if (n == 1) {
        printf("1");
    }

    for (int i = 2; i*i < 500000; i++) {
        for (int j = 2; j*i < 500000; j++) {
            prime[i*j] = 0;//挑出不是素数的数
        }
    }

    bool state = false;
    for (int i = 2; n >= 2; i++) {
        int cnt = 0;
        int flag = 0;
        while(prime[i] == 1 && n%i == 0) {
            cnt++;
            n = n/i;
            flag = 1;
        }
        if (flag == 1) {
            if(state == true) {
                printf("*");
            }
            printf("%d", i);
            state = true;
        }

        if (cnt >= 2) {
            printf("^%d", cnt);
        }
    }

    return 0;
}