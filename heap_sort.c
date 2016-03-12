#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void heap_adjust(int* a, int s, int n) {
    int tmp = a[s];
    for (int i = s << 1; i <= n; i <<= 1) {
        if(i < n && a[i] < a[i + 1])
            i ++;
        if(a[i] <= tmp) break;
        a[s] = a[i];
        s = i;
    }
    a[s] = tmp; 
}
void heap_sort(int* a, int n) {
    for(int i = n >> 1; i > 0; i --) 
        heap_adjust(a, i, n);
    for(int i = n; i > 0; i --) {
        a[i] ^= a[1];
        a[1] ^= a[i];
        a[i] ^= a[1];
        heap_adjust(a, 1, i - 1);
    }
}
int main() {
    int *a = read_data(basename(__FILE__));
    clock_t start = clock();
    heap_sort(a, N);
    printf("heap sort cost time %.2lf, N %d\n",  (clock() - start) * 1.0 / CLOCKS_PER_SEC, N);
    assert(check(a));
    return 0;
}
