#include <iostream>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    //scanf("%d", &n);
    cin >> n;
    string ans;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> ans;
            if (ans[2] == 'T')
                printf("%d", ans[0]-'A'+1);
        }
    }

    return 0;
}