#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

char name[400001][4+1];
vector<int> course[2501];

bool compare(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;//n个学生，k门课
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }

    for (int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), compare);
        for (int j = 0; j < course[i].size(); j++) {
            printf("%s\n", name[course[i][j]]);
        }
    }

    return 0;
}