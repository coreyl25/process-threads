#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int balance = 0;

void* worker(void* arg) {
    // Create race condition
    balance++; // read, increment, and write
    balance++; 
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    
    printf("Initial balance: %d\n", balance);
    
    // Create two threads that will race to modify balance
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    
    // Wait for both threads to complete
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    printf("Final balance: %d\n", balance);
    printf("Expected: 4, but due to race condition, result may vary\n");
    
    return 0;
}