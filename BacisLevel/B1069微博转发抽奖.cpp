#include <iostream>
#include <map>
using namespace std;

#define maxm 1010
string name[maxm];
map<string, int> order;

string rightP[maxm];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int m, n, s;
    scanf("%d%d%d", &m, &n, &s);

    string str;
    for (int i = 1; i <= m; i++) {
        cin >> str;
        name[i] = str;
    }

    if (s > m) {
        printf("Keep going...\n");
        return 0;
    }

    int num = 0;
    for (int i = s; i <= m; i += n) {
        while (order.find(name[i]) != order.end()) {
            i++;
        }
        rightP[num++] = name[i];
        order[name[i]]++;
    }

    //printf("%d", q);
    
    for (int i = 0; i < num; i++) {
        cout << rightP[i] << endl;
    }

    return 0;
}