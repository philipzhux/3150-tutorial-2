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
    pthread_t my_thread; // define the thread data structure
    struct arguments arg = {
        .a = 1,
        .b = 2,
        .c = 3
    };
    pthread_create(&my_thread,NULL,wrapper,(void*)&arg); // pthread_create(pthread_t* your_thread_data_structure,NULL)
    pthread_join(my_thread,NULL);
}




int print_add(int a, int b, int c) {
    int res = a+b+c;
    printf("the result is %d\n",res);
    return res;
}

void* wrapper(void* aux) {
    struct arguments *arg = (struct arguments*) aux; // cast void* back to struct argument*
    print_add(arg->a,arg->b,arg->c);
    return NULL; // hey NULL can be treated as a void* type
}