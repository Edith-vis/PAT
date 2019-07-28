#include <iostream>
using namespace std;

void bubblesort(int A[], int n) {
    for (bool sorted = false; sorted = !sorted; n--) {
        for (int i = 1; i < n; i++) {
            if (A[i-1] > A[i]) {
                swap(A[i-1], A[i]);
                sorted = false;
            }
        }
    }
}

int main() {
    freopen("D:/in.txt", "r", stdin);

    int n;
    scanf("%d", &n);
    int A[12];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    bubblesort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}