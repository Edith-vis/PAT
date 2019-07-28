#include <iostream>
#include <cstring>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    getchar();
    char pwd[90];
    while (n--) {
        //gets(pwd);
        cin.getline(pwd, 90);
        int len = strlen(pwd);
        if (len < 6) {
            printf("Your password is tai duan le.\n");
            continue;
        }
        bool illegal = false, hasNoNum = true, hasNoZiMu = true;
        for (int i = 0; i < len; i++) {
            if ((pwd[i] >= 'a' && pwd[i] <= 'z') || (pwd[i] >= 'A' && pwd[i] <= 'Z')) {
                hasNoZiMu = false;
            } else if (pwd[i] >= '0' && pwd[i] <= '9') {
                hasNoNum = false;
            } else if (pwd[i] == '.') {

            } else {
                illegal = true;
            }
        }

        if (illegal) {
            printf("Your password is tai luan le.\n");
        } else if (hasNoNum) {
            printf("Your password needs shu zi.\n");
        } else if (hasNoZiMu) {
            printf("Your password needs zi mu.\n");
        } else {
            printf("Your password is wan mei.\n");
        }
    }
    return 0;
}