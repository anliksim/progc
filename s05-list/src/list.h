#ifndef S05_LIST_LIST_H
#define S05_LIST_LIST_H

#include "person.h"

typedef struct {

    void (*insert)(Person);

    void (*remove)(Person);

    void (*show)(void);

    void (*clear)(void);

    int (*size)(void);

} LinkedList;

LinkedList list_singleton(void);

#endif //S05_LIST_LIST_H
