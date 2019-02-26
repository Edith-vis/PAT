#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
    return a+b < b+a;
}

string s[10001];
int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s, s+n, compare);
    string ans;
    for (int i = 0; i < n; i++) {
        ans += s[i];
    }

    while (ans[0] == '0' && ans.length() != 0)
    {
        ans.erase(ans.begin());
    }

    if (ans.length() == 0) {
        cout << "0";
    }

    cout << ans;

    return 0;
}