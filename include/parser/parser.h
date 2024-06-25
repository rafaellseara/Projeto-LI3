#ifndef PARSER_H
#define PARSER_H

#include "catalogs/catalog_flights.h"
#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"
#include "catalogs/catalog_hotels.h"
#include "parser/validation.h"

void parse_file_passengers(char *filename, FLIGHTS_CATALOG catalog_flights, USERS_CATALOG catalog_users);

void parse_file_flights(char *filename, FLIGHTS_CATALOG catalog);

void parse_file_reservations(char *filename, RESERVATIONS_CATALOG catalog, USERS_CATALOG catalog_users, HOTELS_CATALOG hotels_catalog);

void parse_file_users(char *filename, USERS_CATALOG catalog);

#endif