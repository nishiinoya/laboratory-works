#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024

int main() {
    const char *fifo_name = "/tmp/fibonacci_fifo";
    int fd;
    char buf[MAX_BUF];
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    fd = open(fifo_name, O_WRONLY);
    sprintf(buf, "%d", n);

    write(fd, buf, MAX_BUF);
    close(fd);
    unlink(fifo_name);
    return 0;
}
