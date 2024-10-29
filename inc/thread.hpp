#include "main.hpp"
typedef struct {
    char buffer[BUFFER_SIZE];
    int count;
    int status;
    pthread_mutex_t mutex;
} shared_buffer;
shared_buffer* Memory_setting();