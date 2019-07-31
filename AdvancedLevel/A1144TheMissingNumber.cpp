#include <iostream>
#include <set>
using namespace std;

set<int> num;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        num.insert(number);
    }

    int i = 1;
    while(true) {
        if (num.find(i) == num.end()) {
            printf("%d", i);
            return 0;
        }
        i++;
    }

    return 0;
}