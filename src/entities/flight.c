#include "entities/flight.h"
#include <stdio.h>
#include <string.h>

#include "utils/stats.h"

struct flight
{
    gpointer id;
    char *airline;
    char *plane_model;
    char *origin;
    char *destination;
    char *schedule_departure_date; 
    char *schedule_arrival_date; 
    char *real_departure_date;
    int num_pass;
    int total_seats;
};

FLIGHT create_flight()
{
    FLIGHT new_flight = malloc(sizeof(struct flight));

    return new_flight;
}

void free_flight(gpointer data)
{
    FLIGHT flight = (FLIGHT)data;
    free(flight->airline);
    free(flight->plane_model);
    free(flight->origin);
    free(flight->destination);
    free(flight->schedule_departure_date);
    free(flight->schedule_arrival_date);
    free(flight->real_departure_date);

    free(flight);
}

void build_flight(char *flight_details, void *catalog)
{
    FLIGHT flight = create_flight();
    FLIGHTS_CATALOG flights_catalog = (FLIGHTS_CATALOG)catalog;

    int i = 0;
    char *token;
    token = strsep(&flight_details, ";");
    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            setIdFlights(flight, token);
            break;
        case 1:
            setAirline(flight, token);
            break;
        case 2:
            setPlaneModel(flight, token);
            break;
        case 3:
            setTotalSeats(flight, token);
            break;
        case 4:
            setOrigin(flight, token);
            break;
        case 5:
            setDestination(flight, token);
            break;
        case 6:
            setScheduleDepartureDate(flight, token);
            break;
        case 7:
            setScheduleArrivalDate(flight, token);
            break;
        case 8:
            setRealDepartureDate(flight, token);
            break;
        }

        token = strsep(&flight_details, ";");
        i++;
    }
    free(token);

    flight->num_pass = 0;

    insert_flight(flights_catalog, flight, getIdFlights(flight));
}

void setIdFlights(FLIGHT flight, char *id)
{
    int id_int = strtol(id, NULL, 10);
    flight->id = GINT_TO_POINTER(id_int);
}

int getIdFlights(FLIGHT flight)
{
    int id = GPOINTER_TO_INT(flight->id);
    return id;
}

void setAirline(FLIGHT flight, char *airline)
{
    flight->airline = strdup(airline);
}

char *getAirline(FLIGHT flight)
{
    return strdup(flight->airline);
}

void setPlaneModel(FLIGHT flight, char *plane_model)
{
    flight->plane_model = strdup(plane_model);
}

char *getPlaneModel(FLIGHT flight)
{
    return strdup(flight->plane_model);
}

void setTotalSeats(FLIGHT flight, char *total_seats)
{
    int seats = strtol(total_seats, NULL, 10);
    flight->total_seats = seats;
}

int getTotalSeats(FLIGHT flight)
{
    return flight->total_seats;
}

void setOrigin(FLIGHT flight, char *origin)
{
    to_upper(origin);
    flight->origin = strdup(origin);
}

char *getOrigin(FLIGHT flight)
{
    return strdup(flight->origin);
}

void setDestination(FLIGHT flight, char *destination)
{
    to_upper(destination);
    flight->destination = strdup(destination);
}

char *getDestination(FLIGHT flight)
{
    return strdup(flight->destination);
}

void setScheduleDepartureDate(FLIGHT flight, char *schedule_departure_date)
{
    flight->schedule_departure_date = strdup(schedule_departure_date);
}

char *getScheduleDepartureDate(FLIGHT flight)
{
    if (flight != NULL && flight->schedule_departure_date != NULL)
    {
        return strdup(flight->schedule_departure_date);
    }
    return NULL;
}

void setScheduleArrivalDate(FLIGHT flight, char *schedule_arrival_date)
{
    flight->schedule_arrival_date = strdup(schedule_arrival_date);
}

char *getScheduleArrivalDate(FLIGHT flight)
{
    return strdup(flight->schedule_arrival_date);
}

void setRealDepartureDate(FLIGHT flight, char *real_departure_date)
{
    flight->real_departure_date = strdup(real_departure_date);
}

char *getRealDepartureDate(FLIGHT flight)
{
    return strdup(flight->real_departure_date);
}

void setNumPass(FLIGHT flight)
{
    flight->num_pass++;
}

int getNumPass(FLIGHT flight)
{
    return flight->num_pass;
}
//.