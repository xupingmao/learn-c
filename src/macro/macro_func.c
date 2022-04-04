#include <stdio.h>

#define MAX(x,y) (x) > (y) ? (x) : (y)
#define STR_CONCAT(x,y) x y
#define NAME_TO_STR(name) #name
#define NAME_CONCAT_STR(name, str) #name str
#define VAR_CONCAT(a, b) a##b



int main(int argc, char* argv[]) {
    char* var15 = "hello";
    printf("MAX(3,5)=%d\n", MAX(3,5));
    printf("STR_CONCAT(\"abc\",\"def\")=%s\n", STR_CONCAT("abc", "def"));
    printf("NAME_TO_STR(abc)=%s\n", NAME_TO_STR(abc));
    printf("NAME_CONCAT_STR(foo, \"bar\")=%s\n", NAME_CONCAT_STR(abc, "bar"));
    printf("VAR_CONCAT(var, 15)=%s\n", VAR_CONCAT(var, 15));
    return 0;
}
