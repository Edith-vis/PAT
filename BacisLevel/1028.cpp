#include <iostream>

using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    string maxname, minname;
    string maxtime = "2014/09/06";
    string mintime = "1814/09/06";
    const string Max = "1814/09/06";
    const string Min = "2014/09/06";

    string name, time;
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> name >> time;
        if (time >= Max && time <= Min) {
            total++;
            //cout << name;
            if (time <= maxtime) {
                maxname = name;
                maxtime = time;
                //cout << name;
            } 
            if (time >= mintime) {
                minname = name;
                mintime = time;
            }
        }
    }

    cout << total;
    if (total)
        cout << " " << maxname << " " << minname;
    return 0;
}