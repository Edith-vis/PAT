#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int times;
    cin >> times;
    int pos[55];
    int start[55], end[55];
    for (int i = 1; i < 55; i++) {
        scanf("%d", &pos[i]);
        end[i] = i;
    }

    for (int i = 0; i < times; i++) {
        for (int j = 1; j < 55; j++) {
            start[j] = end[j];
        }
        for (int j = 1; j < 55; j++) {
            end[pos[j]] = start[j];
        }
    }

    char c[6] = {"SHCDJ"};
    for (int i = 1; i < 55; i++) {
        end[i] = end[i]-1;
        printf("%c%d", c[end[i]/13], end[i]%13+1);
        if (i != 54) printf(" ");
    }
    return 0;
}