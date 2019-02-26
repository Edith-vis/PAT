#include <iostream>
#include <stack>
using namespace std;

//用于树状数组
//Lowbit函数:返回参数转为二进制后,最后一个1的位置所代表的数值
#define lowbit(i) ((i) & (-i))
const int maxn = 100000;

int c[maxn];
stack<int> s;

void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += x;
    }
}



int main() {
    freopen("D:/in.txt", "r", stdin);


    return 0;
}