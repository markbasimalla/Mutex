#include "main.hpp"
#include "thread.hpp"

int main() {

  pthread_t threads_o,threads_t;
  shared_buffer* shared = Memory_setting();

  pthread_create(&threads_o, NULL, Running_belt, shared);
  pthread_create(&threads_t, NULL, Activate_motor,shared);

  pthread_join(threads_o, NULL);
  pthread_join(threads_t, NULL);

  return 1;
}


