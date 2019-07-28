#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v[3];
int main() {
    freopen("D:/in.txt", "r", stdin);
    string input;
    for (int i = 0; i < 3; i++) {
        getline(cin, input);
        int j = 0;
        while (j < input.size()) {
            if (input[j] == '[') {
                j++;
                string str = "";
                while (input[j] != ']') {
                    str += input[j];
                    j++;
                }
                v[i].push_back(str);
            }
            j++;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        string ans = "";
        int id[5];
        for (int i = 0; i < 5; i++) {
            scanf("%d", &id[i]);
            id[i]--;
        }

        if (id[0] >= v[0].size() || id[1] >= v[1].size() || id[2] >= v[2].size() || id[3] >= v[1].size() || id[4] >= v[0].size() || id[0] < 0 || id[1] < 0 || id[2] < 0 || id[3] < 0 || id[4] < 0) {
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        cout << v[0][id[0]] << "(" << v[1][id[1]] << v[2][id[2]] << v[1][id[3]] << ")" << v[0][id[4]] << endl;
    }
    return 0;
}