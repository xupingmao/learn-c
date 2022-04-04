#include <stdio.h>

/** 模拟方法多态的示例 **/
typedef struct person_t {
    char* name;
    int age;
    void (*greeting)(struct person_t*); /* 类似于C++的虚函数 */
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

void Worker_Greeting(Person* p) {
    printf("Hello, my name is %s, I am %d years old, and I am a worker\n", p->name, p->age);
}

void Teacher_Greeting(Person* p) {
    printf("Hello, my name is %s, I am %d years old, and I am a teacher, "
        "I love my job very much!\n", p->name, p->age);
}

void NewWorker(Person* p, char*name, int age) {
    /* 让上层传入结构体，避免动态内存分配 */
    p->name = name;
    p->age = age;
    p->greeting = Worker_Greeting;
}

void NewTeacher(Person* p, char*name, int age) {
    p->name = name;
    p->age = age;
    p->greeting = Teacher_Greeting;
}


int main(int argc, char* argv[]) {
    Person worker;
    NewWorker(&worker, "Mark", 20);
    worker.greeting(&worker);

    Person teacher;
    NewTeacher(&teacher, "Wang", 25);
    teacher.greeting(&teacher);

    return 0;
}