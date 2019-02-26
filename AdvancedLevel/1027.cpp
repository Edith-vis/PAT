#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    char c[14] = {"0123456789ABC"};
    cout << "#";
    for (int i = 0; i < 3; i++) {
        int num;
        cin >> num;
        printf("%c%c", c[num/13], c[num%13]);
    }

    return 0;
}