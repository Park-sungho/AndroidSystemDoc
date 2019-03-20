#include <stdio.h>
#include <errno.h>
#include <sys/mman.h>
#include <ashmem.h>

#define OEM_SHARED_MEMORY_NAME "input_buffer"
#define OEM_SHARED_MEMORY_SIZE 10

void main(int argc, char **argv) {
    int ashId;
    char *buffer;
    int input_val;
    
    /* int ashmem_create_region(const char *name, size_t size) */
    ashId = ashmem_create_region(OEM_SHARED_MEMORY_NAME, OEM_SHARED_MEMORY_SIZE);
    if (ashId < 0)
    {
        debug_error("ashmem_create_region is failed\n");
        return;
    }

    /* mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0) */
    buffer = (char*)mmap(NULL, OEM_SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, ashId, 0);
    if (buffer < 0)
        debug_error("mmap: %s is failed.\n", filename);
        return;
    }

    input_val = getchar();
    buffer[0] = input_val;
    printf("Output Value : %s\n", buffer);

    munmap(buffer, OEM_SHARED_MEMORY_SIZE);

    close(ashId);
    return 0;
}
