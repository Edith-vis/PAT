#include <iostream>
#include <cstring>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);

    char pwd[22]; int allow;
    scanf("%s %d", pwd, &allow);

    getchar();
    char str[100];
    int cnt = 0;
    while (cin.getline(str, 100) && strcmp(str, "#") != 0) {
        if (strcmp(str, pwd) == 0) {
            printf("Welcome in\n");
            return 0;
        } else {
            printf("Wrong password: %s\n", str);
            cnt++;
            if (cnt == allow) {
                printf("Account locked\n");
                return 0;
            }
        }
    }

    return 0;
}