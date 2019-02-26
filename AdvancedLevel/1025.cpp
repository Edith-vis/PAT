#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
    long long id;
    int score, finrank, localnum, localrank;
};

bool compare(student a, student b) {
    return a.score != b.score ? a.score > b.score : a.id < b.id;
    //分数高的在前，id号小的在前
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n; //n:考场数量 
    scanf("%d", &n);
    vector<student> fin;
    int m;
    for (int i = 1; i <= n; i++) {//考场号从1到n
        //int m;//考场内的考生数量
        scanf("%d", &m);
        vector<student> local(m);
        for (int j = 0; j < m; j++) {//录入考生信息
            scanf("%lld %d", &local[j].id, &local[j].score);
            local[j].localnum = i;//考场号为i
        }
        sort(local.begin(), local.end(), compare);

        local[0].localrank = 1;
        fin.push_back(local[0]);

        for (int j = 1; j < m; j++) {
            local[j].localrank = (local[j].score == local[j-1].score) ? local[j-1].localrank : (j+1);
            fin.push_back(local[j]);
        }
    }

    sort(fin.begin(), fin.end(), compare);
    fin[0].finrank = 1;
    for (int i = 1; i < fin.size(); i++) {
        fin[i].finrank = (fin[i].score == fin[i-1].score) ? fin[i-1].finrank : (i+1);
    }

    printf("%d\n", fin.size());
    for (int i = 0; i < fin.size(); i++) {
        printf("%013lld %d %d %d\n", fin[i].id, fin[i].finrank, fin[i].localnum, fin[i].localrank);
    }
    return 0;
}