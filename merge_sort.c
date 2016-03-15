#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int aux[N + 1];
void merge(int* a, int l, int m, int r) {
    int i = l, j = m + 1, k = l;
    while (i <= m &&j <= r) {
        if (a[i] <= a[j]) aux[k++] = a[i++];
        else aux[k++] = a[j++];
    }
    while(i <= m) {
        aux[k++] = a[i++];
    }
    while(j <= r) {
        aux[k++] = a[j++];
    }
    for(int i = l; i <= r; i ++) 
        a[i] = aux[i];
}

void merge_sort(int* a, int l, int r) {
    if (l < r) {
       int m = ( l + r ) >> 1;
       merge_sort(a, l , m);
       merge_sort(a, m + 1, r);
       merge(a, l, m, r);
    }
}
int main() {
    sort(merge_sort, basename(__FILE__));
    return 0;
}
