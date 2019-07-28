#include <iostream>
using namespace std;


int main() {
    freopen("D:/in.txt", "r", stdin);
    string input;
    getline(cin, input);

    int sum = 0;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            sum += input[i] - 'A' + 1;
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            sum += input[i] - 'a' + 1;
        }
    }
    //printf("%d", sum);
    if (sum == 0) {
        printf("0 0");
        return 0;
    }
    
    int num_0 = 0, num_1 = 0;
    do {
        int t = sum % 2;
        sum /= 2;
        if (t == 0) num_0++;
        else num_1++;
    } while (sum != 0);

    printf("%d %d", num_0, num_1);
    return 0;
}