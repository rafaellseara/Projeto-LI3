#include "queries/query5f.h"
#include "catalogs/catalog_flights.h"
#include "entities/flight.h"
#include "utils/stats.h"
#include <stdio.h>
#include <stdlib.h>

void query5f(FLIGHTS_CATALOG catalog, char *parameters, char *output)
{

    FILE *outputFile = fopen(output, "w");
    char aeroport[4];    // Tamanho suficiente para armazenar "LIS" e o caractere nulo
    char begin_date[20]; // Tamanho suficiente para armazenar a data e o caractere nulo
    char end_date[20];   // Tamanho suficiente para armazenar a data e o caractere nulo

    // Usando sscanf para analisar a string com o formato fornecido
    sscanf(parameters, "%3s \"%[^\"]\" \"%[^\"]\"", aeroport, begin_date, end_date);
   
    GArray *resultados = g_array_new(FALSE, FALSE, sizeof(FLIGHT));

    information_query5(parameters, catalog, resultados);
    // primeiro tenho de ordenar o array QSORT
    //  depois tenho de dentro do array selecionar o que necessito e depois dar fprintf disso e de seguida dar free ao array dos resultados
    g_array_sort(resultados, comparacao_FLIGHTS);

    int i = 0;
    int y=1;
    while (i < resultados->len)
    {
        FLIGHT fli = g_array_index(resultados, FLIGHT, i);
        int id = getIdFlights(fli);
        char *destination=getDestination(fli);
        char *schedule_departure_date=getScheduleDepartureDate(fli);
        char *airline=getAirline(fli);
        char *plane_model=getPlaneModel(fli);
        char *id_copy[20];
        sprintf(id_copy, "%0*d", 10, id);
        
    
        if (i==(resultados->len)-1)
        {
            fprintf(outputFile, "--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n",
                    y, id_copy, schedule_departure_date, destination, airline, plane_model);
        }
        else
        {
             fprintf(outputFile, "--- %d ---\nid: %s\nschedule_departure_date: %s\ndestination: %s\nairline: %s\nplane_model: %s\n\n",
                    y, id_copy, schedule_departure_date, destination, airline, plane_model);

        }
        
        
        free(destination);
        free(schedule_departure_date);
        free(airline);
        free(plane_model);

        y++;
        i++;  
    }
    g_array_free(resultados, TRUE);
    fclose(outputFile);
}


