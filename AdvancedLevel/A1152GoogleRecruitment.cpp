#include <iostream>
using namespace std;

bool isPrime(int a) {
    if (a <= 1) return false;
    for (int i = 2; i*i < a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

int L, K;
int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &L, &K);
    string str;
    cin >> str;

    for (int i = 0; i+K < L; i++) {
        if (isPrime(stoi(str.substr(i, K)))) {
            cout << str.substr(i, K);
            return 0;
        }
    }
    printf("404\n");

    return 0;
}