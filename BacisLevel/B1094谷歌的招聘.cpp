#include <iostream>
using namespace std;

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
    int l, k; string num;
    cin >> l >> k >> num;

    bool flag = true;
    for (int i = 0; i + k <= l; i++) {
        string tmp = num.substr(i, k);
        if (isPrime(stoi(tmp))) {
            // while (tmp[0] == '0' && tmp.size() > 1) {
            //     tmp.erase(tmp.begin());
            // } 测试点里不允许去除前导0
            cout << tmp;
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "404";

        return 0;
}