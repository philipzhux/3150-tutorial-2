#include <stdio.h>
#include <pthread.h>

int x= 0;
pthread_mutex_t mu;

void* fun(void* in)
{
    int i;
    for ( i = 0; i < 10000000; i++ )
    {
        pthread_mutex_lock(&mu);
        x++; // seems like a line of code huh?
        pthread_mutex_unlock(&mu);
    }
}

int main()
{
    pthread_t t1, t2;
    pthread_mutex_init(&mu,NULL);
    printf("Point 1 >> X is: %d\n", x);
    

    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Point 2 >> X is: %d\n", x);
    return 0;
}