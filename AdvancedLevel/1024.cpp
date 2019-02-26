#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s;//输入的数

// void add(string t) {
//     int len = s.length();//s和t的长度是一样的
//     int carry = 0;//进位标志
//     for (int i = len-1; i >= 0; i--) {
//         int temp = s[i] + t[i] + carry - '0';
//         carry = 0;
//         if (temp >= 10) {
//             temp = temp - 10;
//             carry = 1;
//         }
//         s[i] = (temp + '0');
//     }

//     if (carry) s.insert(s.begin(), 1, '1');
// }

void add(string t) {
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++) {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int k;
    cin >> s >> k;
    int i;//记录相加的次数
    for (i = 0; i <= k; i++) {// =0意味着本来就是回文数
        string t = s;
        reverse(t.begin(), t.end());//<algorithm>
        if (s == t || i == k) break;
        add(t);//和翻转之后的自己相加
    }
    cout << s << endl << i;
    return 0;
}