#include <iostream>
using namespace std;

int main(){
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;

    string minn = "23:59:59:59";
    string maxn = "00:00:00:00";
    string unlocked, locked;
    for (int i = 0; i < n; i++) {
        string id;
        cin >> id;
        string tempIn, tempOut;
        cin >> tempIn >> tempOut;
        if (tempIn < minn) {
            minn = tempIn;
            unlocked = id;
        } 

        if (tempOut > maxn) {
            maxn = tempOut;
            locked = id;
        }
    }

    cout << unlocked << " " << locked;

    return 0;
}