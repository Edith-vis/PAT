#include <iostream>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    //int	4 个字节 32位 -2147483648 到 2147483647  10的10次方
    int a, b, d;
    cin >> a >> b >> d;
    int result = a + b;
    if (!result) {
        std::cout << 0;
        return 0;
    }

    //十进制转d进制
    int s[100];
    int i = 0;
    while(result){
        s[i] = result % d;
        result /= d;
        i++;
    }
    i--;

    for (int j = i; j >= 0; j--) {
        cout << s[j];
    }
        return 0;
}