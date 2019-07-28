#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

struct student {
    string id;
    int gp = -1, gm = -1, gf = -1;
    int total;
    bool flag;
}stu[100010];
int cnt = 0;
map<string, int> idTOid;

int getID(string id) {
    if (idTOid.find(id) == idTOid.end()) {
        idTOid[id] = cnt;
        return cnt++;
    } else {
        return idTOid.find(id)->second;
    }
}

bool cmp(student a, student b) {
    if (a.flag != b.flag) {
        return a.flag > b.flag;
    } else if (a.total != b.total) {
        return a.total > b.total;
    } else {
        return a.id < b.id;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int p, m, n;
    cin >> p >> m >> n;
    while (p--) {
        string id;
        int score;
        cin >> id >> score;
        int sid = getID(id);
        stu[sid].gp = score;
        stu[sid].id = id;
    }

    while (m--) {
        string id;
        int score;
        cin >> id >> score;
        int sid = getID(id);
        stu[sid].gm = score;
        stu[sid].id = id;
    }

    while (n--) {
        string id;
        int score;
        cin >> id >> score;
        int sid = getID(id);
        stu[sid].gf = score;
        stu[sid].id = id;
    }

    for (int i = 0; i < cnt; i++) {
        if (stu[i].gp < 200) {
            stu[i].flag = false;
        } else {
            stu[i].flag = true;
            stu[i].total = (stu[i].gm > stu[i].gf) ? (int)round(stu[i].gm * 0.4 + stu[i].gf * 0.6) : stu[i].gf;
            if (stu[i].total < 60) {
                stu[i].flag = false;
            }
        }
    }

    sort(stu, stu + cnt, cmp);

    for (int i = 0; i < cnt; i++) {
        if (stu[i].flag == false) {
            return 0;
        }
        cout << stu[i].id  << " " << stu[i].gp << " " << stu[i].gm << " " << stu[i].gf << " " << stu[i].total << endl;
    }

    return 0;
}