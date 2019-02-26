#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct node {
    int poptime;//队首的人出队时间
    int endtime;//队尾的人结束时间
    queue<int> q;//当前窗口的排队队列
};

int main(){
    freopen("D:/in.txt", "r", stdin);
    int n, m, k, q;//n个窗口，每个窗口可排队m人，有k位顾客需要服务，求q个人的服务结束时间
    scanf("%d %d %d %d", &n, &m, &k, &q);
    vector<int> time(k+1), result(k+1);//time:需要操作的时间
    for (int i = 1; i <= k; i++) {//读入需要的服务时间,题目客人编号从1开始
        scanf("%d", &time[i]);
    }
    vector<node> window(n+1);//n个窗口
    vector<bool> sorry(k+1, false);

    int index = 1;//客人编号
    //前m*n个人按顺序排队
    for(int i = 1; i <= m; i++) {//每个窗口可排m人
        for (int j = 1; j <= n; j++) {//n个窗口
            if (index <= k) {
                window[j].q.push(time[index]);

                //判断之前的endtime是否超时并更新endtime
                if(window[j].endtime >= 60*(17-8)) {
                    sorry[index] = true;
                }
                window[j].endtime += time[index];

                if(i == 1) {//更新队首的人的出队时间
                    window[j].poptime = window[j].endtime;
                }

                result[index] = window[j].endtime;
                index++;
            }

        }
    }

    //黄线外等待的人
    while(index <= k) {
        int tempwindow = 1;
        int tempmin = window[1].poptime;
        for (int i = 2; i <= n; i++) {
            if (window[i].poptime < tempmin) {
                tempmin = window[i].poptime;
                tempwindow = i;
            }
        }
        window[tempwindow].q.pop();
        window[tempwindow].q.push(time[index]);
        window[tempwindow].poptime += window[tempwindow].q.front();
        if (window[tempwindow].endtime >= 60*(17-8)) {
            sorry[index] = true;
        }
        window[tempwindow].endtime += time[index];
        result[index] = window[tempwindow].endtime;
        index++;
    }

    //查询
    for (int i = 1; i <= q; i++) {
        int query, minute;
        scanf("%d", &query);
        minute = result[query];
        if (sorry[query] == true) {
            printf("Sorry\n");
        } else {
            printf("%02d:%02d\n", (minute+60*8)/60, (minute+60*8)%60);
        }
    }

    return 0;
}