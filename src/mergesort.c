/*
 * mergesort.c - Merge sort algorithm
 * Copyright (c) 2017 Nicholas West, et al.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * This software is provided "as is" and the author disclaims all
 * warranties with regard to this software including all implied warranties
 * of merchantability and fitness. In no event shall the author be liable
 * for any special, direct, indirect, or consequential damages or any
 * damages whatsoever resulting from loss of use, data or profits, whether
 * in an action of contract, negligence or other tortious action, arising
 * out of or in connection with the use or performance of this software.
 */

#include "sort.h"
#include <stdlib.h>

static void merge(char *a, char *tmp, size_t n, size_t sz, int (*cmp)(const void *, const void *)) {
    size_t i, j, k, m;

    if (n < 2) {
        return;
    }

    m = n / 2;

    merge(a, tmp, m, sz, cmp);
    merge(a + m * sz, tmp, n - m, sz, cmp);

    i = 0;
    j = m;
    k = 0;

    while (i < m && j < n) {
        if (cmp(a + i * sz, a + j * sz) <= 0) {
            memcopy(tmp + k * sz, a + i * sz, sz);
            i++;

        } else {
            memcopy(tmp + k * sz, a + j * sz, sz);
            j++;
        }

        k++;
    }

    while (i < m) {
        memcopy(tmp + k * sz, a + i * sz, sz);
        i++, k++;
    }

    while (j < n) {
        memcopy(tmp + k * sz, a + j * sz, sz);
        j++, k++;
    }

    memcopy(a, tmp, n * sz);
}

void mergesort(void *arr, size_t n, size_t sz, int (*cmp)(const void *, const void *)) {
    char *tmp;

    tmp = malloc(n * sz);
    if (tmp == NULL) {
        symmergesort(arr, n, sz, cmp);
        return;
    }

    merge(arr, tmp, n, sz, cmp);

    free(tmp);
}
