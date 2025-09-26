#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

int balance = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* worker_no_lock(void* arg) {
    // Race condition version - for comparison
    balance++;
    balance++;
    return NULL;
}

void* worker_partial_lock(void* arg) {
    // Only one update protected - still has race condition
    pthread_mutex_lock(&lock);
    balance++;
    pthread_mutex_unlock(&lock);
    
    balance++; // This line is unprotected - race condition remains
    return NULL;
}

void* worker_full_lock(void* arg) {
    // Both updates protected - no race condition
    pthread_mutex_lock(&lock);
    balance++;
    balance++;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;
    int choice = 1; // Default to race condition version
    
    if (argc > 1) {
        choice = atoi(argv[1]);
    }
    
    printf("Running test case %d:\n", choice);
    
    switch(choice) {
        case 1:
            printf("Case 1: Race condition (no locks)\n");
            balance = 0;
            pthread_create(&p1, NULL, worker_no_lock, NULL);
            pthread_create(&p2, NULL, worker_no_lock, NULL);
            break;
            
        case 2:
            printf("Case 2: Partial lock (still has race)\n");
            balance = 0;
            pthread_create(&p1, NULL, worker_partial_lock, NULL);
            pthread_create(&p2, NULL, worker_partial_lock, NULL);
            break;
            
        case 3:
            printf("Case 3: Full lock (no race)\n");
            balance = 0;
            pthread_create(&p1, NULL, worker_full_lock, NULL);
            pthread_create(&p2, NULL, worker_full_lock, NULL);
            break;
            
        default:
            printf("Invalid choice. Use 1, 2, or 3\n");
            return 1;
    }
    
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    printf("Final balance: %d (expected: 4)\n", balance);
    
    return 0;
}