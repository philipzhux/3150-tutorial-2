#include <pthread.h>
#include <stdio.h>

void* job(void*);

int main() {
    pthread_t my_thread; // define the thread data structure
    pthread_create(&my_thread,NULL,job,NULL); // pthread_create(pthread_t* your_thread_data_structure,NULL)
    pthread_join(my_thread,NULL);
}




void* job(void* aux) {
    printf("Hello from thread\n");
    return NULL; // hey NULL can be treated as a void* type
}