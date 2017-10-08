#include <stdio.h>
#include <string.h>
#include "person.h"
#include "console.h"

static void read_name(char *name)
{
    (void) scanf("%19[^\n]", name);
    flush_stdin();
}

Person read_person()
{
    Person person = {0};

    (void) printf("Name:");
    read_name(person.name);

    (void) printf("First name:");
    read_name(person.forename);

    (void) printf("Age:");
    (void) scanf("%u[^\n]", &person.age);

    return person;
}

void print(const Person person)
{
    (void) printf("%s, %s, %d\n", person.name, person.forename, person.age);
}

int equals(const Person p1, const Person p2)
{
    return p1.age == p2.age &&
           strcmp(p1.name, p2.name) == 0 &&
           strcmp(p1.forename, p2.forename) == 0;
}

static int compare_age(const unsigned age1, const unsigned age2)
{
    return age1 == age2 ? 0 : age1 - age2;
}

static int compare_forename(const Person p1, const Person p2)
{
    int forename_cmp = strcmp(p1.forename, p2.forename);
    return forename_cmp == 0 ? compare_age(p1.age, p2.age) : forename_cmp;
}

int compare(const Person p1, const Person p2)
{
    int name_cmp = strcmp(p1.name, p2.name);
    return name_cmp == 0 ? compare_forename(p1, p2) : name_cmp;
}