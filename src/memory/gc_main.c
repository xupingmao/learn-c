/*
 * @Author: xupingmao
 * @email: 578749341@qq.com
 * @Date: 2023-11-25 11:23:32
 * @LastEditors: xupingmao
 * @LastEditTime: 2023-11-25 11:39:38
 * @FilePath: \learn-c\src\memory\gc_main.c
 * @Description: 描述
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../deps/bdwgc/include/gc.h"

#define malloc GC_malloc

typedef struct object_t {
    char* name;
    int   size;
} Object;

Object* NewObject(const char* name) {
    Object* obj = GC_malloc(sizeof(Object));
    obj->size = strlen(name);
    obj->name = GC_malloc(obj->size+1);
    strcpy(obj->name, name);
    return obj;
}

char* ObjectToStr(char* result, Object* obj) {
    strcat(result, "name=");
    strcat(result, obj->name);
    return result;
}

int main(int argc, char* argv[]) {
    Object *obj = NewObject("hello");
    char objStr[1024];
    fprintf("obj=%s", ObjectToStr(objStr, obj));
    return 0;
}
