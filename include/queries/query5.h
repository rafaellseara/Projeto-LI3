#ifndef QUERY5_H
#define QUERY5_H

#include "queries/query5.h"
#include "catalogs/catalog_flights.h"
#include "entities/flight.h"

void query5(FLIGHTS_CATALOG catalog, char *parameters, char *output );
gint comparacao_FLIGHTS(gconstpointer a, gconstpointer b);

#endif