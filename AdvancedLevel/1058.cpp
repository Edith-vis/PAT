#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    long long int a, b, c, d, e, f;
    scanf("%lld.%lld.%lld %lld.%lld.%lld", &a, &b, &c, &d, &e, &f);
    long long int num = (a+d)*17*29 + (b+e)*29 + (c+f);

    long long int g = num / (17*29);
    num = num % (17*29);
    printf("%lld.%lld.%lld", g, num/29, num%29);
    return 0;
}