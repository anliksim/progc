#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

void print(char **list, int length)
{
    for (int j = 0; j < length; ++j) {
        (void) printf("%s", *(list + j));
    }
}

void shift(char **list, int length, int heap)
{
    if (heap) {
        free(*(list));
    }
    for (int i = 0; i < length; ++i) {
        *(list + i) = *(list + i + 1);
    }
    *(list + length) = 0;
}

int reduce(char **list, int length, int heap)
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

int reduce_on_stack(char **list, int length)
{
    return reduce(list, length, 0);
}

int reduce_on_heap(char **list, int length)
{
    return reduce(list, length, 1);
}

void insertion_sort(char **list, int length)
{

    for (int i = 0; i < length; ++i) {

        char *current = *(list + i);

        int j = i;

        while (j > 0 && strcmp(*(list + j - 1), current) > 0) {
            *(list + j) = *(list + j - 1);
            --j;
        }
        *(list + j) = current;
    }
}
