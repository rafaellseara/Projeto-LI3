#ifndef QUERY6_H
#define QUERY6_H

#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_flights.h"
#include "entities/aeroport.h"



gint comparativo(gconstpointer a, gconstpointer b);

int busca_ano(char *data1);

GHashTable *create_airports_catalog();

void insert_airport(GHashTable *catalogo, AIRPORT airport, char *key);

void build_airport(GHashTable *catalogo, char *airport_name, int num);

AIRPORT create_airport(void);

void execute_query6(FLIGHTS_CATALOG catalog, char *parameters, char *output);

void execute_query6F(int numlinha, char *arg, GHashTable *voos);

#endif






















/*#ifndef QUERY6_H
#define QUERY6_H

#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_flights.h"

#include <glib.h>

typedef struct airport *AIRPORT;

gint comparativo(gconstpointer a, gconstpointer b);

int busca_ano(char *data1);

char *get_airport_name(AIRPORT airport);

void set_airport_name(AIRPORT airport, char *value);

int get_airport_num_pass(AIRPORT airport);

void set_airport_num_pass(AIRPORT airport, int numpass);

GHashTable *create_airports_catalog();

void insert_airport(GHashTable *catalogo, AIRPORT airport, char *key);

void build_airport(GHashTable *catalogo, char *airport_name, int num);

AIRPORT create_airport(void);

void execute_query6(FLIGHTS_CATALOG catalog, char *parameters, char *output);

#endif
*/