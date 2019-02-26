#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;

    int win = 0, draw = 0, lose = 0; // 甲的胜、平、负      乙的负、平、胜
    int j[3] = {0}; //甲赢的时候 出的什么 B0 C1 J2
    int y[3] = {0}; //乙赢的时候 出的什么

    //统计输入
    for (int i = 0; i < n; i++) {
        char a, b;
        cin >> a >> b;

        if (a == b) {
            draw++;
        } else if (a =='B' && b == 'C') {
            //甲出B赢
            win++;
            j[0]++;
        } else if (a == 'C' && b == 'J') {
            //甲出C赢
            win++;
            j[1]++;
        } else if (a == 'J' && b == 'B') {
            //甲出J赢
            win++;
            j[2]++;
        } else if (b == 'B' && a == 'C') {
            //乙出B赢
            lose++;
            y[0]++;
        } else if (b == 'C' && a == 'J') {
            //乙出C赢
            lose++;
            y[1]++;
        } else if (b == 'J' && a == 'B') {
            //乙出J赢
            lose++;
            y[2]++;
        }
    }

    printf("%d %d %d\n", win, draw, lose);
    printf("%d %d %d\n", lose, draw, win);

    int maxj = j[0] >= j[1] ? 0 : 1;
    maxj = j[maxj] >= j[2] ? maxj : 2;
    int maxy = y[0] >= y[1] ? 0 : 1;
    maxy = y[maxy] >= y[2] ? maxy : 2;

    string s = "BCJ";
    std::cout << s[maxj] <<" " << s[maxy];

    return 0;
}