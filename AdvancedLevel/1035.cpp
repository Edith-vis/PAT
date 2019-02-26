#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    string name, pwd;
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        cin >> name >> pwd;
        int len = pwd.length();
        int flag = 0;
        for (int j = 0; j < len; j++) {
            switch(pwd[j]) {
                case '0':
                    pwd[j] = '%';
                    flag = 1;
                    break;
                case '1' :
                    pwd[j] = '@';
                    flag = 1;
                    break;
                case 'O' :
                    pwd[j] = 'o';
                    flag = 1;
                    break;
                case 'l' : 
                    pwd[j] = 'L';
                    flag = 1;
                    break;
            }
        }

        if (flag == 1) {
            string temp = name + " " + pwd;
            ans.push_back(temp);
        }
    }

    int len = ans.size();
    if (len != 0) {
        printf("%d\n", len);
        for (int i = 0; i < len; i++) {
            cout << ans[i] << endl;
        }
    } else if (n == 1) {
        cout << "There is 1 account and no account is modified";
    } else {
        printf("There are %d accounts and no account is modified", n);
    }

    return 0;
}