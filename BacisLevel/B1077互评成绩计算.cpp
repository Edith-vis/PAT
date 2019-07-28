#include <iostream>
#include <cmath>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int g1, g2 = 0;
        cin >> g1;
        int cnt = 0;
        int MAX = -1, MIN = m + 1;
        for (int j = 0; j < n - 1; j++) {
            int score;
            cin >> score;
            if (score >= 0 && score <= m) {
                g2 += score;
                cnt++;
                if (score > MAX) {
                    MAX = score;
                }
                if (score < MIN) {
                    MIN = score;
                }
            }
        }
        g2 -= (MAX + MIN);
        g2 /= (cnt - 2);
        //printf("%d %d\n", g1, g2);
        printf("%d\n", (int)((g1+g2)/2.0+0.5));
    }
        return 0;
}