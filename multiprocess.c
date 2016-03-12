#include "util.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#define NUM_PROCESS 3

int ARRAY[N + 1];

char *sort_ways[] = {
    "merge_sort",
    "quick_sort",
    "heap_sort",
};

void shuffle(int *a, int n) {
    int j, i = n;
    srand(time(NULL));
    while (i > 1) {
        j = rand() % (i + 1);
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
        i --;
    }
}
void generate() {
    //FILE *fp = fopen("data.txt", "w");
    for(int i = 1; i <= N; i++) 
        ARRAY[i] = rand();
    
    //shuffle(ARRAY, N);

    //for(int i = 1; i <= N; i++) 
     //   fprintf(fp, "%d ", ARRAY[i]);
    //fflush(fp);
}

int main() {
    generate();
    char filename[64];
    for(int i = 0; i < NUM_PROCESS; i++){

        strcpy(filename, sort_ways[i]);
        strcat(filename, ".c.data");
        FILE *fp = fopen(filename, "w");
        for(int i = 1; i <= N; i ++) 
            fprintf(fp, "%d ", ARRAY[i]);
        fflush(fp);

        pid_t pid = fork();
        if (pid==0) {
            char* args[] = {
                sort_ways[i],
                sort_ways[i],
                (char *)0,
            };
            execv(args[0], args);
        }else if (pid < 0) 
            puts("fork error");
    }

    for(int i = 0; i < NUM_PROCESS; i++)
        wait(NULL);

    return 0;
}
