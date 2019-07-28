#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1000001;
char a[maxn], b[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    cin.getline(a, maxn);
    getchar();
    //cin.getline(b, maxn); !问题在于这一句 I don`t konw why!
    int Hash[300] = {0};

    for (int i = 0; i < strlen(a); i++) {
        if (Hash[a[i]] == 0) {
            Hash[a[i]] = 1;
            printf("%c", a[i]);
        }
    }

    for (int i = 0; i < strlen(b); i++) {
        if (Hash[b[i]] == 0) {
            Hash[b[i]] = 1;
            printf("%c", b[i]);
        }
    }

        return 0;
}