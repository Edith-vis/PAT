#include <iostream>
#include <set>
using namespace std;

set<int> ans;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int num = 0;
        for (int j = 0; j < str.length(); j++) {
            num += str[j] - '0';
        }
        ans.insert(num);
    }

    printf("%d\n", ans.size());
    for (auto it = ans.begin(); it != ans.end(); it++) {
        if (it != ans.begin()) printf(" ");
        printf("%d", *it);
    }

    return 0;
}