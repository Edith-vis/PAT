#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

struct School {
    int rank;
    string name;
    int totalA = 0, totalB = 0, totalT = 0;
    int total;
    int numOfStudents = 0;
} school[100000];

int cnt = 0;

map<string, int> nameTOID;

string getLowerCase(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int getSchoolID(string s) {
    s = getLowerCase(s);
    if (nameTOID.find(s) == nameTOID.end()) {
        nameTOID[s] = cnt;
        return cnt++;
    } else {
        return nameTOID.find(s)->second;
    }
}

bool cmp(School a, School b) {
    if (a.total != b.total) {
        return a.total > b.total;
    } else if (a.numOfStudents != b.numOfStudents) {
        return a.numOfStudents < b.numOfStudents;
    } else {
        return a.name < b.name;
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string stuid, schoolName;
        int score;
        cin >> stuid >> score >> schoolName;
        int schID = getSchoolID(schoolName);
        school[schID].name = getLowerCase(schoolName);
        school[schID].numOfStudents++;
        if (stuid[0] == 'A') {
            school[schID].totalA += score;
        } else if (stuid[0] == 'B') {
            school[schID].totalB += score;
        } else {
            school[schID].totalT += score;
        }
    }

    for (int i = 0; i < cnt; i++) {
        school[i].total = (int)floor(school[i].totalB * 1.0 / 1.5 + school[i].totalA + school[i].totalT * 1.5);
    }

    sort(school, school + cnt, cmp);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++) {
        if (i != 0 && school[i].total == school[i-1].total) {
            school[i].rank = school[i - 1].rank;
        } else {
            school[i].rank = i + 1;
        }

        cout << school[i].rank << " " << school[i].name << " " << school[i].total << " " << school[i].numOfStudents << endl;
    }

        return 0;
}