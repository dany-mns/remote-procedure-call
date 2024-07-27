#include <stdio.h>

typedef struct dddd {
    char name[30];
    int age;
    int weight;
} my_struct;

#define get_offset(struct, field) (unsigned int)(&(((struct *)0)->field))

int main() {
    my_struct a;
    a.age = 1;
    a.weight = 2;

    printf("Direct access to age: %d\n", a.age);

    my_struct *b = &a;

    printf("Direct access to age using pointer: %d\n", b->age);

    printf("Direct access to age using pointer: %d\n", ((char *)b + (32)));
    printf("Offest of age in the struct: %d\n", get_offset(my_struct, age));
    printf("size of struct %d \n", sizeof(my_struct));
    printf("hello\n");
    return 0;
}