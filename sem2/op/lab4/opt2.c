#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define N 5

pthread_mutex_t forks[N];
pthread_t philosophers[N];

void *philosopher(void *arg) {
    int ph_id = *((int *)arg) + 1;

    // Index of the left and right forks
    int left_fork = ph_id - 1;  
    int right_fork = ph_id % N;

    printf("Philosopher %d sits on the chair %d \n", ph_id, ph_id);
    sleep(2); // Wait 2 sec

    while (1) {
        // Attempt to acquire left fork
        pthread_mutex_lock(&forks[left_fork]);
        if (pthread_mutex_trylock(&forks[right_fork]) == 0) {
            // Both forks acquired successfully
            printf("Philosopher %d picks forks: %d and %d\n", ph_id, left_fork + 1, right_fork + 1);
            sleep(2);

            printf("Philosopher %d eats for 5 sec.\n", ph_id);
            sleep(5);

            // Release both forks
            pthread_mutex_unlock(&forks[left_fork]);
            pthread_mutex_unlock(&forks[right_fork]);
            printf("Philosopher %d puts forks: %d and %d\n", ph_id, left_fork + 1, right_fork + 1);
            sleep(2);
            printf("Philosopher %d leaves\n", ph_id);
            break; // Exit the loop after eating
        } else {
            // Release left fork if right fork is not available
            pthread_mutex_unlock(&forks[left_fork]);
        }
        usleep(10);
    }

    return NULL;
}

int main() {
    // Initialize mutexes (forks)
    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Wait for all philosophers to finish
    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes (forks)
    for (int i = 0; i < N; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
