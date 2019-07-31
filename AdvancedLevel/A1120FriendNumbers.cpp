#include <iostream>
using namespace std;

int hashTable[40] = {0};
int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        int key = 0;
        for (int j = 0; j < num.length(); j++) {
            key += num[j] - '0';
        }
        //cout << key << endl;
        hashTable[key]++;
    }

    int cnt = 0;
    for (int i = 0; i < 40; i++) {
        if (hashTable[i] >= 1)
            cnt++;
    }
    printf("%d\n", cnt);

    bool flag = false;
    for (int i = 0; i < 40; i++) {
        if (hashTable[i] >= 1) {
            if (flag)
                printf(" ");
            printf("%d", i);
            flag = true;
        }
    }

    

    return 0;
}