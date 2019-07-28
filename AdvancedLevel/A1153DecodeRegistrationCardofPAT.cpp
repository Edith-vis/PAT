#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct stu {
    string id;
    int site;
    int date;
    int score;
} temp;

struct site {
    int site;
    int num;
} tempS;

vector<stu> levelA, levelB, levelT;
vector<stu> Hash[1000];
vector<stu> all;

bool cmp(stu a, stu b) {
    if (a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}

bool cmpSite(site a, site b) {
    if (a.num != b.num) return a.num > b.num;
    else return a.site < b.site;
}

int n, m;
int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d%d", &n, &m);

    string reg; int score;
    for (int i = 0; i < n; i++) {
        cin >> reg >> score;
        temp.id = reg;
        temp.site = stoi(reg.substr(1, 3));
        temp.date = stoi(reg.substr(4, 6));
        temp.score = score;

        all.push_back(temp);

        if (reg[0] == 'T') levelT.push_back(temp);
        else if (reg[0] == 'A') levelA.push_back(temp);
        else if (reg[0] == 'B') levelB.push_back(temp);

        Hash[temp.site].push_back(temp);
    }

    sort(levelA.begin(), levelA.end(), cmp);
    sort(levelB.begin(), levelB.end(), cmp);
    sort(levelT.begin(), levelT.end(), cmp);

    int type; string query;
    for (int i = 1; i <= m; i++) {
        cin >> type >> query;
        printf("Case %d: %d ", i, type);
        cout << query << endl;
        
        int flag = true;
        if (type == 1) {
            if (query == "A") {
                if (!levelA.empty())
                    for (int j = 0; j < levelA.size(); j++) {
                        flag = false;
                        cout << levelA[j].id << " " << levelA[j].score << endl;
                    }
            } else if (query == "B") {
                if (!levelB.empty())
                    for (int j = 0; j < levelB.size(); j++) {
                        flag = false;
                        cout << levelB[j].id << " " << levelB[j].score << endl;
                    }
            } else if (query == "T") {
                if (!levelT.empty())
                    for (int j = 0; j < levelT.size(); j++) {
                        flag = false;
                        cout << levelT[j].id << " " << levelT[j].score << endl;
                    }
            }
        } else if (type == 2) {
            if (Hash[stoi(query)].size() != 0) {
                flag = false;
                int total = 0;
                printf("%d", Hash[stoi(query)].size());
                for (int j = 0; j < Hash[stoi(query)].size(); j++) {
                    total += Hash[stoi(query)][j].score;
                }
                printf(" %d\n", total);
            }
        } else if (type == 3) {
            map<int, int> m;
            for (int j = 0; j < n; j++) {
                if (all[j].date == stoi(query)) {
                    m[all[j].site]++;
                }
            }
            vector<site> v;
            for (auto it = m.begin(); it != m.end(); it++) {
                tempS.site = it->first;
                tempS.num = it->second;
                v.push_back(tempS);
            }
            if (!v.empty()) {
                sort(v.begin(), v.end(), cmpSite);
                flag = false;
                for (int j = 0; j < v.size(); j++) {
                    printf("%03d %d\n", v[j].site, v[j].num);
                }
            }
        }
        
        if (flag == true) {
            printf("NA\n");
        }
    }

    return 0;
}