#ifndef _READ_DATA_H
#define _READ_DATA_H

#include <libgen.h>
#include <assert.h>

#define N 9000000

void sort(void (*sort_method)(int *a, int s, int e), char *fname);

#endif
