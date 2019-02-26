#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct node {
    char name[9];
    int age;
    int worth;
};

bool compare(node a, node b) {
    if (a.worth != b.worth) {
        return a.worth > b.worth;
    } else if (a.age != b.age) {
        return a.age < b.age;
    } else {
        return strcmp(a.name, b.name) < 0;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;//n个人k个查询
    scanf("%d %d", &n, &k);
    vector<node> people(n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", &people[i].name, &people[i].age, &people[i].worth);
    }
    sort(people.begin(), people.end(), compare);

    vector<int> book(201, 0);//最多两百个年龄
    vector<node> v;
    //因为M (≤100) - the maximum number of outputs
    for (int i = 0; i < n; i++) {
        //m最大为100
        if (book[people[i].age] < 100) {
            v.push_back(people[i]);
            book[people[i].age]++;
        }
    }

    //查询
    int m, min, max;
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &m, &min, &max);
        vector<node> t;
        for (int j = 0; j < v.size(); j++) {
            if (v[j].age >= min && v[j].age <= max) {
                t.push_back(v[j]);
            }
        }
        if (i != 0) {
            printf("\n");
        }
        printf("Case #%d:", i+1);
        int flag = 0;
        for (int j = 0; j < t.size() && j < m; j++) {
            printf("\n%s %d %d", t[j].name, t[j].age, t[j].worth);
            flag = 1;
        }
        if (flag == 0) {
            printf("\nNone");
        }
    }
    return 0;
}