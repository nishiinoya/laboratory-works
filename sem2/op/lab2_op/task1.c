#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int opt;
    char *program = NULL;
    int w_flag = 0;
    int f_flag = 0;

    while ((opt = getopt(argc, argv, "wf")) != -1) {
        switch (opt) {
        case 'w':
            w_flag = 1;
            break;
        case 'f':
            f_flag = 1;
            break;
        default:
            fprintf(stderr, "Usage: %s [-w|-f] executable-filename\n", argv[0]);
            return 1;
        }
    }
    program = argv[optind];
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) { 
        if (execlp(program, program, NULL) == -1) {
            perror("Exec failed");
            return 1;
        }
    } else {   
        if (f_flag) {
            printf("Program %s started asynchronously.\n", program);
        }
        if (w_flag) {
            int status;
            if (waitpid(pid, &status, 0) == -1) {
                perror("Wait failed");
                return 1;
            }

            if (WIFEXITED(status)) {
                printf("Program %s completed with return code: %d\n", program, WEXITSTATUS(status));
            } else {
                printf("Program %s terminated abnormally\n", program);
            }
        }
    }
    return 0;
}
