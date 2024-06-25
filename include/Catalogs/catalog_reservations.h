#ifndef CATALOG_RESERVATIONS_H
#define CATALOG_RESERVATIONS_H

#include <glib.h>
#include "entities/reservation.h"
#include "utils/stats.h"

typedef struct reservations_catalog *RESERVATIONS_CATALOG;

typedef struct reservation *RESERVATION; // Forward declaration

/**
 * @brief Function that creates a new reservation catalog
 *
 * @return new_catalog - The reservation catalog of type `RESERVATIONS_CATALOG`
 */
RESERVATIONS_CATALOG create_reservation_catalog();

/**
 * @brief Function that inserts a reservation into the reservation catalog struct
 *
 * @param catalog - The catalog of type `RESERVATIONS_CATALOG`
 * @param reservation - The flight of type `RESERVATION`
 * @param key - The key of type `void*`
 */
void insert_reservation(RESERVATIONS_CATALOG catalog, RESERVATION reservation, void *key);

/**
 * @brief Function that verifies if a reservations is on the catalog
 *
 * @param catalog - The catalog of type `RESERVATIONS_CATALOG`
 * @param id - The id to be fetch of type `int`
 *
 * @return a bool in of type `int`
 */
int is_reservation_on_the_table(RESERVATIONS_CATALOG catalog, int id);

/**
 * @brief Function that gets a reservation from the reservation catalog struct with a given id
 *
 * @param catalog - The catalog of type `RESERVATIONS_CATALOG`
 * @param id - The id to be fetch of type `int`
 *
 * @return flight - The flight of type `RESERVATION`
 */
RESERVATION get_reservation_by_id(RESERVATIONS_CATALOG catalog, int id);

/**
 * @brief Function frees memory allocated for the reservation catalog struct
 *
 * @param catalog of type `RESERVATIONS_CATALOG`
 */
void free_reservations_catalog(RESERVATIONS_CATALOG catalog); 

/**
 * @brief Function that calcutes the total spent in a reservation
 * 
 * @param catalog of type `RESERVATIONS_CATALOG`
 * 
 * @return a int with the total spent
 */
double total_spent(char *parameters, RESERVATIONS_CATALOG catalog);

/**
 * @brief Function that gives information that is necessary for query 3
 *
 * @param catalog of type `RESERVATIONS_CATALOG`
 */
void information_query3(RESERVATIONS_CATALOG catalog, double *rating, int *number_of_reservations, char *hotel_id);

void information_query4(RESERVATIONS_CATALOG catalog, char *arg, GArray *listaReservas);

void information_query8(RESERVATIONS_CATALOG catalog, char *parametros, char *id, char *dataInicial, char *dataFinal, int *receitaFinal);

#endif