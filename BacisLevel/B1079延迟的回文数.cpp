#include <iostream>
#include <algorithm>
using namespace std;

bool isPali(string s) {
    if (s.length() == 1)
        return true;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length()-i-1]) {
            return false;
        }
    }
    return true;
}

string add(string a, string b) {
    int carry = 0;
    string ans = "";
    for (int i = a.length() - 1; i >= 0; i--) {
        ans += ((a[i] - '0') + (b[i] - '0') + carry) % 10 + '0';
        carry = ((a[i] - '0') + (b[i] - '0') + carry) / 10;
    }
    if (carry == 1)
        ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    string num;
    cin >> num;

    for (int i = 0; i < 10; i++) {
        if (isPali(num) == true) {
            cout << num << " is a palindromic number." << endl;
            return 0;
        }
        string tmp = num;
        reverse(tmp.begin(), tmp.end());
        cout << num << " + " << tmp << " = " << add(num, tmp) << endl;
        num = add(num, tmp);
    }

    printf("Not found in 10 iterations.\n");
    return 0;
}