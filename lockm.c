#include <pthread.h>
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wformat-zero-length"
void* job(void*);

int main() {
    pthread_t my_thread[100]; // define the thread data structure
    int sum = 0;

    for(int i=0;i<100;i++) {
        pthread_create(&my_thread[i],NULL,job,(void*)&sum); // pthread_create(pthread_t* your_thread_data_structure,NULL)
    }
    
    printf("The main thread finishes creating all threads!\n");

    for(int i=0;i<100;i++) {
        pthread_join(my_thread[i],NULL);
    }
    printf("final sum = %d, expecting 100.\n",sum);
}


void* job(void* aux) {
    int* t  = (int*)aux;
    int old = *t;
    for(int i=0;i<10000;i++) {
        printf("");
    }
    (*t)= old+1; // the old may be stale!
    return NULL; // hey NULL can be treated as a void* type
}
#pragma GCC diagnostic warning "-Wformat-zero-length"