#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    //int最大32768 太小了
    string a, b;
    int da, db;
    std::cin >> a >> da >> b >> db;
    int counta = 0, countb = 0;
    for (int i = 0; i < a.length(); i++){
        if (da == (a[i] - '0')) {
            counta++;
        }
    }
    for (int i = 0; i < b.length(); i++){
        if (db == (b[i] - '0')) {
            countb++;
        }
    }

    int ta = 0, tb = 0;
    if (counta)
        ta = da;
    if (countb)
        tb = db;
    for (int i = 1; i < counta; i++){
        ta = 10 * ta + da;
    }
    for (int i = 1; i < countb; i++){
        tb = 10 * tb + db;
    }
    cout << ta + tb;
    return 0;
}