#include <iostream>
using namespace std;


//[lo, hi)
void max2(int A[], int lo, int hi, int &x1, int &x2) {
    if (hi <= lo + 2) {
        if (A[lo] >= A[lo+1]) {
            x1 = lo;
            x2 = lo + 1;
        } else {
            x1 = lo + 1;
            x2 = lo;
        }
        return;
    }

    if (hi <= lo + 3) {
        int larger = lo;
        int less = lo + 1;
        if( A[less] > A[larger]) swap(larger, less);//最大值候补
        if (A[larger] > A[lo + 2]) {
            x1 = larger;
            x2 = A[less] > A[lo + 2] ? less : lo + 2;
        } else {
            x1 = lo + 2;
            x2 = larger;
        }
        return;
    }

    int mi = (lo+hi)/2;
    int x1L, x2L; max2(A, lo, mi, x1L, x2L);
    int x1R, x2R; max2(A, mi, hi, x1R, x2R);

    if (A[x1L] > A[x1R]) {
        x1 = x1L; x2 = (A[x2L] > A[x1R]) ? x2L : x1R; 
    } else {
        x1 = x1R; x2 = (A[x2R] > A[x1L]) ? x2R : x1L;
    }
    return;
}


int main() {
    int a[3] = {0, 2, 2};
    int x1, x2;
    max2(a, 0, 3, x1, x2);
    printf("%d--%d\n", x1, x2);
    return 0;
}