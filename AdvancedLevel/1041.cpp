#include <iostream>
using namespace std;

int a[100001];
int num[100001];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        num[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (num[a[i]] == 1) {
            cout << a[i];
            return 0;
        }
    }

    cout << "None";
    
    return 0;
}