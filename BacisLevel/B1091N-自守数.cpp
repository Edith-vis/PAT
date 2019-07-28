#include <iostream>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        int num;
        scanf("%d", &num);
        bool flag = true;
        for (int i = 1; i <= 9; i++) {
            int mul = num * num * i;
            string _mul = to_string(mul);
            string _num = to_string(num);
            string cmp = _mul.substr(_mul.size()-_num.size());
            if (cmp == _num) {
                cout << i << " " << _mul << endl;
                flag = false;
                break;
            }
        }
        if (flag) cout << "No" << endl;
    }

    return 0;
}