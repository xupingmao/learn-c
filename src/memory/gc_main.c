/*
 * @Author: xupingmao
 * @email: 578749341@qq.com
 * @Date: 2023-11-25 11:23:32
 * @LastEditors: xupingmao
 * @LastEditTime: 2023-11-25 13:46:46
 * @FilePath: \learn-c\src\memory\gc_main.c
 * @Description: 描述
 */
#define GC_DBGLOG_PRINTF /* 开启debug日志 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <execinfo.h>
#include "../../deps/bdwgc/include/gc.h"

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

char* ObjectToStr(char* result, Object* obj) {
    sprintf(result, "{id=%p, name=%s}", obj, obj->name);
    return result;
}

void GC_CALLBACK finalizer(void * obj, void * client_data) {
  char* args = (char*) client_data;
  printf("object finalize, obj=%p, args=%s\n", obj, args);
}


void testGc() {
    Object *obj = NewObject("hello");
    GC_REGISTER_FINALIZER(obj, finalizer, "finalize args", 0, 0);
    
    char objStr[1024];
    memset(objStr, 0, sizeof(objStr));
    printf("obj=%s\n", ObjectToStr(objStr, obj));
}

void printTraceback() {
    int size = 16;
    void* array[16];

    int stackNum = backtrace(array, size);
    char **stackTrace = backtrace_symbols(array, stackNum);
    for (int i = 0; i < stackNum; i++) {
        printf("%s\n", stackTrace[i]);
    }
}


int main(int argc, char* argv[]) {
    testGc();
    GC_gcollect();
    testGc();
    GC_gcollect();
    return 0;
}
