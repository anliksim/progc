#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct node {
    Person person;
    struct node *next;
} Node;

static Node head = {{{0}}, &head};
static int size = 0;

static void list_insert(Person person) {

    Node *prev = &head;
    while (prev->next != &head) {
        prev = prev->next;
    }

    Node *el = malloc(sizeof(Node));
    if (el == NULL) {
        return;
    }
    el->person = person;
    el->next = &head;
    prev->next = el;

    ++size;
}

static void list_remove(Person person) {
    Node *prev = &head;
    Node *el = head.next;
    while (el != &head) {
        if (equals(person, el->person)) {
            prev->next = el->next;
            el = &head;
        } else {
            prev = el;
            el = el->next;
        }
    }
    --size;
}

static Node *for_each(Node *(*func)(Node *)) {
    Node *el = head.next;
    while (el != &head) {
        el = func(el);
    }
    return el;
}

static Node *_print(Node *el) {
    print(el->person);
    return el->next;
}

static void list_show(void) {
    (void) for_each(&_print);
}

static Node *_clear(Node *el) {
    Node *tmp = el;
    el = tmp->next;
    free(tmp);
    return el;
}

static void list_clear(void) {
    head.next = for_each(&_clear);
    size = 0;
}

static int list_size(void) {
    return size;
}

LinkedList list_singleton() {
    LinkedList list = {
            &list_insert,
            &list_remove,
            &list_show,
            &list_clear,
            &list_size
    };
    return list;
}
