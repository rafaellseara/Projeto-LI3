#include "catalogs/catalog_flights.h"
#include <stdio.h>
#include <glib.h>
#include <ctype.h>
#include "queries/query6.h"

struct flights_catalog
{
    GHashTable *flights;
};

FLIGHTS_CATALOG create_flight_catalog()
{
    FLIGHTS_CATALOG new_catalog = g_malloc(sizeof(struct flights_catalog));

    new_catalog->flights = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)free_flight);

    return new_catalog;
}

int is_flight_on_the_table(FLIGHTS_CATALOG catalog, int id)
{
    if (g_hash_table_lookup(catalog->flights, GINT_TO_POINTER(id)) == NULL)
        return 0;
    else
        return 1;
}

void insert_flight(FLIGHTS_CATALOG catalog, FLIGHT flight, int key)
{
    g_hash_table_insert(catalog->flights, GINT_TO_POINTER(key), flight);
}

FLIGHT get_flight_by_id(FLIGHTS_CATALOG catalog, int id)
{
    return g_hash_table_lookup(catalog->flights, GINT_TO_POINTER(id));
}

void free_flights_catalog(FLIGHTS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->flights);
    g_free(catalog);
}

void information_query5(char *parameters, FLIGHTS_CATALOG catalog, GArray *resultados)
{

    char aeroport[4];
    char begin_date[20];
    char end_date[20];

    sscanf(parameters, "%3s \"%[^\"]\" \"%[^\"]\"", aeroport, begin_date, end_date);
    
    GHashTableIter iter;
    gpointer key, value;
    
    g_hash_table_iter_init(&iter, catalog->flights);
    while (g_hash_table_iter_next(&iter, &key, &value))
    {

        FLIGHT flight = (FLIGHT)value;
        char *found_aeroport = getOrigin(flight);
        char *found_begin_date = getScheduleDepartureDate(flight);
        if (strcmp(found_aeroport, aeroport) == 0 && strcmp(begin_date, found_begin_date) <= 0 && strcmp(end_date, found_begin_date) >= 0)
        {
            g_array_append_val(resultados, flight);
        }
        free(found_aeroport);
        free(found_begin_date);
    }
    
}

void information_query6(FLIGHTS_CATALOG catalog, GHashTable *airports, char *origem, char *destino, char *ano)
{
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->flights);
    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        FLIGHT novo_voo = (FLIGHT)value;
        char *origem_voo = getOrigin(novo_voo);
        char *destino_voo = getDestination(novo_voo);
        char *dep_date = getScheduleDepartureDate(novo_voo);
        for (int i = 0; i < 3; i++)
            origem[i] = toupper((unsigned char)origem_voo[i]);
        origem[3] = '\0';
        for (int i = 0; i < 3; i++)
            destino[i] = toupper((unsigned char)destino_voo[i]);
        destino[3] = '\0';
        if (busca_ano(dep_date) == atoi(ano))
        {
            if (g_hash_table_contains(airports, origem))
            {
                AIRPORT airport = g_hash_table_lookup(airports, origem);
                set_airport_num_pass(airport, getNumPass(novo_voo));
            }
            else
            {
                build_airport(airports, origem, getNumPass(novo_voo));
            }
            strcpy(origem, destino);
            if (g_hash_table_contains(airports, origem))
            {
                AIRPORT airport = g_hash_table_lookup(airports, origem);
                set_airport_num_pass(airport, getNumPass(novo_voo));
            }
            else
            {
                build_airport(airports, origem, getNumPass(novo_voo));
            }
        }
    }
}

