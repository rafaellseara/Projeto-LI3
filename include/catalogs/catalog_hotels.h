#ifndef CATALOG_HOTELS_H
#define CATALOG_HOTELS_H

#include <glib.h>
#include "entities/hotel.h"

typedef struct hotels_catalog *HOTELS_CATALOG;

typedef struct hotel *HOTEL; // Forward declaration

/**
 * @brief Function that creates a new hotel catalog
 *
 * @return new_catalog - The hotel catalog of type `HOTELS_CATALOG`
 */
HOTELS_CATALOG create_hotel_catalog();

/**
 * @brief Function that verifies if a hotel is on the catalog
 *
 * @param catalog - The catalog of type `HOTELS_CATALOG`
 * @param id - The id of type `char*`
 *
 * @return a bool in of type `int`
 */
int is_hotel_on_the_table(HOTELS_CATALOG catalog, char *hotel_id);

/**
 * @brief Function that inserts a hotel into the hotels catalog struct
 *
 * @param catalog - The catalog of type `HOTELS_CATALOG`
 * @param hotel - The hotel of type `HOTEL`
 * @param key - The key of type `char*`
 */
void insert_hotel(HOTELS_CATALOG catalog, HOTEL hotel, char *key);

/**
 * @brief Function that gets a hotel from the hotel catalog struct with a given id
 *
 * @param catalog - The catalog of type `HOTELS_CATALOG`
 * @param id - The id to be fetch of type `char*`
 *
 * @return hotel - The flight of type `FLIGHT`
 */
HOTEL get_hotel_by_id(HOTELS_CATALOG catalog, char*hotel_id);

/**
 * @brief Function frees memory allocated for the hotel catalog struct
 *
 * @param catalog of type `HOTELS_CATALOG`
 */
void free_hotels_catalog(HOTELS_CATALOG catalog);

#endif