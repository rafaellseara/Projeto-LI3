#ifndef QUERY4_H
#define QUERY4_H

#include <glib.h>
#include "utils/stats.h"
#include "entities/reservation.h"
#include "catalogs/catalog_reservations.h"

gint comparaReservations(gconstpointer a, gconstpointer b);

void query4(char *args_for_query,RESERVATIONS_CATALOG res_catalog, char *output);

#endif