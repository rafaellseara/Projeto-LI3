#ifndef QUERY3_H
#define QUERY3_H
#include <stdio.h>
#include <stdlib.h>

#include "catalogs/catalog_hotels.h"

/**
 * @brief Function that executes the query 3 and prints the values expected in the outputfile
 * 
 *
 * @param catalog - The catalog of type HOTELS_CATALOG
 * @param hotel_id - The hotel_id of type char * is passed to the
 * query
 *
 * @return the information necessary
 */
void query3(char *hotel_id, HOTELS_CATALOG catalog, char *output);

#endif