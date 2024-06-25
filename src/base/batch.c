#include "base/batch.h"

#include <glib.h>

int batch(char *argv1, char *argv2)
{
    // Catalogs and stats part
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
    
    while (getline(&line, &len, file) != -1)
    {
         acc++;

        char outputFileLocation[100];
        sprintf(outputFileLocation, "Resultados/command%d_output.txt", acc);

    
        sscanf(line, "%4s %49[^\n]", query_num, args_for_query);
        if (strcmp(query_num, "9") == 0)
        {
            
            query9(users_catalog, args_for_query, outputFileLocation);
            
        }
        if (strcmp(query_num, "9F") == 0)
        {
            
            query9F(users_catalog, args_for_query, outputFileLocation);
            
        }
        
        if (strcmp(query_num, "1") == 0)
        {
            
            query1(args_for_query, reservations_catalog, users_catalog, flights_catalog, outputFileLocation);
            
        }
        if (strcmp(query_num, "1F") == 0)
        {
            
            query1F(args_for_query, reservations_catalog, users_catalog, flights_catalog, outputFileLocation);
            
        }
        
        if (strcmp(query_num, "3") == 0)
        {
            query3(args_for_query, hotels_catalog, outputFileLocation);
        }
        if (strcmp(query_num, "3F") == 0)
        {
            query3F(args_for_query, hotels_catalog, outputFileLocation);
        }
        if (strcmp(query_num, "8") == 0)
        {
            
            query8(reservations_catalog, args_for_query, acc);
            
        }
        if (strcmp(query_num, "8F") == 0)
        {
           
            query8F(reservations_catalog, args_for_query, acc);
             
        }
        if (strcmp(query_num, "4") == 0)
        {
            
            query4(args_for_query, reservations_catalog, outputFileLocation);
            
        }
        if (strcmp(query_num, "4F") == 0)
        {
            
            query4F(args_for_query, reservations_catalog, outputFileLocation);
        
        }
        if (strcmp(query_num, "5") == 0)
        {
            query5(flights_catalog, args_for_query, outputFileLocation);
        }
        if (strcmp(query_num, "5F") == 0)
        {
            query5f(flights_catalog, args_for_query, outputFileLocation);
        }
        
        if (strcmp(query_num, "6") == 0)
        {
            execute_query6(flights_catalog, args_for_query, outputFileLocation);
        }
        
        if (strcmp(query_num, "6F") == 0)
        {
            execute_query6f(flights_catalog, args_for_query, outputFileLocation); 
        }

        /*if (strcmp(query_num, "2") == 0)
        {
            printf("EDEDE\n");
            query2(args_for_query, reservations_catalog, users_catalog, flights_catalog, outputFileLocation); // args for query??
            printf("FORA\n");
        } */
        // if (strcmp(query_num, "2F") == 0)
        // {
        //     query2F(args_for_query, reservations_catalog, users_catalog, flights_catalog, outputFileLocation);
        // }
        /*
        
        if (strcmp(query_num, "7") == 0)
        {
            query7(args_for_query, flights_catalog, outputFileLocation);
        }
        */
    }
    
    fclose(file);
    free(line);

    free_flights_catalog(flights_catalog);
    free_reservations_catalog(reservations_catalog);
    free_users_catalog(users_catalog);
    free_hotels_catalog(hotels_catalog);

    return 0;
}
