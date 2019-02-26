//按照发现顺序，在一行中输出坏掉的键。其中英文字母只输出大写，每个坏键只输出一次。
//npos是一个常数，表示size_t的最大值（Maximum value for size_t）。
//许多容器都提供这个东西，用来表示不存在的位置，类型一般是std::container_type::size_type
//npos可以表示string的结束位子，是string::type_size 类型的，也就是find（）返回的类型。
//find函数在找不到指定值的情况下会返回string::npos
#include <iostream>

using namespace std;

int main() {
    freopen("D:/in.txt", "r", stdin);
    string a, b;
    cin >> a >> b;
    string result = "";
    for (int i = 0; i < a.length(); i++) {
        if (b.find(a[i]) == string::npos && result.find(toupper(a[i])) == string::npos) {
            //b中找不到a[i] 且 result中找不到a[i]的大写
            result += toupper(a[i]);
        }
    }
    cout << result;
    return 0;
}