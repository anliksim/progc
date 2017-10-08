#ifndef S04_POINTER_SORT_H
#define S04_POINTER_SORT_H

/**
 * Pretty-print the list to stdout.
 */
void print(const char **list, int length);

/**
 * Eliminate duplicated entries.
 * Use if list elements that are NOT stored on the heap.
 */
int reduce_on_stack(char **list, int length);

/**
 * Eliminate duplicated entries.
 */
int reduce_on_heap(char **list, int length);

/**
 * Perform an insertion sort on the list.
 * Sting comparison is case insensitive.
 */
void insertion_sort(char **list, int length);

#endif //S04_POINTER_SORT_H
