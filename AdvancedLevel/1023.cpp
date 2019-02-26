#include <iostream>
#include <cstring>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);

    char num[21+1];//'\n'和进位
    scanf("%s", &num);

    int flag = 0;//进位标志
    int book[10]={0};// 0123456789
    int len = strlen(num);//<cstring>
    for (int i = len - 1; i >= 0; i--)//从最低位开始计算
    {
        int temp = num[i] - '0';//字符转数字
        book[temp]++;
        //更新二倍之后的数
        temp = 2*temp + flag;
        flag = 0;//先清空进位标志
        if (temp >= 10) {
            temp = temp - 10;
            flag = 1;
        }
        num[i] = (temp + '0');//数字转字符
        book[temp]--;
    }//最后一个进位仍保留在flag内
    
    int flag1 = 0;//判断book是否平衡
    for (int i = 0; i < 10; i++) {
        if (book[i] != 0) {
            flag1 = 1;
            break;
        }
    }

    printf("%s\n", (flag == 1 || flag1 == 1) ? "No" : "Yes");
    if (flag == 1) {
        cout << "1";
    }
    printf("%s", num);

    return 0;
}