#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#define BUFFER_DEFAULT_SIZE 1

typedef struct serialized_buffer {
    char *starting_address;
    int size;
    int next;
} serialized_buffer;

typedef struct dddd {
    char name[30];
    int age;
    int weight;
} my_struct;

#define get_offset(struct, field) (unsigned int)(&(((struct *)0)->field))

void init_serialized_buffer(serialized_buffer *buff) {
    buff->starting_address = calloc(1, BUFFER_DEFAULT_SIZE);
    buff->size = BUFFER_DEFAULT_SIZE;
    buff->next = 0;
}

void serialize_date(serialized_buffer *buff, char *data, int nbytes) {
    printf("We have %d/%d bytes free space, and size of data to be copied is %d bytes \n", (buff->size - buff->next), buff->size, nbytes);
    
    if(buff->size - buff->next < nbytes) {
        printf("Allocate more space.\n");
        uint32_t required_size = (nbytes + (BUFFER_DEFAULT_SIZE - 1)) / BUFFER_DEFAULT_SIZE;
        buff->size = buff->size + (required_size * BUFFER_DEFAULT_SIZE);
        buff->starting_address = (char *)realloc(buff->starting_address, buff->size);
    } 

    memcpy(buff->starting_address + buff->next, data, nbytes);
    buff->next += nbytes;

}

int main() {
    serialized_buffer *sbuff = (serialized_buffer *)calloc(1, sizeof(serialized_buffer));
    init_serialized_buffer(sbuff);
    sbuff->starting_address[0] = 'A';
    sbuff->next += 1;
    serialize_date(sbuff, "B", 1);
    serialize_date(sbuff, "C", 1);
    return 0;
}