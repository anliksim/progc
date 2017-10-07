#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"

Person read_person() {

    Person person = {0};

    (void) printf("Name:");
    (void) scanf("%s", person.name);
    (void) printf("First name:");
    (void) scanf("%s", person.forename);
    (void) printf("Age:");
    (void) scanf("%d", &person.age);

    return person;
}

void print(Person person) {
    (void) printf("%s, %s, %d\n", person.name, person.forename, person.age);
}

int equals(Person p1, Person p2) {
    return p1.age == p2.age &&
           strcmp(p1.name, p2.name) == 0 &&
           strcmp(p1.forename, p2.forename) == 0;
}

int compare_age(unsigned age1, unsigned age2) {
    return age1 == age2 ? 0 : age1 - age2;
}

int compare_forename(Person p1, Person p2) {
    int forename_cmp = strcmp(p1.forename, p2.forename);
    return forename_cmp == 0 ? compare_age(p1.age, p2.age) : forename_cmp;
}

/**
 * < 0 if p1 less than p2
 * > 0 if p2 less than p1
 * = 0 if p1 equals p2
 */
int compare(Person p1, Person p2) {
    int name_cmp = strcmp(p1.name, p2.name);
    return name_cmp == 0 ? compare_forename(p1, p2) : name_cmp;
}