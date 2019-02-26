#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
    int come;//达到时间s 距00:00
    int time;//处理时间s
}tempcustomer;

bool compare(node a, node b) {
    return a.come < b.come;
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;//n个顾客，k个窗口
    scanf("%d %d", &n, &k);

    //读入顾客信息
    vector<node> customer;//不一定是n个，超过17:00的客户不处理
    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int come = hh*60*60 + mm*60 + ss;
        if (come > 17*60*60) {//17:00以后 不处理
            continue;
        }
        tempcustomer = {come, time*60};
        customer.push_back(tempcustomer);
    }
    //排序
    sort(customer.begin(), customer.end(), compare);

    vector<int> window(k, 8*60*60);//window数组存储每个窗口的结束时间
    int result = 0;//总等待时间 
    for (int i = 0; i < customer.size(); i++) {
        int minindex = 0;
        int minfinish = window[0];
        //找到最早处理完的窗口
        for (int j = 1; j < k; j++) {//k:窗口数量
            if (window[j] < minfinish) {
                minindex = j;
                minfinish = window[j];
            }
        }
        if (window[minindex] <= customer[i].come) {//如果i到之前已经处理完前一个人
            window[minindex] = customer[i].come + customer[i].time;    
        } else {
            result += window[minindex] - customer[i].come;//等待时间增加
            window[minindex] += customer[i].time;
        }
    }

    if (customer.size()==0) {
        printf("0.0");
    } else {
        printf("%.1f", result/60.0/customer.size());
    }

    return 0;
}