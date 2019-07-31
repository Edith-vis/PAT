#include <iostream>
#include <set>
using namespace std;

const int maxn = 50010;
int book[maxn] = {0};

struct node {
    int id;
    int cnt;

    node (int _id, int _cnt) {
        id = _id;
        cnt = _cnt;
    }

    bool operator< (const node & a) const {
        if (cnt != a.cnt) {
            return cnt > a.cnt;
        } else {
            return id < a.id;
        }
    }
};

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n, k;
    cin >> n >> k;

    set<node> s;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (i == 0) {
            s.insert(node{num, 1});
            book[num]++;
            continue;
        }
        printf("%d:", num);
        int cnt = 0;
        for (auto it = s.begin(); it != s.end() && cnt < k; it++, cnt++)
        {
            printf(" %d", it->id);
        }
        printf("\n");

        auto it = s.find(node{num, book[num]});
        if (it != s.end())
            s.erase(it);
        book[num]++;
        s.insert(node{num, book[num]});
    }

    return 0;
}