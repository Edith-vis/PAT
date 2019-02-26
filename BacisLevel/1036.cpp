//   t = n / 2 + n % 2; n/2的四舍五入
#include <iostream>
using namespace std;

int main()
{
    freopen("D:/in.txt", "r", stdin);
    int n;
    char a;
    cin >> n >> a;
    //第一行
    for (int i = 0; i < n; i++)
    {
        cout << a;
    }
    cout << endl;

    for (int i = 1; i < (n / 2 + n % 2) - 1; i++)
    {
        cout << a;
        for (int j = 1; j < n - 1; j++)
        {
            cout << " ";
        }
        cout << a << endl;
    }
    //最后一行
    for (int i = 0; i < n; i++)
    {
        cout << a;
    }

    return 0;
}