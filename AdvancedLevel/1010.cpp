#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//将给定进制(radix)的数(n)转换为10进制 sum
long long convert(string n, long long radix) {
    long long sum = 0;
    int temp = 0, index = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {//反向迭代器
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10; //string转为10进制数
        sum += temp*pow(radix, index++);
    }
    return sum;
}

//使用二分法找到使n=num的n的进制
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;//进制最小为n的单位上的最大字母代表的数
    long long high = max(num, low);

    //二分法
    while (low <= high)
    {
        long long mid = (high - low) / 2 + low;
        long long temp = convert(n, mid);
        if (temp == num) {
            return mid;
        } else if (temp < 0 || temp > num) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    freopen("D:/in.txt", "r", stdin);
    string n1, n2;
    long long tag, radix, result_radix = 0;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        cout << "Impossible";
    }
    return 0;
}