#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    string s;
    cin >> s;

    if (s[0] == '-')
        cout << "-";

    int flag = 0; //E的位置，指数和底数的分界
    while (s[flag] != 'E')
        flag++;

    string t = s.substr(1, flag - 1); //底数部分
    int n = stoi(s.substr(flag + 2, s.length() - 1)); //指数部分 是个整数

    if (s[flag + 1] == '-') {
        cout << "0.";
        for (int i = 0; i < abs(n) - 1; i++) {
            cout << "0";
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '.')
                cout << t[i];
        }
    } else {
        cout << t[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < t.length() && (cnt < n); j++, cnt++) {
            cout << t[j];
        }
        if (j == t.length()) {
            for (int k = 0; k < n - cnt; k++)
                cout << 0;
        } else {
            cout << ".";
            for (int k = j; k < t.length(); k++) {
                cout << t[k];
            }
        }
    }
    return 0;
}