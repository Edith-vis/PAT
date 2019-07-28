#include <iostream>
#include <map>
#include <set>
using namespace std;

map<char, bool> isBroken; //句子中出现过的字母，是否是坏的
bool sureNoBroken[256];   //确定不是坏的的字母 asc码有256个
set<char> printed;        //判断为坏并且已经被打印过了的字母

int main() {
    freopen("D:/in.txt", "r", stdin);
    int k;
    scanf("%d", &k);
    string input;
    cin >> input;
    char pre = '#';
    input = input + "#";

    int cnt = 1;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == pre) {
            cnt++;
        } else {
            if (cnt%k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }

        if (i != input.size()-1)//因为i==input.size()-1时，input[i]="#"
            isBroken[input[i]] = cnt % k == 0;
        pre = input[i];
    }

    for (int i = 0; i < input.size(); i++) {
        if (sureNoBroken[input[i]] == true) {
            isBroken[input[i]] = false;
        }
    }

    for (int i = 0; i < input.size(); i++) {
        if (isBroken[input[i]] == true && printed.find(input[i]) == printed.end()) {
            printf("%c", input[i]);
            printed.insert(input[i]);
        }
    }
    printf("\n");

    for (int i = 0; i < input.size() - 1; i++) {
        printf("%c", input[i]);
        if (isBroken[input[i]] == true) {
            i += (k - 1);
        }
    }

    return 0;
}

// 寻找坏键:
// s1:遍历字符串的每个字符的时候，与pre（字符串当前字符s[i]的前⼀个字符）相⽐较，如果相等就继续计数cnt++，如果不相等，令cnt = 1表示当前字符出现了⼀次, 如果cnt%k==0 则令s[i]可能是坏键，置map对应的字符的bool值为true
// s2:布尔型数组sureNoBroken[256]，标记确定不是坏键的键，在map都设置完成后把确定不是坏键的m标记为false。
// 输出坏键：
// 由于需要根据坏键发现的顺序输出，所以遍历整个字符串的⽅式输出，并且确保不会重
// 复输出（⽤set集合确保，输出过了的放在set⾥⾯）
// 输出整个正确的字符串：
// 如果当前s[i]是坏键，在输出⼀次后，令 i += k – 1，再输出，保证坏键出现k次只输出⼀次