/*
 * combsort.c - Comb sort algorithm
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

static void symmerge(char *a, size_t first1, size_t first2, size_t last, size_t sz, int (*cmp)(const void *, const void *)) {
    size_t m, n, l, r, mid, start, end;

    if (first1 < first2 && first2 < last) {
        m = (first1 + last) / 2;
        n = m + first2;

        if (first2 > m) {
            l = n - last;
            r = m;
        } else {
            l = first1;
            r = first2;
        }

        while (l < r) {
            mid = (l + r) / 2;

            if (cmp(a + mid * sz, a + (n - mid - 1) * sz) <= 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        start = l;
        end = n - start;

        if (end - start > 1) {
            for (l = start, r = first2 - 1; l < r; l++, r--) {
                memswap(a + l * sz, a + r * sz, sz);
            }

            for (l = first2, r = end - 1; l < r; l++, r--) {
                memswap(a + l * sz, a + r * sz, sz);
            }

            for (l = start, r = end - 1; l < r; l++, r--) {
                memswap(a + l * sz, a + r * sz, sz);
            }
        }

        symmerge(a, first1, start, m, sz, cmp);
        symmerge(a, m, end, last, sz, cmp);
    }
}

void symmergesort(void *arr, size_t n, size_t sz, int (*cmp)(const void *, const void *)) {
    char *a;
    size_t m;

    if (n < 2) {
        return;
    }

    a = arr;
    m = n / 2;

    symmergesort(a, m, sz, cmp);
    symmergesort(a + m * sz, n - m, sz, cmp);
    symmerge(a, 0, m, n, sz, cmp);
}
