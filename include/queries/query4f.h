#ifndef QUERY4F_H
#define QUERY4F_H

#include <glib.h>
#include "queries/query4.h"
#include "utils/stats.h"
#include "entities/reservation.h"
#include "catalogs/catalog_reservations.h"

void query4F(char *args_for_query, RESERVATIONS_CATALOG res_catalog, char *output);

#endif