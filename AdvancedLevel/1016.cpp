#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int rate[25];

struct node {
    string name;
    int month, day, hour, minute;
    int status;//online-1 offline-0
    int time;//从xx:00:00:00开始
};

//排序
bool compare(node a, node b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}

//计算费⽤从00:00:00到dd:hh:mm计算可以避免跨天的问题，⽐如
//01:12:00到02:02:00,不考虑月份
double billFromZero(node call) {
    double result = rate[call.hour]*call.minute + rate[24]*60*call.day;
    for (int i = 0; i < call.hour; i++) {
        result += 60*rate[i];
    }
    return result/100.0;
}
int main() {
    freopen("D:/in.txt", "r", stdin);

    //读取rate
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    //读取n条记录
    int n;
    scanf("%d", &n);
    vector<node> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = temp == "on-line" ? 1 : 0;
        data[i].time = data[i].day*24*60 + data[i].hour*60 + data[i].minute;
    }
    //排序:按name和time
    sort(data.begin(), data.end(), compare);//<algorithm>
    map<string, vector<node>> customer;
    //过滤无用信息:status不匹配
    for (int i = 1; i < n; i++) {
        if (data[i-1].name == data[i].name && data[i-1].status == 1 && data[i].status == 0) {
            customer[data[i-1].name].push_back(data[i-1]);
            customer[data[i].name].push_back(data[i]);
        }
    }

    for (auto it : customer) {
        vector<node> temp = it.second;//存放该客户的data的vector
        cout << it.first;
        printf(" %02d\n", temp[0].month);//打印第一行：客户名字和月份
        double total = 0.0;
        for (int i = 1; i < temp.size(); i+=2) {
            double t = billFromZero(temp[i]) - billFromZero(temp[i-1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i-1].day, temp[i-1].hour, temp[i-1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time-temp[i-1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}