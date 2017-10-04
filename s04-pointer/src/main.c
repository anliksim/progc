/// @brief Include POSIX 2008 and X/Open 7 definitions
#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

const char *EOI = "ZZZ\n";

int swap(char **current, char **next) {
    char *tmp = *next;
    *next = *current;
    *current = tmp;
}

int partition(char **list, int low, int high) {
    char *pivot = *(list + high);
    int i = low - 1;
    for (int j = 0; j < high; ++j) {
        if (strcmp(*(list + j), pivot) < 0) {
            ++i;
            swap(list + i, list + j);
        }
    }
    if (strcmp(pivot, *(list + i + 1)) < 0) {
        swap(list + i + 1, list + high);
    }
    return i + 1;
}

void quick_sort(char **list, int low, int high) {
    if (low < high) {
        int p = partition(list, 0, high);
        quick_sort(list, 0, p - 1);
        quick_sort(list, p + 1, high);
    }
}

void shift(char **list, int length) {
    free(*(list));
    for (int i = 0; i < length; ++i) {
        *(list + i) = *(list + i + 1);
    }
    *(list + length) = 0;
}

/**
 *
 * @param list
 * @param length
 * @return new length
 */
int reduce(char **list, int length) {
    for (int i = 0; i < length; ++i) {
        if (strcmp(*(list + i), *(list + i + 1)) == 0) {
            shift(list + i, length - i);
            --length;
        }
    }
    return length;
}

void sort(char **list, int length) {
    quick_sort(list, 0, length);
}


void print(char **list, int length) {
    for (int j = 0; j < length; ++j) {
        (void) printf("%s", *(list + j));
    }
}

/**
 *
 * @return exit code
 */
int main() {

//    char word[20];
    char *wordlist[100];

    char *line = NULL;

    int i = 0;

    do {

        size_t size;
        ssize_t length = getline(&line, &size, stdin);
        if (length == -1) {
            (void) fprintf(stderr, "Failed to read line. (errno=%d)", errno);
            return EXIT_FAILURE;
        }

        wordlist[i] = malloc(size);
        strcpy(wordlist[i], line);

        ++i;

    } while (strcmp(line, EOI) != 0);

    int length = i - 1;

    sort(wordlist, length);
    length = reduce(wordlist, length);
    print(wordlist, length);

    for (int j = 0; j < i; ++j) {
        free(wordlist[j]);
    }

    return EXIT_SUCCESS;
}
