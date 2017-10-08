#ifndef S05_LIST_PERSON_H
#define S05_LIST_PERSON_H

#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char forename[NAME_LENGTH];
    unsigned age;
} Person;

/**
 * Read a person from stdin.
 * @return read input as Person
 */
Person read_person();

/**
 * Pretty-print a person to stdout.
 */
void print(Person person);

/**
 * @return 1 if p1 equals p2
 */
int equals(Person p1, Person p2);

/**
 * @return value < 0 if p1 less than p2
 *               > 0 if p2 less than p1
 *               = 0 if p1 equals p2
 */
int compare(Person p1, Person p2);

#endif //S05_LIST_PERSON_H
