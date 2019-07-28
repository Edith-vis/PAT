#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10000;
bool wrongThing[maxn];

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    fill(wrongThing, wrongThing + maxn, false);
    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        wrongThing[id] = true;
    }

    int totalChild = 0, totalThing = 0;
    for (int i = 0; i < n; i++) {
        string name;
        int num, thing;
        cin >> name >> num;
        vector<int> w;
        for (int j = 0; j < num; j++) {
            cin >> thing;
            if (wrongThing[thing] == true) {
                w.push_back(thing);
            }
        }
        if (w.size() == 0) continue;
        totalChild++;
        totalThing += w.size();
        cout << name << ":";
        for (int j = 0; j < w.size(); j++) {
            printf(" %04d", w[j]);
        }
        printf("\n");
    }
    printf("%d %d\n", totalChild, totalThing);

    return 0;
}