#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 256

pthread_mutex_t lock;
pthread_cond_t condition;
char buffer[BUFFER_SIZE];
int data_ready = 0;

void *write_to_file(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        printf("Writing to file...\n");
        FILE *file = fopen("data.txt", "a");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        fputs(buffer, file);
        fclose(file);
        data_ready = 1;
        pthread_cond_signal(&condition);
        pthread_mutex_unlock(&lock);
        usleep(1000000); // Sleep for 1 second
    }
}

void *read_from_file(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        while (!data_ready) {
            pthread_cond_wait(&condition, &lock);
        }
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
        data_ready = 0;
        pthread_mutex_unlock(&lock);
        usleep(2000000); // Sleep for 2 seconds
    }
}

int main() {
    pthread_t write_thread, read_thread;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&condition, NULL);

    pthread_create(&write_thread, NULL, write_to_file, NULL);
    pthread_create(&read_thread, NULL, read_from_file, NULL);

    pthread_join(write_thread, NULL);
    pthread_join(read_thread, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&condition);

    return 0;
}
