#include <iostream>
#include <set>
using namespace std;

set<int> ans;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int num;
    cin >> num;

    for (int i = 1; i <= num; i++) {
        ans.insert(i / 3 + i / 5 + i / 2);
    }

    printf("%d", ans.size());

    return 0;
}