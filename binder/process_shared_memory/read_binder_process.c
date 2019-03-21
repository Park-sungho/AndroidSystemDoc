#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include "ashmem.h"

#define OEM_SHARED_MEMORY_NAME "input_buffer"
#define OEM_SHARED_MEMORY_SIZE 10

int main() {
    int ashId;
    char *buffer;

    /* int ashmem_create_region(const char *name, size_t size) */
    ashId = ashmem_create_region(OEM_SHARED_MEMORY_NAME, OEM_SHARED_MEMORY_SIZE);
    if (ashId < 0) {
        printf("ashmem_create_region is failed\n");
        return -1; 
    }    
    
    /* mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0) */
    buffer = (char*)mmap(NULL, OEM_SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, ashId, 0); 
    if (buffer < 0) {
        printf("mmap: %s is failed.\n", buffer);
        return -1; 
    }   

    do {
        printf("Input Value : %s\n", buffer);
    } while (getchar());
    return 0;
}
