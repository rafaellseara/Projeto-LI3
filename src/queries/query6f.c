#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "queries/query6.h"
#include "catalogs/catalog_flights.h"
#include "entities/flight.h"
#include "utils/stats.h"


void execute_query6f(FLIGHTS_CATALOG catalog, char *parameters, char *output)
{
    //---------------------ESCREVER FICHEIRO---------------------
    FILE *outputFile = fopen(output, "w");
    char query6_path[60];
    char numero[10]; 

    sscanf(parameters, "%3s \"%[^\"]\" \"%[^\"]\"", query6_path, numero);
    
    GArray *resultados = g_array_new(FALSE, sizeof(FLIGHT), sizeof(AIRPORT));

    void insert_airport(GHashTable *catalogo, AIRPORT airport, char *key); // not sure

    g_array_sort(resultados, comparativo); 

    //------------------------------------------------------------
    char *ano, *quantidade;
    ano = strsep(&parameters, " ");
    quantidade = (parameters != NULL) ? parameters : "";
    //------------------------------------------------------------


    GHashTable *airports = create_airports_catalog();
    char origem[4];
    char destino[4];

    information_query6(catalog, airports, origem, destino, ano);

    //------------------------------------------------------------

    GHashTableIter iter2;
    gpointer key2, value2;

    GArray *listaAirports = g_array_new(FALSE, FALSE, sizeof(gchar *));

    g_hash_table_iter_init(&iter2, airports);

    while (g_hash_table_iter_next(&iter2, &key2, &value2))
    {
        AIRPORT novo_airport = (AIRPORT)value2;
        g_array_append_val(listaAirports, novo_airport);
    }

    //------------------------------------------------------------

    g_array_sort(listaAirports, comparativo);

    //------------------------------------------------------------
    int z=1;
    for (int i = 0; i < atoi(quantidade) && i<(listaAirports->len); i++)
    {
            AIRPORT line = g_array_index(listaAirports, AIRPORT, i);

            char *nome_aero = get_airport_name(line);
            fprintf(outputFile, "--- %d ---\n", z);
            fprintf(outputFile, "%s;%d\n", nome_aero, get_airport_num_pass(line));  
            free(nome_aero);
            i++;
            z++;
    }

g_hash_table_destroy(airports);
fclose(outputFile);
}
