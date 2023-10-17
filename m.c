#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_INCREMENTS 100

int counter = 0;
pthread_mutex_t mutex_counter = PTHREAD_MUTEX_INITIALIZER;

void *increment_counter(void *arg) {

    for (int i = 0; i < NUM_INCREMENTS; i++) {
        pthread_mutex_lock(&mutex_counter);
        counter++;
        pthread_mutex_unlock(&mutex_counter);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    if (pthread_create(&thread1, NULL, &increment_counter, NULL)) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &increment_counter, NULL)) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Expected counter value: %d\n", 2 * NUM_INCREMENTS);  

    printf("Final counter value: %d\n", counter);

    return 0;
}

