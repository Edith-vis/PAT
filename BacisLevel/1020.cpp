#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct mooncake{
    float mount, price, unit; //数量、总价、单价
};

int compare(struct mooncake a, struct mooncake b) {
    return a.unit > b.unit; //单价降序
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, need;
    cin >> n >> need;
    //初始化size,但每个元素值为默认值
    //vector<int> abc(10);    //初始化了10个默认值为0的元素
    vector<mooncake> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].mount;
    for (int i = 0; i < n; i++)
        cin >> v[i].price;
    for (int i = 0; i < n; i++)
        v[i].unit = v[i].price / v[i].mount;
    sort(v.begin(), v.end(), compare);

    float result = 0.0;
    for (int i = 0; i < n; i++){
        if (v[i].mount <= need) {
            need -= v[i].mount;
            result += v[i].price;
        } else {
            result += need * v[i].unit;
            break;
        }
    }

    printf("%.2f", result);

    return 0;
}