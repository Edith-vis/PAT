#include <iostream>

using namespace std;
long a, b, c, d;

long GCD(long a, long b)
{ //求最大公约数
    long m = a % b;
    while (m)
    {
        a = b;
        b = m;
        m = a % b;
    }
    return b;
}

void func(long m, long n)
{ //将一个分数以规定形式输出 a分子 b分母
    int flag1 = 0, flag2 = 0, flag = 0;

    if (n == 0)
    { //分母为0
        cout << "Inf";
        return;
    }
    if (m == 0)
    { //分子为0
        cout << "0";
        return;
    }

    if (m < 0)
        flag1 = 1;
    if (n < 0)
        flag2 = 1;

    m = abs(m), n = abs(n);
    if (flag1 == 1 && flag2 == 1)
        flag = 0;
    else if (flag1 == 1 || flag2 == 1)
        flag = 1;

    if (m == n)
    {
        if (flag)
            cout << "(-1)";
        else
            cout << "-1";

        return;
    }

    long x = m % n, y = m / n;
    if (x==0){
        if(flag)
            printf("(-%ld)", y);
        else
            printf("%ld", y);

        return;
    } else {
        long t1 = m - y * n, t2 = n, t = GCD(t1, t2);
        t1 /= t, t2 /= t;
        if (flag){
            cout << "(-";
            if(y)
                printf("%ld %ld/%ld)", y, t1, t2);
            else
                printf("%ld/%ld)", t1, t2);
        } else {
            if (y) printf("%ld %ld/%ld", y, t1, t2);
            else printf("%ld/%ld", t1, t2);
        }
    }
    
}

void print()
{
    func(a, b);
    printf(" + ");
    func(c, d);
    printf(" = ");
    func(a * d + b * c, b * d);
    printf("\n");
    func(a, b);
    printf(" - ");
    func(c, d);
    printf(" = ");
    func(a * d - b * c, b * d);
    printf("\n");
    func(a, b);
    printf(" * ");
    func(c, d);
    printf(" = ");
    func(a * c, b * d);
    printf("\n");
    func(a, b);
    printf(" / ");
    func(c, d);
    printf(" = ");
    func(a * d, b * c);
    printf("\n");
}

int main()
{
    freopen("D:/in.txt", "r", stdin);
    scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
    print();
    return 0;

    return 0;
}