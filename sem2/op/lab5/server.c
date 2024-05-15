#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_NAME "./variant2_malanchuk"


long long fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else {
        long long a = 0;
        long long b = 1;
        for (int i = 2; i <= n; i++) {
            long long c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

int main() {
    FILE *f;
    char ch;
    int num = 0;
    f = fopen(FIFO_NAME, "r");

    if (f == NULL) {
        printf("Error open file\n");
        return -1;
    }
    printf("Waiting for data...\n");
    do {
        ch = fgetc(f);
        if (ch >= '0' && ch <= '9') {
            num = num * 10 + (ch - '0');
        } else {
            printf("Invalid character in file.\n");
            fclose(f);
            return 1;
        }
    } while (ch != '\n');

    long long fib = fibonacci(num);
    printf("Fibonacci number of %d is %lld\n", num, fib);

    fclose(f);
    unlink(FIFO_NAME);
    return 0;
}
