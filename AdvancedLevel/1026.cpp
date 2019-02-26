#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct person {
    //要打印到达时间 开始时间 使用时间
    int arrive, start, time;//以s计:从00:00:00
    bool vip;
} tempperson;

struct tablenode {
    int end = 8*60*60;//8点
    int num;//该桌子serve的player对数
    bool vip;//是否是vip专用桌
};

bool compare1 (person a, person b) {//到来时间先后排序
    return a.arrive < b.arrive;
}

bool compare2 (person a, person b) {//开始时间先后排序
    return a.start < b.start;
}

vector<person> player;
vector<tablenode> table;

void assignable(int personid, int tableid) {
    if (player[personid].arrive <= table[tableid].end) {//到达时桌子未空
        player[personid].start = table[tableid].end;
    } else {//到达时刚好有桌子
        player[personid].start = player[personid].arrive;
    }
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
}

int findNextVIP(int vipid) {
    vipid++;
    while (vipid < player.size() && player[vipid].vip != true) vipid++;
    return vipid;
}


int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;//待服务的顾客
    cin >> n;
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, temptime, tag;
        scanf("%d:%d:%d %d %d\n", &hh, &mm, &ss, &temptime, &tag);
        tempperson.arrive = hh*60*60 + mm*60 + ss;
        if (tempperson.arrive >= 21*60*60) continue;
        tempperson.time = temptime > 120 ? 120*60 : temptime*60;
        tempperson.vip = tag == 1 ? true : false;
        tempperson.start = 21*60*60;//21点
        player.push_back(tempperson);
    }

    int k, m;//k:桌子总数 m:vip桌子数
    scanf("%d %d\n", &k, &m);
    table.resize(k+1);//桌子编号从1开始
    int viptable;
    for (int i = 0; i < m; i++) {
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    sort(player.begin(), player.end(), compare1);//按到来时间先后排序

    int i = 0;
    int vipid = -1;
    vipid = findNextVIP(vipid);

    while (i < player.size()) {
        int index = -1;//当前最先结束的桌子编号
        int minEndTime = 999999999;
        for (int j = 1; j <= k; j++) {
            if (table[j].end < minEndTime) {
                minEndTime = table[j].end;
                index = j;
            }
        }

        if (table[index].end >= 21*60*60) break;//以后都超出服务时间
        if (player[i].vip == true && i < vipid) {//这是一个已经被处理过了的vip用户
            i++;
            continue;
        }

        if (table[index].vip == true) {//最先空闲的是vip桌
            if (player[i].vip == true) {//当前队首是vip客户
                assignable(i, index);//把index号桌给i号顾客使用
                if (vipid == i) {//???
                    vipid = findNextVIP(vipid);
                }
                i++;
            } else {//当前队首不是vip顾客
                if (vipid < player.size() && player[vipid].arrive <= table[index].end) {//队伍中有vip在等候
                    assignable(vipid, index);
                    vipid = findNextVIP(vipid);
                } else {//队伍中没有vip在等待，将桌子分配给当前队首客户
                    assignable(i, index);
                    i++;
                }
            }
        } else {//最先空闲的不是vip桌
            if (player[i].vip == false) {//当前队首不是vip客户
                assignable(i, index);
                i++;
            } else {//当前队首是vip客户
                int vipindex = -1;
                int minVipEndTime = 999999999;
                //寻找空闲的vip桌子
                for (int j = 1; j <= k; j++) {//桌子编号从1开始
                    if (table[j].vip == true && table[j].end < minVipEndTime) {
                        vipindex = j;
                        minVipEndTime = table[j].end;
                    }
                }
                if (vipindex != -1 && player[i].arrive >= table[vipindex].end) {
                    assignable(i, vipindex);//当前的vip顾客去空闲的vip桌
                    if (vipid == i) {//???
                        vipid = findNextVIP(vipid);
                    }
                    i++;
                } else {//没找到当前空闲的vip桌子 
                    assignable(i, index);//当前的vip客户在当前的普通桌子玩球
                    if (vipid == i) {//???
                        vipid = findNextVIP(vipid);
                    }
                    i++;
                }
            }

        }
    }

    sort(player.begin(), player.end(), compare2);

    for (int i = 0; i < player.size() && player[i].start<21*3600; i++) {
        printf("%02d:%02d:%02d ", player[i].arrive/3600, player[i].arrive%3600/60, player[i].arrive%60);
        printf("%02d:%02d:%02d ", player[i].start/3600, player[i].start%3600/60, player[i].start%60);
        printf("%.0f\n", round((player[i].start - player[i].arrive)/60.0));
    }

    for (int i = 1; i <= k; i++) {
        if (i != 1) cout << " ";
        cout << table[i].num;
    }

    return 0;
}