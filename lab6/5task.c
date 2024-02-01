#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randNum(double *pa, int n)
{
    for (double *p = pa; p < pa + n; p++)
    {
        *p = (rand() % 100000) / 1000.0;
    }
}

double find_min(double *pa, int n)
{
    double min = pa[0];
    for (double *p = pa; p < pa + n; p++)
    {
        if (*p < min)
        {
            min = *p;
        }
    }

    return min;
}

double find_max(double *pa, int n)
{
    double max = pa[0];

    for (double *p = pa; p < pa + n; p++)
    {
        if (*p > max)
        {
            max = *p;
        }
    }

    return max;
}

void print_arr(double *pa, int n)
{
    for (double *p = pa; p < pa + n; p++)
    {
        printf("%lf ", *p);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    double *pa = (double *)malloc(n * sizeof(double));

    if (pa == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    randNum(pa, n);
    print_arr(pa, n);
    double minValue = find_min(pa, n);
    double maxValue = find_max(pa, n);
    free(pa);

    FILE *result = fopen("task5results.txt", "w");

    if (result == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    fprintf(result, "minimum: %lf\n", minValue);
    fprintf(result, "maximum: %lf\n", maxValue);
    fprintf(result, "sum of min and max: %lf", minValue + maxValue);

    fclose(result);
    return 0;
}
