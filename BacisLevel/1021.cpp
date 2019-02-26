#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    string n;
    cin >> n;
    int a[10] = {0};

    for (int i = 0; i < n.length(); i++) {
        a[n[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        if(a[i]){
            printf("%d:%d\n", i, a[i]);
        }
    }

        return 0;
}