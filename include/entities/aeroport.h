#ifndef AEROPORT_H
#define AEROPORT_H

#include <glib.h>
#include "catalogs/catalog_aeroports.h"
#include "utils/stats.h"

typedef struct airport *AIRPORT;

AIRPORT create_airport(void);
void free_airport(AIRPORT airport);
void set_airport_name(AIRPORT airport, char *value);
char *get_airport_name(AIRPORT airport);
void set_airport_num_pass(AIRPORT airport, int numpass);
int get_airport_num_pass(AIRPORT airport);
void set_aeroporto_delay(AIRPORT airport, int delay);
GArray *get_aeroporto_delay(AIRPORT airport);
void set_aeroport_mediana(AIRPORT airport);
int get_aeroport_mediana(AIRPORT airport);

#endif