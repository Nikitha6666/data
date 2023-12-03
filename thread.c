#include <stdio.h>
#include <pthread.h>

// Function to be executed by the first thread
void* threadOneFunction(void* arg) {
    printf("This is thread one\n");
    return NULL;
}

// Function to be executed by the second thread
void* threadTwoFunction(void* arg) {
    printf("This is thread two\n");
    return NULL;
}

int main() {
    pthread_t threadOne, threadTwo;

    // Create the first thread
    if (pthread_create(&threadOne, NULL, threadOneFunction, NULL) != 0) {
        perror("Error creating thread one");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&threadTwo, NULL, threadTwoFunction, NULL) != 0) {
        perror("Error creating thread two");
        return 1;
    }

    // Wait for the first thread to finish
    if (pthread_join(threadOne, NULL) != 0) {
        perror("Error joining thread one");
        return 1;
    }

    // Wait for the second thread to finish
    if (pthread_join(threadTwo, NULL) != 0) {
        perror("Error joining thread two");
        return 1;
    }

    return 0;
}
