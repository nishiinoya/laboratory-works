#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

sem_t semaphore;
char buffer[BUFFER_SIZE];

void *write_to_file(void *arg) {
    while (1) {
        sem_wait(&semaphore);
        printf("Writing to file...\n");
        FILE *file = fopen("data.txt", "a");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fputs(buffer, file);
        fclose(file);
        sem_post(&semaphore);
        usleep(1000000); 
    }
}

void *read_from_file(void *arg) {
    while (1) {
        sem_wait(&semaphore);
        printf("Reading from file...\n");
        FILE *file = fopen("data.txt", "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        char read_buffer[BUFFER_SIZE];
        fgets(read_buffer, BUFFER_SIZE, file);
        printf("Read: %s\n", read_buffer);
        fclose(file);
        sem_post(&semaphore);
        usleep(2000000); 
    }
}

int main() {
    pthread_t write_thread, read_thread;
    sem_init(&semaphore, 0, 1);

    pthread_create(&write_thread, NULL, write_to_file, NULL);
    pthread_create(&read_thread, NULL, read_from_file, NULL);

    pthread_join(write_thread, NULL);
    pthread_join(read_thread, NULL);

    sem_destroy(&semaphore);

    return 0;
}
