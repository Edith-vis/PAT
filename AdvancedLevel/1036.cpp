#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    string female;
    int femaleScore = -1;//找女性的最高分
    string male;
    int maleScore = 101;//找男性的最低分

    for (int i = 0; i < n; i++) {
        string name, sex, id;
        int score;
        cin >> name >> sex >> id >> score;
        if (sex == "F") {
            if (score > femaleScore) {
                female = name + " " + id;
                femaleScore = score;
            }
        } else {
            if (score < maleScore) {
                male = name + " " + id;
                maleScore = score;
            }
        }
    }

    if (femaleScore != -1) {
        cout << female << endl;
    } else {
        cout << "Absent\n";
    }

    if (maleScore != 101) {
        cout << male << endl;
    } else {
        cout << "Absent\n";
    }

    if (femaleScore != -1 && maleScore != 101) {
        printf("%d", femaleScore - maleScore);
    } else {
        cout << "NA";
    }
    return 0;
}