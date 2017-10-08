#ifndef S05_LIST_PERSON_H
#define S05_LIST_PERSON_H

#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char forename[NAME_LENGTH];
    unsigned age;
} Person;

void flush_stdin();

Person read_person();

void print(Person person);

int equals(Person p1, Person p2);

int compare(Person p1, Person p2);

#endif //S05_LIST_PERSON_H
