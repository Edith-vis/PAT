#include <iostream>
using namespace std;

int N, D;
double e;

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d %lf %d", &N, &e, &D);

    int flag1 = 0, flag2 = 0;
    for (int i = 0; i < N; i++) {
        int k;
        scanf("%d", &k);
        int numLowerThanE = 0;
        double use;
        for (int j = 0; j < k; j++) {
            scanf("%lf", &use);
            if (use < e) {
                numLowerThanE++;
            }
        }

        if (numLowerThanE > k/2 && k > D) {
            flag2++;
        } else if (numLowerThanE > k/2) {
            flag1++;
        }
    }

    //printf("%d %d\n", flag1, flag2);

    printf("%.1lf", ((double)flag1)/N*100);
    cout << "% ";
    printf("%.1lf", ((double)flag2)/N*100);
    cout << "%";

    return 0;
}