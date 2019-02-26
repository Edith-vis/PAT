#include <iostream>
#include <cctype>//判断字符类型需要的头文件

using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'}; //1 0 X 9 8 7 6 5 4 3 2
    int flag = 0;
    for (int i = 0; i < n; i++) {
        string num;
        cin >> num;
        int total = 0;
        for (int i = 0; i < 17; i++) {
            if (!isdigit(num[i])){
                flag = 1;
                break;
            }
            total += (num[i] - '0') * weight[i];
        }
        total %= 11;
        if (M[total] != num[17]) {
            flag = 1;
        }
        if(flag) {
            cout << num << endl;
        } 
    }

    if(flag == 0)
        cout << "All passed";

    return 0;
}