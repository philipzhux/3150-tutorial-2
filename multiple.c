#include <pthread.h>
#include <stdio.h>

struct arguments{
    int a;
    int b;
    int c;
};

int print_add(int, int, int);
void* wrapper(void*);

int main() {
    pthread_t my_thread[10]; // define the thread data structure
    struct arguments arg[10];

    for(int i=0;i<10;i++) {
        arg[i].a = i; //caution you can't use compond literal to initialize here any more
        arg[i].b = i+1;
        arg[i].c = i+2;
        pthread_create(&my_thread[i],NULL,wrapper,(void*)&arg[i]); // pthread_create(pthread_t* your_thread_data_structure,NULL)
    }
    
    printf("The main thread finishes creating all threads!\n");

    for(int i=0;i<10;i++) {
        pthread_join(my_thread[i],NULL);
    }
}




int print_add(int a, int b, int c) {
    int res = a+b+c;
    printf("%d+%d+%d=%d\n",a,b,c,res);
    return res;
}

void* wrapper(void* aux) {
    struct arguments *arg = (struct arguments*) aux; // cast void* back to struct argument*
    print_add(arg->a,arg->b,arg->c);
    return NULL; // hey NULL can be treated as a void* type
}