#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int weight;
    int index;//按照排名后的顺序的老鼠的下标
    int rank;//最终要输出的老鼠的排名
    int index0;//排名前老鼠的下标
};

bool compare (node a, node b) {
    return a.index0 < b.index0;
    //输出按初始玩耍编号
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int np, ng;
    scanf("%d %d", &np, &ng);

    vector<int> v(np);
    for (int i = 0; i < np; i++) {
        scanf("%d", &v[i]);
    }

    vector<node> w(np);
    int num;
    for (int i = 0; i < np; i++) {
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
        //第一个程序员的初始顺序是6，他的老鼠是第6个老鼠
    }

    queue<node> q;
    for (int i = 0; i < np; i++) {
        q.push(w[i]);
    }

    while (q.empty() != true) {
        int size = q.size();
        if (size == 1) {//找到了最终赢家
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }

        //分组
        int group = size / ng;
        if (size % ng != 0) {
            group += 1;
        }

        //找每组的赢家，并把组内其他输家的rank标为group+1
        //此时，本轮的赢家的rank也为group+1，但到了下一轮就会被更新
        node maxnode;
        int maxn = -1;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if (temp.weight > maxn) {
                maxn = temp.weight;
                maxnode = temp;
            }
            if (cnt == ng || i == size-1) {//本轮的赢家push进队列继续比较
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }

    sort(w.begin(), w.end(), compare);
    for (int i = 0; i < np; i++) {
        if (i != 0) printf(" ");
        printf("%d", w[i].rank);
    }


    return 0;
}