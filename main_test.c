#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

#include "base/batch.h"
#include "base/batch_for_test.h"

int main(int argc, char **argv)
{
    clock_t start_time = clock(); // tempo

    struct rusage r_usage; // memoria

    if (argc == 4)
    {
        batch_for_test(argv[1], argv[2], argv[3]);
    }
    else
    {
        printf("Error");
        return 1;
    }

    // tempo
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\n\nTime taken: %f seconds\n", elapsed_time);

    // memoria
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n\n", r_usage.ru_maxrss);

    return 0;
}
