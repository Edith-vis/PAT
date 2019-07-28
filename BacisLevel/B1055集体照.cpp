#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct people {
    char name[10];
    int high;
} tmp;

bool cmp(people a, people b) {
    if (a.high != b.high) return a.high > b.high;
    else return strcmp(a.name, b.name) < 0;
}

vector<people> stu;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    int m = n / k;//每排人数
    for (int i = 0; i < n; i++) {
        scanf("%s %d", &tmp.name, &tmp.high);
        stu.push_back(tmp);
    }
    sort(stu.begin(), stu.end(), cmp);

    int remain = n % k;
    int p = 0;
    for (int i = 0; i < k; i++) {
        int num = m;
        if (i == 0) {
            num += remain;
        }
        string name[10000];
        int middle = num / 2;
        name[middle] = stu[p++].name;
        int j = 1;
        while (j <= middle) {
            if (middle - j >= 0) name[middle - j] = stu[p++].name;
            if (middle + j < num) name[middle + j] = stu[p++].name;
            j++;
        }

        for (int j = 0; j < num; j++) {
            if (j != 0) printf(" ");
            cout << name[j];
        }
        printf("\n");
    }

    return 0;
}