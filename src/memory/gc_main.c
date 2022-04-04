#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../third_party/bdwgc/include/gc.h"

#define malloc GC_malloc

typedef struct object_t {
    char* name;
    int   size;
} Object;

Object* NewObject(const char* name) {
    Object* obj = malloc(sizeof(Object));
    obj->size = strlen(name);
    obj->name = malloc(obj->size+1);
    strcpy(obj->name, name);
    return obj;
}

int main(int argc, char* argv[]) {
    Object *obj = NewObject("hello");
    return 0;
}
