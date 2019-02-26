#include <iostream>
#include <algorithm>
using namespace std;

int compare1(char a, char b) {
    return a > b; //降序
}

int compare2(char a, char b) {
    return a < b; //升序
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    string n;
    cin >> n;

    //string &insert(int p0, int n, char c);//在p0处插入n个字符c
    n.insert(0, 4 - n.length(), '0');
    do {
        string a = n, b = n;
        sort(a.begin(), a.end(), compare1);
        sort(b.begin(), b.end(), compare2);
        //stoi()将string转化为int  string to int
        int result = stoi(a) - stoi(b);
        n = to_string(result);
        n.insert(0, 4 - n.length(), '0');
        cout << a << " - " << b << " = " << n << endl;
    } while (n != "6174" && n != "0000");

    return 0;
}