#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
#include <unistd.h>

void signal_handler(int signal) {
    switch (signal) {
    case SIGUSR1:
        syslog(LOG_INFO, "Received SIGUSR1 signal");
        break;
    case SIGINT:
        syslog(LOG_INFO, "Received SIGINT signal. Exiting...");
        exit(EXIT_SUCCESS);
        break;
    }
}

int main() {
    pid_t pid, sid; 

    pid = fork();
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0); 
    sid = setsid(); 
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    signal(SIGUSR1, signal_handler);
    signal(SIGINT, signal_handler);

    while (1) {
        // Do
        sleep(1);
    }

    exit(EXIT_SUCCESS);
}