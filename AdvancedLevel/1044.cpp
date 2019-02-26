#include <iostream>
#include <vector>
using namespace std;

vector<int> sum, ans;
int n, m;

void binarySeach(int i, int &j, int &tempSum) {//固定i找合适的j
    int left = i;
    int right = n;
    while (left < right) {
        int mid = (left + right)/2;
        if (sum[mid] - sum[i-1] >= m) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    j = right;//和大于m的最近的j
    tempSum = sum[j] - sum[i-1];
}

int main() {
    freopen("D:/in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    sum.resize(n+1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];//sum数组里存储的是累加的结果 
    }

    int minSum = sum[n];
    for (int i = 1; i <= n; i++) {
        int j = 0, tempSum = 0;
        binarySeach(i, j, tempSum);
        if (tempSum > minSum) continue;
        if (tempSum >= m) {
            if (tempSum < minSum) {
                ans.clear();
                minSum = tempSum;
            }
            ans.push_back(i);
            ans.push_back(j);
        }
    }

    for (int i = 0; i < ans.size(); i+=2) {
        printf("%d-%d\n", ans[i], ans[i+1]);
    }

    return 0;
}