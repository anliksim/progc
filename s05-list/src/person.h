#ifndef S05_LIST_PERSON_H
#define S05_LIST_PERSON_H

typedef struct {
    char name[20];
    char forename[20];
    unsigned age;
} Person;

Person read_person();

void print(Person person);

int equals(Person p1, Person p2);

int compare(Person p1, Person p2);

#endif //S05_LIST_PERSON_H
