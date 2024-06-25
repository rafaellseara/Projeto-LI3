#include <stdio.h>
#include "parser/parser.h"

void parse_file_passengers(char *filename, FLIGHTS_CATALOG catalog_flights, USERS_CATALOG catalog_users)
{
    FILE *file;
    FILE *file_error;
    char line[1000];
    char line_copy[1000];
    file_error = fopen("Resultados/passengers_errors.csv", "w");

    if (file_error == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, sizeof(line), file) != NULL)
        fprintf(file_error, "%s", line);

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char *line_ptr = line;
        strcpy(line_copy, line);
        int i = 0;
        char *token;
        token = strsep(&line_ptr, ";");

        int flight_id;
        char user_id[50];
        char copy_flight[50];

        while (token != NULL)
        {
            switch (i)
            {
            case 0:
                flight_id = strtol(token, NULL, 10);
                strcpy(copy_flight, token);
                break;
            case 1:
                strcpy(user_id, token);
                size_t len = strlen(user_id);
                user_id[len-1] = '\0';
                break;
            }
            token = strsep(&line_ptr, ";");
            i++;
        }

        if (!is_flight_on_the_table(catalog_flights, flight_id) || !is_user_on_the_table(catalog_users, user_id))
        {
            fprintf(file_error, "%s", line_copy);
        }
        else
        {
            if (strcmp(user_id, "") != 0)
            {
                if (is_flight_on_the_table(catalog_flights, flight_id)){
                    setNumPass(get_flight_by_id(catalog_flights, flight_id));
                }
                if (is_user_on_the_table(catalog_users, user_id)){
                    set_user_flight_list(get_user_by_id(catalog_users, user_id), copy_flight);
                }
            }
        }
        
        
    }

    fclose(file);
    fclose(file_error);
}

void parse_file_flights(char *filename, FLIGHTS_CATALOG catalog)
{
    FILE *file;
    FILE *file_error;
    char line[1000];
    char line_copy[1000];
    file_error = fopen("Resultados/flights_errors.csv", "w");

    if (file_error == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, sizeof(line),file) != NULL)
        fprintf(file_error, "%s", line);

    while (fgets(line, sizeof(line),file) != NULL)
    {
        strcpy(line_copy, line);
        if (is_flight_valid(line))
            build_flight(line_copy, catalog);

        else
        {
            fprintf(file_error, "%s", line_copy);
        }
    }

    fclose(file);
    fclose(file_error);
}

void parse_file_reservations(char *filename, RESERVATIONS_CATALOG catalog, USERS_CATALOG catalog_users, HOTELS_CATALOG hotels_catalog)
{
    FILE *file;
    FILE *file_error;
    char line[1000];
    char line_copy[1000];
    char line_copy_2[1000];
    file_error = fopen("Resultados/reservations_errors.csv", "w");

    if (file_error == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, sizeof(line),file) != NULL)
        fprintf(file_error, "%s", line);

    while (fgets(line, sizeof(line),file) != NULL)
    {
        strcpy(line_copy, line);
        strcpy(line_copy_2, line);
        if (is_reservation_valid(line, catalog_users))
        {
            build_reservation(line_copy, catalog, catalog_users);
            
            build_hotel(hotels_catalog, line_copy_2);
           
        }
        else
            fprintf(file_error, "%s", line_copy);
    }

    fclose(file);
    fclose(file_error);
}

void parse_file_users(char *filename, USERS_CATALOG catalog)
{
    FILE *file;
    FILE *file_error;
    char line[1000];
    char line_copy[1000];
    file_error = fopen("Resultados/users_errors.csv", "w");

    if (file_error == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (fgets(line, sizeof(line),file) != NULL)
        fprintf(file_error, "%s", line);

    while (fgets(line, sizeof(line),file) != NULL)
    {
        strcpy(line_copy, line);
        if (is_user_valid(line) == 1)
        {
            build_user(line_copy, catalog);
        }
        else
            fprintf(file_error, "%s", line_copy);
    }

    fclose(file);
    fclose(file_error);
}