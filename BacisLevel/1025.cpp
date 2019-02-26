#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int first, n, k;
    cin >> first >> n >> k;
    //Address Data Next
    int temp;
    int data[100000], next[100000];
    //输入乱序的n个节点
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];  
        // temp==Address data[temp]==Data next[temp]==Next
    }

    //找到正确的顺序并存在list里
    int list[100000];
    int sum = 0;//不一定所有的节点都是有用的，加个计数器
    //序后的链的大小，不一定等于N，因为可能存在废点不在链上
    while (first != -1) { //-1是链表的结尾
        list[sum] = first;
        first = next[first];
        sum++;
    }
    //list存放的是正确的顺序的节点地址
    
    //在list里翻转k个
    for (int i = 0; i < sum - sum % k; i += k) {
        reverse(list + i, list + i + k);
    } //步长为k
    
    //打印
    //最后一个节点是不对的 e.g 68237 6 00000 应该为-1
    //因为最后一个节点的next不在list[i+1]里
    for (int i = 0; i < sum - 1; i++) {
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    }
    printf("%05d %d -1\n", list[sum - 1], data[list[sum - 1]]);
    return 0;
}