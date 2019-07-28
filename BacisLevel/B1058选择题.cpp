#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct problem {
    int id;
    int total;
    int num;
    int true_num;
    set<char> ans;
    int wrong;
} tmp;

vector<problem> pro;

bool cmp(problem a, problem b) {
    return a.wrong > b.wrong;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        tmp.id = i; tmp.wrong = 0;
        scanf("%d%d%d", &tmp.total, &tmp.num, &tmp.true_num);
        char c;
        tmp.ans.clear();
        for (int j = 0; j < tmp.true_num; j++) {
            scanf(" %c", &c);
            tmp.ans.insert(c);
            //printf("%c\n", c);
        }
        //printf("----\n");
        pro.push_back(tmp);
    }

    // for (int i = 0; i < m; i++) {
    //     for (auto it = pro[i].ans.begin(); it != pro[i].ans.end(); it++) {
    //         cout << *it << endl;
    //     }
    //     printf("-----\n");
    // }

    for (int i = 0; i < n; i++) {
        int score = 0;
        scanf("\n");
        for (int j = 0; j < m; j++) {
            if (j != 0) scanf(" ");
            int cnt;
            scanf("(%d", &cnt);
            //printf("%d\n", cnt);
            set<char> st;
            char c;
            for (int k = 0; k < cnt; k++) {
                scanf(" %c", &c);
                //cout << c << endl;
                st.insert(c);
            }
            //printf("!!\n");
            scanf(")");
            if (st == pro[j].ans) {
                score += pro[j].total;
                //printf("%d--yes\n", j);
            } else {
                pro[j].wrong++;
            }
        }
        //printf("-----\n");
        printf("%d\n", score);
    }

    sort(pro.begin(), pro.end(), cmp);
    if (pro[0].wrong == 0) {
        printf("Too simple\n");
    } else {
        printf("%d", pro[0].wrong);
        for (int i = 0; i < m; i++) {
            if (pro[i].wrong == pro[0].wrong) {
                printf(" %d", pro[i].id);
            }
        }
    }

    return 0;
}