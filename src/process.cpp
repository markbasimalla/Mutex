#include "main.hpp"
#include "thread.hpp"
void* Running_belt(void* arg) {
    shared_buffer* shared = (shared_buffer*)arg;
    while (1) {
        pthread_mutex_lock(&shared->mutex);
        shared->count = shared->count + 1;
        if(shared->count == BUFFER_SIZE)
            shared->count = 0;  
        char data = shared->buffer[shared->count];
        LOG(LOGGER_LEVEL_INFO, "Running belt: %c ", data);
        pthread_mutex_unlock(&shared->mutex);
        usleep(500);
    }
    return NULL;
}

void* Activate_motor(void* arg) {
    shared_buffer* shared = (shared_buffer*)arg;
    while (1) {
        pthread_mutex_lock(&shared->mutex);
        if (shared->buffer[shared->count] == '0')
           LOG(LOGGER_LEVEL_INFO, "Motor Status: OFF");
        else
           LOG(LOGGER_LEVEL_INFO, "Motor Status: ON");        
        pthread_mutex_unlock(&shared->mutex);
        usleep(500);
    }
    return NULL;
}

shared_buffer* Memory_setting() {
    int fd = shm_open("/sample_memory", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(shared_buffer)); 
    shared_buffer* shared = (shared_buffer*)mmap(NULL, sizeof(shared_buffer), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    shared->count = -1;
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutex_init(&shared->mutex, &attr);
    
    char initial_buffer[BUFFER_SIZE] = {'0', 'A', 'B', 'D', '0', '0', 'E', 'F', '0', 'G'};
    memcpy(shared->buffer, initial_buffer, sizeof(initial_buffer));

    return shared;
}








