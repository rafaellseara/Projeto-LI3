#ifndef CATALOG_AEROPORTS_H
#define CATALOG_AEROPORTS_H

#include <glib.h>
#include "entities/aeroport.h"

typedef struct aeroports_catalog *AEROPORTS_CATALOG;

typedef struct aeroport *AEROPORT; // Forward declaration

AEROPORTS_CATALOG create_aeroport_catalog();
int is_aeroport_on_the_table(AEROPORTS_CATALOG catalog, char* aeroport_name);
void insert_aeroport(AEROPORTS_CATALOG catalog, AEROPORT aeroport, char* aeroport_name);
AEROPORT get_aeroport_by_name(AEROPORTS_CATALOG catalog, char* aeroport_name);
void free_aeroports_catalog(AEROPORTS_CATALOG catalog);


#endif