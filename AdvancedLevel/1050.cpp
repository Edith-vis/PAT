#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool flag[256] = {false};

int main() {
    freopen("D:/in.txt", "r", stdin);
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int len1 = str1.length();
    int len2 = str2.length();
    for (int i = 0; i < len2; i++) {
        flag[int(str2[i])] = true;
    }
    for (int i = 0; i < len1; i++) {
        if (flag[int(str1[i])] == false) {
            cout << str1[i];
        }
    }

    return 0;
}