#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
	int opt;
	int w_flag = 0;
	int f_flag = 0;

	// geting flags
	while ((opt = getopt(argc, argv, "wf")) != -1) {
		switch (opt) {
			case 'w':
				w_flag = 1;
				break;
			case 'f':
				f_flag = 1;
				break;
			default:
				fprintf(stderr, "Usage: %s [-w|-f] exe-filename\n", argv[0]);
				exit(EXIT_FAILURE);
		}
	}

	// checking flags
	if ((w_flag && f_flag) || (!w_flag && !f_flag)) {
		fprintf(stderr, "Usage: %s [-w|-f] exe-filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// checking exe
	if (optind >= argc) {
		fprintf(stderr, "Usage: %s [-w|-f] exe-filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	// making process
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		if (execvp(argv[optind], &argv[optind]) == -1) {
			perror("execvp failed");
			exit(EXIT_FAILURE);
		}
	} else {
		int status;

		if (w_flag) {
			waitpid(pid, &status, 0);
			if (WIFEXITED(status)) {
				printf("Child process terminated with exit code: %d\n", WEXITSTATUS(status));
			} else {
				printf("Child process terminated not normal\n");
			}
		}

		if (f_flag) {
			printf("Child process started asynchronously with PID: %d\n", pid);
		}
	}


	return 0;
}

