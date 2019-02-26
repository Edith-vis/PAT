#include <iostream>
#include <algorithm> //sort()
using namespace std;

int main(){
    freopen("D:/in.txt", "r",stdin);
    //输入原数列与中间数列
    int n;
    cin >> n;
    int *a = new int[n];
    int *b = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    //判断是否是插入排序
    int i, j;
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    for (j = i + 1; j < n && a[j] == b[j]; j++);

    if (j == n) {//是插入排序
        cout << "Insertion Sort" << endl;
        //下一次排序的序列
        sort(a, a + i + 2); //i是最后一个排好序了的位置
    } else {//不是插入排序，即为归并排序
        cout << "Merge Sort" << endl;
        //自己模拟一遍归并排序 到 成为中间序列
        int k = 1, flag = 1;
        while(flag){
            //判断是否成为了中间序列
            flag = 0;
            for (i = 0; i < n; i++){
                if (a[i] != b[i])
                    flag = 1;
            }
            //归并排序
            k *= 2;
            for (i = 0; i < n / k; i++){
                sort(a + i * k, a + (i + 1) * k);
            }
            //剩余不到 n/k 的排序
            sort(a + n / k * k, a + n);
        }
    }

    for (j = 0; j < n; j++){
        if (j != 0)
            cout << " ";
        cout << a[j];
    }

    delete[] a;
    delete[] b;
    return 0;
}