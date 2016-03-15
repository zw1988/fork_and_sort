#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int partition(int *a, int l, int r) {
    int val = a[l];
    while (l < r) {
        while(l < r && a[r] >= val) r --;
        a[l] = a[r];

        while(l < r && a[l] <= val) l ++;
        a[r] = a[l];
    }
    a[l] = val;
    return l;
}
void quick_sort(int *a, int l, int r) {
    if(l < r) {
        int p = partition(a, l ,r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}

int main() {
    /*int *a = read_data(basename(__FILE__));
    clock_t start = clock();
    quick_sort(a, 1, N);
    printf("quick sort cost time %lf, N %d\n",  (clock() - start) * 1.0 / CLOCKS_PER_SEC, N);
    assert(check(a));*/
    sort(quick_sort, basename(__FILE__));
    return 0;
}
