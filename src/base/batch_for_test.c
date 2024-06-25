#include "base/batch_for_test.h"

int batch_for_test(char *argv1, char *argv2, char *argv3)
{
    clock_t start_time_parse = clock();
    struct rusage r_usage;

    FLIGHTS_CATALOG flights_catalog = create_flight_catalog();
    RESERVATIONS_CATALOG reservations_catalog = create_reservation_catalog();
    USERS_CATALOG users_catalog = create_users_catalog();
    HOTELS_CATALOG hotels_catalog = create_hotel_catalog();

    char file_location_users[100];
    strcpy(file_location_users, argv1);
    strcat(file_location_users, "/users.csv");

    char file_location_reservations[100];
    strcpy(file_location_reservations, argv1);
    strcat(file_location_reservations, "/reservations.csv");

    char file_location_flights[100];
    strcpy(file_location_flights, argv1);
    strcat(file_location_flights, "/flights.csv");

    char file_location_passengers[100];
    strcpy(file_location_passengers, argv1);
    strcat(file_location_passengers, "/passengers.csv");

    parse_file_users(file_location_users, users_catalog);
    parse_file_reservations(file_location_reservations, reservations_catalog, users_catalog, hotels_catalog);
    parse_file_flights(file_location_flights, flights_catalog);
    parse_file_passengers(file_location_passengers, flights_catalog, users_catalog);
    
    clock_t end_time = clock();
    double elapsed_time_parse = ((double)(end_time - start_time_parse)) / CLOCKS_PER_SEC;
    printf(ANSI_COLOR_GREEN "Time taken for parser: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_parse);
    getrusage(RUSAGE_SELF, &r_usage);
    printf(ANSI_COLOR_BLUE "Memory usage for parser: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);

    FILE *file;
    char *line = NULL;
    size_t len = 0;

    file = fopen(argv2, "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return 1;
    }

    char args_for_query[50];
    char query_num[5];
    int acc = 0;

    double array_of_average[9] = {0};
    int array_of_num[9] = {0};

    while (getline(&line, &len, file) != -1)
    {
        acc++;

        char outputFileLocation[100];
        sprintf(outputFileLocation, "Resultados/command%d_output.txt", acc);

        sscanf(line, "%4s %49[^\n]", query_num, args_for_query);

        if (strcmp(query_num, "1") == 0)
        {
            printf(ANSI_COLOR_RED "Query 1 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q1 = clock();
            struct rusage r_usage;
            query1(args_for_query, reservations_catalog, users_catalog, flights_catalog, outputFileLocation);
            clock_t end_time_q1 = clock();
            double elapsed_time_q1 = ((double)(end_time_q1 - start_time_q1)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 1: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q1);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 1: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[0] += elapsed_time_q1;
            array_of_num[0]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "1F") == 0)
        {
            printf(ANSI_COLOR_RED "Query 1F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q1f = clock();
            struct rusage r_usage;
            query1F(args_for_query, reservations_catalog, users_catalog, flights_catalog, outputFileLocation);
            clock_t end_time_q1f = clock();
            double elapsed_time_q1f = ((double)(end_time_q1f - start_time_q1f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 1F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q1f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 1F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[0] += elapsed_time_q1f;
            array_of_num[0]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "3") == 0)
        {
            printf(ANSI_COLOR_RED "Query 3 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q3 = clock();
            struct rusage r_usage;
            query3(args_for_query, hotels_catalog, outputFileLocation);
            clock_t end_time_q3 = clock();
            double elapsed_time_q3 = ((double)(end_time_q3 - start_time_q3)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 3: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q3);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 3: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[2] += elapsed_time_q3;
            array_of_num[2]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "3F") == 0)
        {
            printf(ANSI_COLOR_RED "Query 3F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q3f = clock();
            struct rusage r_usage;
            query3F(args_for_query, hotels_catalog, outputFileLocation);
            clock_t end_time_q3f = clock();
            double elapsed_time_q3f = ((double)(end_time_q3f - start_time_q3f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 3F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q3f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 3F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[2] += elapsed_time_q3f;
            array_of_num[2]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "4") == 0)
        {
            printf(ANSI_COLOR_RED "Query 4 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q4 = clock();
            struct rusage r_usage;
            query4(args_for_query, reservations_catalog, outputFileLocation);
            clock_t end_time_q4 = clock();
            double elapsed_time_q4 = ((double)(end_time_q4 - start_time_q4)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 4: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q4);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 4: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[3] += elapsed_time_q4;
            array_of_num[3]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "4F") == 0)
        {
            printf(ANSI_COLOR_RED "Query 4F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q4f = clock();
            struct rusage r_usage;
            query4F(args_for_query, reservations_catalog, outputFileLocation);
            clock_t end_time_q4f = clock();
            double elapsed_time_q4f = ((double)(end_time_q4f - start_time_q4f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 4F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q4f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 4F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[3] += elapsed_time_q4f;
            array_of_num[3]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "5") == 0)
        {
            printf(ANSI_COLOR_RED "Query 5 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q5 = clock();
            struct rusage r_usage;
            query5(flights_catalog, args_for_query, outputFileLocation);
            clock_t end_time_q5 = clock();
            double elapsed_time_q5 = ((double)(end_time_q5 - start_time_q5)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 5: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q5);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 5: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[4] += elapsed_time_q5;
            array_of_num[4]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "5F") == 0)
        {
            printf(ANSI_COLOR_RED "Query 5F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q5f = clock();
            struct rusage r_usage;
            query5f(flights_catalog, args_for_query, outputFileLocation);
            clock_t end_time_q5f = clock();
            double elapsed_time_q5f = ((double)(end_time_q5f - start_time_q5f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 5F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q5f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 5F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[4] += elapsed_time_q5f;
            array_of_num[4]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "6") == 0){
            printf(ANSI_COLOR_RED "Query 6 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q6 = clock();
            struct rusage r_usage;
            execute_query6(flights_catalog, args_for_query, outputFileLocation);
            clock_t end_time_q6 = clock();
            double elapsed_time_q6 = ((double)(end_time_q6 - start_time_q6)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 6: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q6);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 6: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[5] += elapsed_time_q6;
            array_of_num[5]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "6F") == 0){
            printf(ANSI_COLOR_RED "Query 6F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q6f = clock();
            struct rusage r_usage;
            execute_query6f(flights_catalog, args_for_query, outputFileLocation);
            clock_t end_time_q6f = clock();
            double elapsed_time_q6f = ((double)(end_time_q6f - start_time_q6f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 6F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q6f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 6F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[5] += elapsed_time_q6f;
            array_of_num[5]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "8") == 0)
        {
            printf(ANSI_COLOR_RED "Query 8 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q8 = clock();
            struct rusage r_usage;
            query8(reservations_catalog, args_for_query, acc);
            clock_t end_time_q8 = clock();
            double elapsed_time_q8 = ((double)(end_time_q8 - start_time_q8)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 8: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q8);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 8: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[7] += elapsed_time_q8;
            array_of_num[7]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "8F") == 0)
        {
            printf(ANSI_COLOR_RED "Query 8F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q8f = clock();
            struct rusage r_usage;
            query8F(reservations_catalog, args_for_query, acc);
            clock_t end_time_q8f = clock();
            double elapsed_time_q8f = ((double)(end_time_q8f - start_time_q8f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 8F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q8f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 8F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[7] += elapsed_time_q8f;
            array_of_num[7]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "9") == 0)
        {
            printf(ANSI_COLOR_RED "Query 9 with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q9 = clock();
            struct rusage r_usage;
            query9(users_catalog, args_for_query, outputFileLocation);
            clock_t end_time_q9 = clock();
            double elapsed_time_q9 = ((double)(end_time_q9 - start_time_q9)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 9: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q9);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 9: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[8] += elapsed_time_q9;
            array_of_num[8]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }

        if (strcmp(query_num, "9F") == 0)
        {
            printf(ANSI_COLOR_RED "Query 9F with input %s\n" ANSI_COLOR_RED, args_for_query);
            clock_t start_time_q9f = clock();
            struct rusage r_usage;
            query9F(users_catalog, args_for_query, outputFileLocation);
            clock_t end_time_q9f = clock();
            double elapsed_time_q9f = ((double)(end_time_q9f - start_time_q9f)) / CLOCKS_PER_SEC;
            printf(ANSI_COLOR_GREEN "Time taken for query 9F: %f seconds\n" ANSI_COLOR_RESET, elapsed_time_q9f);
            getrusage(RUSAGE_SELF, &r_usage);
            printf(ANSI_COLOR_BLUE "Memory usage for query 9F: %ld KB\n" ANSI_COLOR_RESET, r_usage.ru_maxrss);
            array_of_average[8] += elapsed_time_q9f;
            array_of_num[8]++;

            char outputFileLocationForTest[100];
            snprintf(outputFileLocationForTest, sizeof(outputFileLocationForTest), "%s/command%d_output.txt", argv3, acc);

            int result = compareFiles(outputFileLocation, outputFileLocationForTest);
            if (result == 0)
            {
                printf(ANSI_COLOR_MAGENTA "Query passed the test\n\n" ANSI_COLOR_RESET);
            }
            else if (result == -1)
            {
                printf(ANSI_COLOR_MAGENTA "Error reading files!\n\n" ANSI_COLOR_RESET);
            }
            else
            {
                printf(ANSI_COLOR_MAGENTA "Error on line %d\n\n" ANSI_COLOR_RESET, result);
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        double result = array_of_average[i] / array_of_num[i];
        if (i % 2 == 0)
        {
            printf(ANSI_COLOR_CYAN "Query %d with an average of %fs\n" ANSI_COLOR_RESET, i + 1, result);
        }
        else
        {
            printf(ANSI_COLOR_MAGENTA "Query %d with an average of %fs\n" ANSI_COLOR_RESET, i + 1, result);
        }
    }

    fclose(file);
    free(line);

    free_flights_catalog(flights_catalog);
    free_reservations_catalog(reservations_catalog);
    free_users_catalog(users_catalog);
    free_hotels_catalog(hotels_catalog);

    return 0;
}