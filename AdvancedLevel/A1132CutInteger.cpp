#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int l = s.length() / 2;
        int num1 = stoi(s.substr(0, l));
        int num2 = stoi(s.substr(l, l));
        //printf("%d %d\n", num1, num2);
        if (num1 == 0 || num2 == 0) {
            printf("No\n");
        } else {
            if (stoi(s) % (num1*num2) == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}