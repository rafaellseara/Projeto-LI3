#ifndef FLIGHTS_H
#define FLIGHTS_H

#include <glib.h>
#include "catalogs/catalog_flights.h"

typedef struct flight *FLIGHT;

/**
 * @brief Creates a new flight
 *
 * @return new_flight - The new flight of type `FLIGHT`
 */
FLIGHT create_flight();

/**
 * @brief Frees the memory allocated to store the flight
 *
 * @param flight - The flight of type `FLIGHT`
 */
void free_flight(gpointer data);

/**
 * @brief Builds the flight with the given parameters
 *
 * @param flight_details - The flight parameters of type `char**`
 * @param catalog - The catalog of type `void*` (CATALOG)
 */
void build_flight(char *flight_details, void *catalog);

/**
 * @brief Sets the flight id
 *
 * @param flight - The flight of type `FLIGHT`
 * @param id - The id string of type `char*`
 */
void setIdFlights(FLIGHT flight, char *id);

/**
 * @brief Gets the flight id
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return id - The flight id of type `int`
 */
int getIdFlights(FLIGHT flight);

/**
 * @brief Sets the flight airline
 *
 * @param flight - The flight of type `FLIGHT`
 * @param airline - The airline string of type `char*`
 */
void setAirline(FLIGHT flight, char *airline);

/**
 * @brief Gets the flight airline
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return Airline - The flight airline of type `char*`
 */
char *getAirline(FLIGHT flight);

/**
 * @brief Sets the flight plane model
 *
 * @param flight - The flight of type `FLIGHT`
 * @param plane_model - The plane model string of type `char*`
 */
void setPlaneModel(FLIGHT flight, char *plane_model);

/**
 * @brief Gets the flight plane model
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return PlaneModel - The plane model string of type `char*`
 */
char *getPlaneModel(FLIGHT flight);

/**
 * @brief Sets the flight total seats
 *
 * @param flight - The flight of type `FLIGHT`
 * @param total_seats - The total seats string of type `char*`
 */
void setTotalSeats(FLIGHT flight, char *total_seats);

/**
 * @brief Gets the flight total seats
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return TotalSeats - The total seats string of type `int`
 */
int getTotalSeats(FLIGHT flight);

/**
 * @brief Sets the flight origin
 *
 * @param flight - The flight of type `FLIGHT`
 * @param origin - The origin string of type `char*`
 */
void setOrigin(FLIGHT flight, char *origin);

/**
 * @brief Gets the flight origin
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return Origin - The origin string of type `char*`
 */
char *getOrigin(FLIGHT flight);

/**
 * @brief Sets the flight destination
 *
 * @param flight - The flight of type `FLIGHT`
 * @param destination - The destination string of type `char*`
 */
void setDestination(FLIGHT flight, char *destination);

/**
 * @brief Gets the flight destination
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return Destination - The destination string of type `char*`
 */
char *getDestination(FLIGHT flight);

/**
 * @brief Sets the flight schedule departure date
 *
 * @param flight - The flight of type `FLIGHT`
 * @param schedule_departure_date - The schedule departure date string of type `char*`
 */
void setScheduleDepartureDate(FLIGHT flight, char *schedule_departure_date);

/**
 * @brief Gets the flight schedule departure date
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return ScheduleDepartureDate - The schedule departure date string of type `char*`
 */
char *getScheduleDepartureDate(FLIGHT flight);

/**
 * @brief Sets the flight schedule arrival date
 *
 * @param flight - The flight of type `FLIGHT`
 * @param schedule_arrival_date - The schedule arrival date string of type `char*`
 */
void setScheduleArrivalDate(FLIGHT flight, char *schedule_arrival_date);

/**
 * @brief Gets the flight schedule arrival date
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return ScheduleArrivalDate - The schedule arrival date string of type `char*`
 */
char *getScheduleArrivalDate(FLIGHT flight);

/**
 * @brief Sets the flight real departure date
 *
 * @param flight - The flight of type `FLIGHT`
 * @param real_departure_date - The real departure date string of type `char*`
 */
void setRealDepartureDate(FLIGHT flight, char *real_departure_date);

/**
 * @brief Gets the flight real departure date
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return RealDepartureDate - The real departure date string of type `char*`
 */
char *getRealDepartureDate(FLIGHT flight);

/**
 * @brief Sets the flight number of passengers
 *
 * @param flight - The flight of type `FLIGHT`
 */
void setNumPass(FLIGHT flight);

/**
 * @brief Gets the flight real departure date
 *
 * @param flight - The flight of type `FLIGHT`
 *
 * @return NumPass - The number of passengers of type `int`
 */
int getNumPass(FLIGHT flight);

#endif