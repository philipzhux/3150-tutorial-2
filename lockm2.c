#include <stdio.h>
#include <pthread.h>

int x= 0;

void* fun(void* in)
{
    int i;
    for ( i = 0; i < 10000000; i++ )
    {
        x++; // seems like a line of code huh?
    }
}

int main()
{
    pthread_t t1, t2;
    printf("Point 1 >> X is: %d\n", x);

    pthread_create(&t1, NULL, fun, NULL);
    pthread_create(&t2, NULL, fun, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Point 2 >> X is: %d\n", x);
    return 0;
}