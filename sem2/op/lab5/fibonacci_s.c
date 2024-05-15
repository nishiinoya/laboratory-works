#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    const char *fifo_name = "/tmp/fibonacci_fifo";
    int fd;
    char buf[MAX_BUF];

    mkfifo(fifo_name, 0666);

    printf("Waiting for data...\n");
    fd = open(fifo_name, O_RDONLY);
    read(fd, buf, MAX_BUF);
    int n = atoi(buf);
    close(fd);

    int result = fibonacci(n);

    printf("Fibonacci number of %d: %d\n", n, result);

    unlink(fifo_name);

    return 0;
}
