#ifndef S04_POINTER_SORT_H
#define S04_POINTER_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(char **list, int length);

int reduce_on_stack(char **list, int length);

int reduce_on_heap(char **list, int length);

void insertion_sort(char **list, int length);

#endif //S04_POINTER_SORT_H
