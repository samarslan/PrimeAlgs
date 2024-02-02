#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_THREADS 4

long long int number;
bool isPrime = true;
pthread_mutex_t lock;

void *checkPrime(void *threadId) {
    long long int start = (*((long long int *)threadId));

    for (long long int i = start; i < number; i += NUM_THREADS) {
        if (i >= 3) {
            pthread_mutex_lock(&lock);

            if (!isPrime) {
                pthread_mutex_unlock(&lock);
                pthread_exit(NULL);
            }

            if (number % i == 0) {
                isPrime = false;
                pthread_mutex_unlock(&lock);
                pthread_exit(NULL);
            }

            pthread_mutex_unlock(&lock);
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    long long int threadIds[NUM_THREADS];

    //scanf("%lld", &number);
    number = 11120933330250889;

    if (number <= 1) {
        isPrime = false;
    } else if (number == 2) {
        isPrime = true;
    } else {
        pthread_mutex_init(&lock, NULL);

        for (int i = 0; i < NUM_THREADS; i++) {
            threadIds[i] = i + 3; 
            pthread_create(&threads[i], NULL, checkPrime, (void *)&threadIds[i]);
        }

        for (int i = 0; i < NUM_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        pthread_mutex_destroy(&lock);
    }

    if (isPrime) {
        printf("\n%lld is prime\n", number);
    } else {
        printf("\n%lld is not prime\n", number);
    }

    return 0;
}
