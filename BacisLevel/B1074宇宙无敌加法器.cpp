#include <iostream>
#include <algorithm>
using namespace std;

int haha[10] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    freopen("D:/in.txt", "r", stdin);
    string hh;
    cin >> hh;
    reverse(hh.begin(), hh.end());

    int carry = 0;
    string ans = "";
    string num1, num2;
    cin >> num1 >> num2;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int i;
    for (i = 0; i < num1.length() && i < num2.length(); i++) {
        ans += ((num1[i] - '0') + (num2[i] - '0') + carry) % haha[hh[i]-'0'] + '0';
        carry = ((num1[i] - '0') + (num2[i] - '0') + carry) / haha[hh[i]-'0'];
    }

    while (i < num1.length()) {
        ans += ((num1[i] - '0') + carry) % haha[hh[i]-'0'] + '0';
        carry = ((num1[i] - '0') + carry) / haha[hh[i]-'0'];
        i++;
    }

    while (i < num2.length()) {
        ans += ((num2[i] - '0') + carry) % haha[hh[i]-'0'] + '0';
        carry = ((num2[i] - '0') + carry) / haha[hh[i]-'0'];
        i++;
    }

    if (carry != 0)
        ans += "1";

    reverse(ans.begin(), ans.end());
    while (ans[0] == '0' && ans.size() > 1) {
        ans.erase(ans.begin());
    }

    cout << ans;

    return 0;
}