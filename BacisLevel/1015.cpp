#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int num, mora, talent;//准考证号，德分，才分
};

int compare(struct node a, struct node b)
{
    if ((a.mora + a.talent) != (b.mora + b.talent))
        return (a.mora + a.talent) > (b.mora + b.talent); //总分降序
    else if (a.mora != b.mora)
        return a.mora > b.mora;  //德分降序
    else
        return a.num < b.num;   //准考证号升序
}

int main(){
    freopen("D:/in.txt", "r", stdin); //输入重定向
    int n, low, high; //考生总数，录取最低分数线，优先录取线
    scanf("%d %d %d", &n, &low, &high);
    vector<node> v[4]; //四类被录取的考生
    node temp;
    int total = n;//录取的考生总数
    //输入分类
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &temp.num, &temp.mora, &temp.talent);
        if (temp.mora < low || temp.talent < low) {
            total--; //不录取
        } else if (temp.mora >= high && temp.talent >= high) {
            v[0].push_back(temp);  //第一类
        } else if (temp.mora >= high && temp.talent < high) {
            v[1].push_back(temp); //第二类
        } else if (temp.mora < high && temp.talent < high && temp.mora >= temp.talent) {
            v[2].push_back(temp); //第三类
        } else {
            v[3].push_back(temp);
        }
    }

    //输出
    printf("%d\n", total);
    for (int i = 0; i < 4; i++) {
        sort(v[i].begin(), v[i].end(), compare);
        for (int j = 0; j < v[i].size(); j++) {
            printf("%d %d %d\n", v[i][j].num, v[i][j].mora, v[i][j].talent);
        }
    }

        return 0;
}



