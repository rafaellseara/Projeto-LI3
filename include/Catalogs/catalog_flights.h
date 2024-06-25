#ifndef CATALOG_FLIGHTS_H
#define CATALOG_FLIGHTS_H

#include <glib.h>
#include "entities/flight.h"

typedef struct flights_catalog *FLIGHTS_CATALOG;

typedef struct flight *FLIGHT; // Forward declaration

/**
 * @brief Function that creates a new flight catalog
 *
 * @return new_catalog - The flight catalog of type `FLIGHTS_CATALOG`
 */
FLIGHTS_CATALOG create_flight_catalog();

/**
 * @brief Function that inserts a flight into the flights catalog struct
 *
 * @param catalog - The catalog of type `FLIGHTS_CATALOG`
 * @param flight - The flight of type `FLIGHT`
 * @param key - The key of type `char*`
 */
void insert_flight(FLIGHTS_CATALOG catalog, FLIGHT flight, int key);

/**
 * @brief Function that verifies if a flight is on the catalog
 *
 * @param catalog - The catalog of type `FLIGHTS_CATALOG`
 * @param id - The id of type `int`
 *
 * @return a bool in of type `int`
 */
int is_flight_on_the_table(FLIGHTS_CATALOG catalog, int id);

/**
 * @brief Function that gets a flight from the flight catalog struct with a given id
 *
 * @param catalog - The catalog of type `FLIGHTS_CATALOG`
 * @param id - The id to be fetch of type `int`
 *
 * @return flight - The flight of type `FLIGHT`
 */
FLIGHT get_flight_by_id(FLIGHTS_CATALOG catalog, int id);

/**
 * @brief Function frees memory allocated for the flight catalog struct
 *
 * @param catalog of type `FLIGHTS_CATALOG`
 */
void free_flights_catalog(FLIGHTS_CATALOG catalog);

/**
 * @brief Function that gives information that is necessary for query 5
 *
 * @param catalog of type `FLIGHTS_CATALOG`
 */
void information_query5(char *parameters, FLIGHTS_CATALOG catalog, GArray *resultados);

void information_query6(FLIGHTS_CATALOG catalog, GHashTable *airports, char *origem, char *destino, char *ano);

#endif