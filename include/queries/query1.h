#ifndef QUERY1_H
#define QUERY1_H

#include "catalogs/catalog_flights.h"
#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"
#include "utils/stats.h"

/**
 * @brief This function calculates da total spent in reservations
 *
 * @param parameters - parameters need to function total spent that iterates in the reservations catalog
 * @param catalog - reservations catalog
 */
double total_spent_in_reservations(char *parameters, RESERVATIONS_CATALOG catalog);

/**
 * @brief Function that executes the query one and prints the values expected in the outputfile
 * 
 *
 * @param reservations_catalog - The catalog of type RESERVATIONS_CATALOG
 * @param users_catalog - The catalog of type USERS_CATALOG
 * @param flights_catalog - The catalog of type FLIGHTS_CATALOG
 * 
 * @param parameters - The parameters of type char * that are passed to the
 * query
 *
 * @return the information necessary
 */
void query1(char *parameters, RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog,
            FLIGHTS_CATALOG flights_catalog, char *output);

#endif
