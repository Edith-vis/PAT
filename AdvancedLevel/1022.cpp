#include <iostream>
#include <set>
#include <map>
using namespace std;

map<string, set<int>> title, author, key, pub, year;

void query(map<string, set<int>> &m, string &s) {
    if (m.find(s) != m.end()) {
        for (auto it = m[s].begin(); it != m[s].end(); it++) {
            printf("%07d\n", *it);
        }
    } else {
        printf("Not Found\n");
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    int id;
    string ttitle, tauthor, tkey, tpub, tyear;
    for (int i = 0; i < n; i++) {//读入图书信息，填充map
        //id
        scanf("%d\n", &id);
        //title
        getline(cin, ttitle);
        title[ttitle].insert(id);
        //author
        getline(cin, tauthor);
        author[tauthor].insert(id);
        //keywords
        while (cin >> tkey) {
            key[tkey].insert(id);
            char c = getchar();
            if (c == '\n') break;
        }
        //pub
        getline(cin, tpub);
        pub[tpub].insert(id);
        //year
        getline(cin, tyear);
        year[tyear].insert(id);
    }
    
    int m;
    cin >> m;
    int code;
    string temp;
    for (int i = 0; i < m; i++) {
        scanf("%d: ", &code);
        getline(cin, temp);
        cout << code << ": " << temp << endl;
        if (code == 1) query(title, temp);
        else if (code == 2) query(author, temp);
        else if (code == 3) query(key, temp);
        else if (code == 4) query(pub, temp);
        else if (code == 5) query(year, temp);
    }

    return 0;
}