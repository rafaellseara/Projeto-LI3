/*#ifndef QUERY2_H
#define QUERY2_H

#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"
#include "catalogs/catalog_flights.h"

void query2(char *parameters, RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, char *output);

void comparaReservas(const void* a, const void* b);

gint comparaFLights(gconstpointer a, gconstpointer b, gpointer user_data);

GArray* combine_and_sort_lists_by_date(GArray *list1, GArray *list2, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog);

gboolean is_id_in_array(const char *id, GArray *array);

#endif*/

