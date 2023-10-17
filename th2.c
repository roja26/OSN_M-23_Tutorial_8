#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

void *print_numbers(void *arg) {
    for (int i = 1; i <= 5; i++) {
        printf("Number: %d\n", i);
        sleep(1);
    }
    return NULL;
}

void *print_letters(void *arg) {
    char letters[] = "abcde";
    for (int i = 0; i < 5; i++) {
        printf("Letter: %c\n", letters[i]);
        sleep(5);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    if (pthread_create(&thread1, NULL, &print_numbers, NULL)) {
        fprintf(stderr, "Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &print_letters, NULL)) {
        fprintf(stderr, "Error creating thread 2\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
