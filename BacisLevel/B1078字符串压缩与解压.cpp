#include <iostream>
#include <cstring>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    string c;
    cin >> c;
    getchar();
    if (c == "C") {
        //printf("YES");
        string s;
        getline(cin, s);
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            int cnt = 1;
            while (s[i] == s[i+1]) {
                cnt++;
                i++;
            }
            //printf("%c", s[i]);
            if (cnt > 1) {
                ans += (to_string(cnt) + s[i]);
            } else {
                ans += s[i];
            }
        }
        cout << ans;
    } else {
        string s;
        getline(cin, s);
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int cnt = s[i] - '0';
                i++;
                while (s[i] >= '0' && s[i] <= '9') {
                    cnt = cnt * 10 + s[i] - '0';
                    i++;
                }
                for (int j = 0; j < cnt; j++) {
                    ans += s[i];
                }
            } else {
                ans += s[i];
            }
        }
        cout << ans;
    }

    return 0;
}