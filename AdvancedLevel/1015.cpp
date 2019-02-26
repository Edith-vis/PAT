#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, radix;
    while(scanf("%d", &n) != EOF) {
        if (n < 0) {
            break;
        }
        scanf("%d", &radix);
        if (isPrime(n) == false) {
            printf("No\n");
            continue;
        } else {
            //把n转换为radix进制
            //反转
            //把反转后的radix进制的数转为10进制
            int len = 0;
            int arr[100];
            do{
                arr[len++] = n % radix;
                n = n / radix;
            } while (n != 0);
            for (int i = 0; i < len; i++) {
                n = n * radix + arr[i];
            }

            if (isPrime(n) == false) {
                printf("No\n");
            } else {
                printf("Yes\n");
            }
            
        }
    }
    return 0;
}