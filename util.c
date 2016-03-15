#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int read_int(FILE *fp) {
    char c = fgetc(fp);
    int n = 0;
    while(c < '0' || c > '9') c = fgetc(fp);
    while(c >= '0' && c <= '9') {
        n = (n << 1) + (n << 3) + c - '0';
        c = fgetc(fp);
    }
    return n;
}

int* read_data(char *fname){
    char filename[60];
    strcpy(filename, fname);
    strcat(filename, ".data");

    int *a = malloc(sizeof(int) * (N + 1));
    FILE *fp = fopen(filename, "r");
    for(int i = 1; i <= N; i++) 
        a[i] = read_int(fp);

    return a;
}

int check(int *a) {
    for(int i = 2; i <= N; i ++)
        if (a[i - 1] > a[i])
            return 0;
    return 1;
}

void sort(void (*sort_method)(int *a, int start, int end), char *filename) {
    int *a = read_data(filename);
    clock_t start = clock();
    sort_method(a, 1, N);
    printf("%s cost time %lf, N  %d\n", filename, (clock() - start) * 1.0 / CLOCKS_PER_SEC, N);
    assert(check(a));
    free(a);
}
