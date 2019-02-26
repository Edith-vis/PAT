#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 99999999;

struct node {
    double price, distance;
};

bool compare (node a, node b) {
    return a.distance < b.distance;
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    double cmax, distance, davg;
    int n;
    scanf ("%lf %lf %lf %d", &cmax, &distance, &davg, &n);

    vector<node> station(n+1);
    station[0] = {0.0, distance};//目的地结点
    for (int i = 1; i <= n; i++)
    {   
        scanf("%lf %lf", &station[i].price, &station[i].distance);
    }
    sort(station.begin(), station.end(), compare);//按距离远近排序 距离近的在前

    //贪心法
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalprice = 0.0, leftdis = 0.0;
    //nowdis表示当前所在的距离， maxdis是能够到达的最⼤距离，nowprice是当前的站点的价格， totalPrice是总的价格。 leftdis是当前油箱内剩余的油还可以走的距离
    if (station[0].distance != 0) {//如果起点没有加油站
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = station[0].price;
    }

    while (nowdis < distance) {
        maxdis = nowdis + cmax*davg;//估算可能走到的最远距离是在邮箱满的情况下用完所有油
        double minPriceDis = 0, minPrice = inf;
        int flag = 0;

        for (int i = 1; i <= n && station[i].distance <= maxdis; i++) {//在我可以到达的加油站范围内找
            if (station[i].distance <= nowdis) {//这个加油站已经在过去的路上了
                continue;
            }
            if (station[i].price < nowprice) {//距离我最近的比我便宜的可到达的加油站
                //加油到刚好能到达那个加油站的距离的油，然后去那个更低价格的加油站
                totalprice += (station[i].distance - nowdis - leftdis) / davg * nowprice;
                //更新当前状态为到达下一个站点的状态
                nowprice = station[i].price;
                nowdis = station[i].distance;
                leftdis = 0.0;
                flag = 1;
                break;
            }
            if (station[i].price < minPrice) {//此加油站价格不比我便宜，记录下价格最低的加油站
                minPrice = station[i].price;
                minPriceDis = station[i].distance;
            }
        } 

        if (flag == 0 && minPrice != inf) {
            //找尽可能低的油价的加油站，在当前加油站加满油之后过去。
            totalprice += nowprice*(cmax - leftdis/davg);
            //更新状态
            leftdis = cmax*davg - (minPriceDis - nowdis);
            nowdis = minPriceDis;
            nowprice = minPrice;
        }

        if (flag == 0 && minPrice == inf) {
            nowdis += cmax*davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }

    printf("%.2f", totalprice);

    return 0;
}