#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "queries/query6.h"
#include "catalogs/catalog_flights.h"
#include "entities/flight.h"
#include "utils/stats.h"

gint comparativo(gconstpointer a, gconstpointer b)
{
    // AEROPORTO A comparacao
   const AIRPORT aeroportoi = *(const AIRPORT *)a;
   const AIRPORT aeroportoii = *(const AIRPORT *)b;
   char *aeroi_name = get_airport_name(aeroportoi);
   char *aeroii_name = get_airport_name(aeroportoii);
   int resultado;

    int result =  get_airport_num_pass(aeroportoi) - get_airport_num_pass(aeroportoii);
    if (result == 0)
    {
        resultado = strcmp(aeroi_name, aeroii_name);
    }
    else resultado = -result;

    free(aeroi_name);
    free(aeroii_name);
return resultado;
}

int busca_ano(char *data1)
{
    int ano1, mes1, dia1, hora1, minuto1, segundo1;
    sscanf(data1, "%d/%d/%d %d:%d:%d", &ano1, &mes1, &dia1, &hora1, &minuto1, &segundo1);

    return ano1;
}

GHashTable *create_airports_catalog()
{
    GHashTable *catalogo_airport = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, g_free);
    return catalogo_airport;
}

void insert_airport(GHashTable *catalogo, AIRPORT airport, char *key)
{
    g_hash_table_insert(catalogo, key, GINT_TO_POINTER(airport));
}



void build_airport(GHashTable *catalogo, char *airport_name, int num)
{
    AIRPORT airport = create_airport();

    set_airport_name(airport, airport_name);
    set_airport_num_pass(airport, num);

    insert_airport(catalogo, airport, airport_name);
}


void execute_query6(FLIGHTS_CATALOG catalog, char *parameters, char *output)
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

    for (int i = 0; i < atoi(quantidade) && i<(listaAirports->len); i++)
    {
            AIRPORT line = g_array_index(listaAirports, AIRPORT, i);
            char *nome_aero = get_airport_name(line);
            fprintf(outputFile, "%s;%d\n", nome_aero, get_airport_num_pass(line));  
            free(nome_aero);
    }

g_hash_table_destroy(airports);
fclose(outputFile);
}






















/*#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <ctype.h>
#include "queries/query6.h"
#include "catalogs/catalog_flights.h"
#include "entities/flight.h"
#include "utils/stats.h"


gint comparativo(gconstpointer a, gconstpointer b)
{
    // AEROPORTO A comparacao
   const AIRPORT aeroportoi = *(const AIRPORT *)a;
   const AIRPORT aeroportoii = *(const AIRPORT *)b;
   char *aeroi_name = get_airport_name(aeroportoi);
   char *aeroii_name = get_airport_name(aeroportoii);
   int resultado;

    int result =  get_airport_num_pass(aeroportoi) - get_airport_num_pass(aeroportoii);
    if (result == 0)
    {
        resultado = strcmp(get_airport_name(aeroportoi), get_airport_name(aeroportoii));
    }
    else resultado = -result;

    free(aeroi_name);
    free(aeroii_name);
return resultado;
}

int busca_ano(char *data1)
{
    int ano1, mes1, dia1, hora1, minuto1, segundo1;
    sscanf(data1, "%d/%d/%d %d:%d:%d", &ano1, &mes1, &dia1, &hora1, &minuto1, &segundo1);

    return ano1;
}

struct airport
{
    char *airport_name;
    int num_pass_airport;
};

char *get_airport_name(AIRPORT airport)
{
    return strdup(airport->airport_name);
}

void set_airport_name(AIRPORT airport, char *value)
{
    free(airport->airport_name);
    airport->airport_name = strdup(value);
}

int get_airport_num_pass(AIRPORT airport)
{
    return airport->num_pass_airport;
}

void set_airport_num_pass(AIRPORT airport, int numpass)
{
    airport->num_pass_airport += numpass;
}

GHashTable *create_airports_catalog()
{
    GHashTable *catalogo_airport = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, g_free);
    return catalogo_airport;
}

void insert_airport(GHashTable *catalogo, AIRPORT airport, char *key)
{
    g_hash_table_insert(catalogo, key, GINT_TO_POINTER(airport));
}

AIRPORT create_airport(void)
{
    AIRPORT new_airport = malloc(sizeof(struct airport));

    new_airport->airport_name = NULL;
    new_airport->num_pass_airport = 0;

    return new_airport;
}

void build_airport(GHashTable *catalogo, char *airport_name, int num)
{
    AIRPORT airport = create_airport();

    set_airport_name(airport, airport_name);
    set_airport_num_pass(airport, num);

    insert_airport(catalogo, airport, airport_name);
}

//

void execute_query6(FLIGHTS_CATALOG catalog, char *parameters, char *output)
{
    //---------------------ESCREVER FICHEIRO---------------------
    FILE *outputFile = fopen(output, "w");
    char query6_path[60];
    char numero[10];

    char *query6_ficheiro = strdup(query6_path);

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

    GArray *listaAirports = g_array_new(FALSE, FALSE, sizeof(AIRPORT));

    g_hash_table_iter_init(&iter2, airports);

    while (g_hash_table_iter_next(&iter2, &key2, &value2))
    {
        AIRPORT novo_airport = (AIRPORT)value2;
        g_array_append_val(listaAirports, novo_airport);
    }

    //------------------------------------------------------------

    g_array_sort(listaAirports, comparativo);

    //------------------------------------------------------------
    int z = 1;
    int i = 0;
    while (i < atoi(quantidade) && i < listaAirports->len)
    {
        AIRPORT line = g_array_index(listaAirports, AIRPORT, i);
        char *nome_aero = get_airport_name(line);

        fprintf(output, "--- %d ---\n", z);
        fprintf(output, "name: %s\n", nome_aero);

        if (i == quantidade - 1 || i == listaAirports - 1)
        {
            fprintf(output, "passengers: %d\n", get_airport_num_pass(line));
        }
        else
        {
            fprintf(output, "passengers: %d\n\n", get_airport_num_pass(line));
        }

        free(nome_aero);
        i++;
        z++;
    }

    g_hash_table_destroy(airports);
    fclose(outputFile);
    free(query6_ficheiro);

}
*/