#include "catalogs/catalog_hotels.h"
#include "entities/hotel.h"
#include <stdio.h>
#include <glib.h>

struct hotels_catalog
{
    GHashTable *hotels;
};

HOTELS_CATALOG create_hotel_catalog()
{
    HOTELS_CATALOG new_catalog = g_malloc(sizeof(struct hotels_catalog));

    new_catalog->hotels = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)free_hotel);

    return new_catalog;
}

int is_hotel_on_the_table(HOTELS_CATALOG catalog, char* hotel_id)
{
    if (g_hash_table_lookup(catalog->hotels, hotel_id) == NULL)
        return 0;
    else
        return 1;
}

void insert_hotel(HOTELS_CATALOG catalog, HOTEL hotel, char *key)
{
    char *id = strdup(key);
    g_hash_table_insert(catalog->hotels, id, hotel);
}

HOTEL get_hotel_by_id(HOTELS_CATALOG catalog, char *hotel_id)
{
    return g_hash_table_lookup(catalog->hotels, hotel_id);
}

void free_hotels_catalog(HOTELS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->hotels);
    g_free(catalog);
}