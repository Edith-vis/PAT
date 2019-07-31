#include <iostream>
using namespace std;

const int maxn = 10010;
int hashTable[maxn];

bool isPrime(int x) {
    if (x <= 1)
        return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int msize, n, m;
    cin >> msize >> n >> m;
    fill(hashTable, hashTable + maxn, -1);

    while (isPrime(msize) == false) {
        msize++;
    }
    //printf("%d\n", msize);
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool flag = true;
        for (int j = 0; j <= msize - 1; j++) {
            //printf("%d %d %d\n", j, ((num % msize) + j * j) % msize, hashTable[(num % msize + j * j) % msize]);
            if (hashTable[(num % msize + j * j) % msize] == -1) {
                hashTable[(num % msize + j * j) % msize] = num;
                flag = false;
                break;
            }
        }
        if (flag) printf("%d cannot be inserted.\n", num);
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        for (int j = 0; j <= msize; j++) {
            //printf("%d %d %d\n", j, ((num % msize) + j * j) % msize, hashTable[(num % msize + j * j) % msize]);
            cnt++;
            if (hashTable[(num % msize + j * j) % msize] == num || hashTable[(num % msize + j * j) % msize] == -1) {
                //hashTable[(num % msize + j * j) % msize] = num;
                //flag = false;
                break;
            }
        }
    }

    printf("%.1lf", cnt * 1.0 / m);

    return 0;
}