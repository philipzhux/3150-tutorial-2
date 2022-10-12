#include <pthread.h>
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wformat-zero-length"

void* job(void*);
pthread_mutex_t mutex; // define the mutex data structure
int main() {
    pthread_mutex_init(&mutex,NULL); // initialize the mutex data structre
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
    pthread_mutex_lock(&mutex); //only one thread can grab the lock
    // if somebody else is grabbing the lock, wait until she releases!

    /* --- this is what called "critical section" starts */

    int* t  = (int*)aux;
    int old = *t;
    for(int i=0;i<10000;i++) {
        printf("");
    }
    (*t)= old+1; // the sum may be already more than the old at this point!

    /* --- this is what called "critical section" ends */

    pthread_mutex_unlock(&mutex); // now you need to release so that other thread can go on! 

    return NULL; // hey NULL can be treated as a void* type
}

#pragma GCC diagnostic warning "-Wformat-zero-length"