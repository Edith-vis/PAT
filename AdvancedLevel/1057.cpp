#include <iostream>
#include <stack>
using namespace std;

//用于树状数组
//Lowbit函数:返回参数转为二进制后,最后一个1的位置所代表的数值
#define lowbit(i) ((i) & (-i))
const int maxn = 100001;

int c[maxn];
stack<int> s;

void update(int x, int v) {
    for (int i = x; i < maxn; i += lowbit(i)) {
        c[i] += v;
    }
}

int sum(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void peekMedian() {//二分查找
    int left = 1, right = maxn, mid;
    int k = (s.size()+1)/2;
    while (left < right) {
        mid = (left+right)/2;
        if (sum(mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    printf("%d\n", left);
}



int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    char str[11];
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        if (str[1] == 'u') {//push
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if (str[1] == 'o') {//pop
            if (s.empty() != true) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {//peekMedian
            if (s.empty() != true) {
                peekMedian();
            } else {
                printf("Invalid\n");
            }
        }
    }


    return 0;
}