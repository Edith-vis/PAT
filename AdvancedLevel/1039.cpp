#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getID(char *name) {
    int id = 0;
    for (int i = 0; i < 3; i++) {
        id = id*26 + (name[i] - 'A');
    }
    id = id*10 + (name[3] - '0');
    return id;
}

const int maxn = 26*26*26*10 + 10;
vector<int> v[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);

    char name[5];
    int id;

    int n, k;
    scanf("%d %d", &n, &k);//n个学生k门课
    int no, num;//no:课程编号 num:选课学生人数
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &no, &num);
        for (int j = 0; j < num; j++) {
            scanf("%s", name);
            id = getID(name);
            v[id].push_back(no);
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", name);
        id = getID(name);
        sort(v[id].begin(), v[id].end());
        printf("%s %d", name, v[id].size());
        for (int j = 0; j < v[id].size(); j++) {
            printf(" %d", v[id][j]);
        }
        printf("\n");
    }


    return 0;
}