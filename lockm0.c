#include <pthread.h>
#include <stdio.h>

void* job(void*);

int main() {
    pthread_t my_thread[5]; // define the thread data structure
    int ids[5];

    for(int i=0;i<5;i++) {
        ids[i] = i;
        pthread_create(&my_thread[i],NULL,job,(void*)&ids[i]); // pthread_create(pthread_t* your_thread_data_structure,NULL)
    }
    
    printf("The main thread finishes creating all threads!\n");

    for(int i=0;i<5;i++) {
        pthread_join(my_thread[i],NULL);
    }
}






void* job(void* aux) {
    int t  = *(int*)aux;
    for(int i=0;i<20;i++){
        printf("[THERAD %d] Line %d\n",t,i);
    }
    return NULL; // hey NULL can be treated as a void* type
}