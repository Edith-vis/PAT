#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct node {
    int id;
    char name[10];
    int score;
};

vector<node> student;

int c;

bool compare(node a, node b) {
    if (c==1) {
        return a.id < b.id;
    } else if (c==2) {
        return strcmp(a.name, b.name) == 0 ? a.id < b.id : strcmp(a.name, b.name) < 0;
    } else {
        return a.score != b.score ? a.score < b.score : a.id < b.id;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    int n;
    scanf("%d %d\n", &n, &c);
    student.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d", &student[i].id, &student[i].name, &student[i].score);
    }

    sort(student.begin(), student.end(), compare);

    for (int i = 0; i < student.size(); i++) {
        printf("%06d %s %d\n", student[i].id, student[i].name, student[i].score);
    }

    return 0;
}