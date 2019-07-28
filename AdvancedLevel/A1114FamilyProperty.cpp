#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 10010;

int father[maxn];
bool visit[maxn];

int findFather(int id) {
    int x = id;
    while (id != father[id]) {
        id = father[id];
    }

    // while (x != father[x]) {
    //     int z = x;
    //     x = father[x];
    //     father[z] = id;
    // }
    return id;
}

void Union(int a, int b) {//保证一个集合的father是id最小的那个人
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa > fb)
        father[fa] = fb;
    else if (fa < fb)
        father[fb] = fa;
}

struct People {
    int id, fid, mid, numOfKids, num, area;
    int kids[10];
} people[maxn];//用father id标记family方便查找

struct Family {
    int id;
    int numOfPeople;
    double num, area;
    bool flag = false;//flag == true是指这个id上有家庭
} family[maxn];

bool cmp(Family a, Family b) {
    if (a.area != b.area) {
        return a.area > b.area;
    } else {
        return a.id < b.id;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    fill(visit, visit + maxn, false);

    for (int i = 0; i < maxn; i++) {
        father[i] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> people[i].id >> people[i].fid >> people[i].mid >> people[i].numOfKids;
        visit[people[i].id] = true;
        for (int j = 0; j < people[i].numOfKids; j++) {
            cin >> people[i].kids[j];
            Union(people[i].id, people[i].kids[j]);
            visit[people[i].kids[j]] = true;
        }
        cin >> people[i].num >> people[i].area;

        if (people[i].fid != -1) {
            Union(people[i].id, people[i].fid);
            visit[people[i].fid] = true;
        }
        if (people[i].mid != -1) {
            Union(people[i].id, people[i].mid);
            visit[people[i].mid] = true;
        }        
    }

    for (int i = 0; i < n; i++) {
        int id = findFather(people[i].id);
        family[id].id = id;
        family[id].flag = true;
        family[id].num += people[i].num;
        family[id].area += people[i].area;
        family[id].numOfPeople = 0;
    }

    int cnt = 0;
    for (int i = 0; i < maxn; i++)
    {
        if (visit[i] == true) {
            family[findFather(i)].numOfPeople++;
        }
        if (family[i].flag == true) {
            cnt++;
        }
    }

    for (int i = 0; i < maxn; i++) {
        if (family[i].flag == true) {
            family[i].area = (double)(family[i].area*1.0 / family[i].numOfPeople);
            family[i].num = (double)(family[i].num*1.0 / family[i].numOfPeople);
        }
    }

    sort(family, family + maxn, cmp);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%04d %d %.3f %.3f\n", family[i].id, family[i].numOfPeople, family[i].num, family[i].area);
    }

    return 0;
}