#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int id, best;//best:最好排名的下标
    int score[4], rank[4];
}stu[2000];

int exist[1000000], flag = -1;//全局变量

bool compare (node a, node b) {
    return a.score[flag] > b.score[flag];//大的往前放
}

int main(){
    freopen("D:/in.txt", "r", stdin);
    int n, m;//n:学生个数
    cin >> n >> m;
    //输入学生结构体数组
    for (int i = 0; i < n; i++) {
        cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;//四舍五入
    }
    //按不同科目排序，并填充rank列
    for (flag = 0; flag < 4; flag++){
        sort(stu, stu + n, compare);
        stu[0].rank[flag] = 1;
        for (int i = 1; i < n; i++){
            stu[i].rank[flag] = i+1;
            if (stu[i].score[flag] == stu[i-1].score[flag]) {//并列则为1,1,3,4,5
                stu[i].rank[flag] = stu[i-1].rank[flag];
            }
        }
    }

    //填充exist数组，使下标对应的内容为stu的下标
    //并填充stu的best
    for (int i = 0; i < n; i++) {
        exist[stu[i].id] = i+1;//排除0的干扰
        stu[i].best = 0;
        int min = stu[i].rank[0];
        for (int j = 1; j <= 3; j++) {
            if (min > stu[i].rank[j]) {
                min = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }

    char c[5] = {"ACME"};
    //查询并输出
    for (int i = 0; i < m; i++) {
        int id;
        cin >> id;
        int t = exist[id];
        int best = stu[t-1].best;
        if (t) {
            cout << stu[t-1].rank[best] << " " << c[best] << endl;
        } else {
            cout << "N/A" << endl;
        }
    }
    return 0;
}