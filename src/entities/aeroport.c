#include "catalogs/catalog_aeroports.h"
#include "entities/aeroport.h"
#include <stdio.h>
#include <glib.h>
#include "utils/stats.h"

struct airport
{
    GArray *delay;
    char *airport_name;
    int mediana;
    int num_pass_airport;
    
};

AIRPORT create_airport(void)
{
    AIRPORT new_airport = malloc(sizeof(struct airport));

    new_airport->airport_name = NULL;
    new_airport->num_pass_airport = 0;
    new_airport->delay = g_array_new(FALSE, FALSE, sizeof(int));
    new_airport->mediana = 0;

    return new_airport;
}


void free_airport(AIRPORT airport)
{

    free(airport->airport_name);

    if (airport->delay)
    {
        g_array_free(airport->delay, TRUE);
    }

    free(airport);
}

void set_airport_name(AIRPORT airport, char *value)
{
    free(airport->airport_name);
    airport->airport_name = strdup(value);
}

char *get_airport_name(AIRPORT airport)
{
    return strdup(airport->airport_name);
}

void set_airport_num_pass(AIRPORT airport, int numpass)
{
    airport->num_pass_airport += numpass;
}

int get_airport_num_pass(AIRPORT airport)
{
    return airport->num_pass_airport;
}

void set_aeroporto_delay(AIRPORT airport, int delay){
    g_array_append_val(airport->delay, delay);
}

GArray *get_aeroporto_delay(AIRPORT airport){
    return g_array_copy(airport->delay);
}

/*void set_aeroport_mediana(AIRPORT airport, int mediana){
    airport->mediana=mediana;
}

int get_aeroport_mediana(AIRPORT airport){
   return airport->mediana;
}
*/