#ifndef QUERY1F_H
#define QUERY1F_H

#include "queries/query1.h"
#include "catalogs/catalog_flights.h"
#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"
#include "utils/stats.h"

/**
 * @brief Function that executes the query one F and prints the values expected in the outputfile
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
void query1F(char *parameters, RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog,
            FLIGHTS_CATALOG flights_catalog, char *output);

#endif