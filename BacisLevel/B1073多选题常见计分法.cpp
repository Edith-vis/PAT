#include <iostream>
#include <vector>
using namespace std;

int Hash[] = {1, 2, 4, 8, 16};

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);//n-人数 m-多选题个数
    vector<int> rightAns(m, 0);
    vector<int> fullScore(m);

    for (int i = 0; i < m; i++) {
        int optNum, rightNum;
        cin >> fullScore[i] >> optNum >> rightNum;
        for (int j = 0; j < rightNum; j++) {
            char c;
            cin >> c;
            rightAns[i] += Hash[c - 'a'];
        }
    }

    int opt[1001][101] = {{0}};// [人, 题]
    int chooseWrong[101][5] = {{0}};//[题，选项]
    for (int i = 0; i < n; i++) {
        scanf("\n");
        double score = 0.0;
        for (int j = 0; j < m; j++) {
            if (j != 0) scanf(" ");
            int choice;
            scanf("(%d", &choice);
            
            for (int k = 0; k < choice; k++) {
                char c; cin >> c;
                opt[i][j] += Hash[c - 'a'];
            }

            int el = opt[i][j] ^ rightAns[j];//相同为0，相异为1
            if (el == 0) {//相同为0，全部选择正确
                score += fullScore[j];
            } else {
                if ((opt[i][j] | rightAns[j]) == rightAns[j]) {//按位或可以得到正确结果，说明是漏选
                    score += fullScore[j] * 0.5;
                }

                for (int k = 0; k < 5; k++) {
                    if (el & Hash[k]) {//相同为1
                        chooseWrong[j][k]++;
                    }
                }
            }
            scanf(")");
        }
        printf("%.1lf\n", score);
    }

    int maxn = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 5; j++) {
            if (chooseWrong[i][j] > maxn) {
                maxn = chooseWrong[i][j];
            }
        }
    }

    if (maxn == 0) {
        printf("Too simple\n");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 5; j++) {
                if (chooseWrong[i][j] == maxn) {
                    printf("%d %d-%c\n", maxn, i + 1, j + 'a');
                }
            }
        }
    }

    return 0;
}