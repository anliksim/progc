#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "sort.h"

void print(const char **list, const int length)
{
    for (int j = 0; j < length; ++j) {
        (void) printf("%s", *(list + j));
    }
}

static void shift(char **list, const int length, const int heap)
{
    if (heap) {
        /*
         * If on heap make sure the memory used for the
         * duplicate element is freed up.
         */
        free(*(list));
    }
    for (int i = 0; i < length; ++i) {
        *(list + i) = *(list + i + 1);
    }
    *(list + length) = 0;
}

static int reduce(char **list, int length, const int heap)
{
    for (int i = 0; i < length;) {
        if (strcmp(*(list + i), *(list + i + 1)) == 0) {
            shift(list + i, length - i, heap);
            --length;
        } else {
            ++i;
        }
    }
    return length;
}

int reduce_on_stack(char **list, const int length)
{
    return reduce(list, length, 0);
}

int reduce_on_heap(char **list, const int length)
{
    return reduce(list, length, 1);
}

void insertion_sort(char **list, const int length)
{
    for (int i = 0; i < length; ++i) {

        char *current = *(list + i);

        int j = i;

        while (j > 0 && strcasecmp(*(list + j - 1), current) > 0) {
            *(list + j) = *(list + j - 1);
            --j;
        }
        *(list + j) = current;
    }
}
