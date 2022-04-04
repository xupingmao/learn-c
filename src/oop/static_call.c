#include <stdio.h>

typedef struct person_t {
    char* name;
    int age;
} Person;

char* Person_GetName(Person* p) {
    return p->name;
}

int Person_GetAge(Person* p) {
    return p->age;
}

void Person_Greeting(Person* p) {
    printf("Hello, my name is %s, I am %d years old\n", p->name, p->age);
}


int main(int argc, char* argv[]) {
    Person p;
    p.name = "Mark";
    p.age = 20;

    Person_Greeting(&p);
    return 0;
}