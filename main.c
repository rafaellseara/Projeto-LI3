#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

#include "base/batch.h"
#include "base/interactive.h"

int main(int argc, char **argv)
{
    clock_t start_time = clock(); // tempo

    struct rusage r_usage; // memoria

    if (argc == 3)
    {
        batch(argv[1], argv[2]);
    }
    else if (argc == 1)
    {
        menu();
    }
    else
    {
        printf("Error");
        return 1;
    }

    // tempo
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", elapsed_time);

    // memoria
    getrusage(RUSAGE_SELF, &r_usage);
    printf("Memory usage: %ld KB\n", r_usage.ru_maxrss);

 

    return 0;
}
