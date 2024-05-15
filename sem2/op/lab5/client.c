#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_NAME "./variant2_malanchuk"

int main() {
    FILE *f;
    int num;

    mkfifo(FIFO_NAME, 0600);

    f = fopen(FIFO_NAME, "w");

    if (f == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    printf("Enter an integer: ");
    scanf("%d", &num);

    fprintf(f, "%d\n", num);
    fflush(f);

    fclose(f);
    unlink(FIFO_NAME);
    return 0;
}
