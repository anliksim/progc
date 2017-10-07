#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct node {
    Person person;
    struct node *next;
} Node;

Node head = {
        {0},
        &head
};

void list_insert(Person person) {

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
}

void list_remove(Person person) {
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
}

void list_show() {
    Node *el = head.next;
    while (el != &head) {
        print(el->person);
        el = el->next;
    }
}

void list_clear() {
    Node *el = head.next;
    while (el != &head) {
        Node *tmp = el;
        el = tmp->next;
        free(tmp);
    }
    head.next = el;
}
