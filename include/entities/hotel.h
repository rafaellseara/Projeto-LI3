#ifndef HOTEL_H
#define HOTEL_H

#include <glib.h>
#include "catalogs/catalog_hotels.h"
#include "entities/reservation.h"
#include "catalogs/catalog_users.h"
#include "catalogs/catalog_reservations.h"


typedef struct hotel *HOTEL;

/**
 * @brief Creates a new hotel
 *
 * @return new_hotel - The new hotel of type `HOTEL`
 */
HOTEL create_hotel();

/**
 * @brief Frees the memory allocated to store the hotel
 *
 * @param hotel - The hotel of type `HOTEL`
 */
void free_hotel(gpointer data);

/**
 * @brief Builds the hotel with the given parameters
 *
 * @param reservation_details - The hotel parameters of type `char**`
 * @param catalog - The catalog of type `void*` (CATALOG)
 */
void build_hotel(void *catalog, char *reservation_details);

/**
 * @brief Sets the hotel id
 *
 * @param hotel - The flight of type `HOTEL`
 * @param id - The id string of type `char*`
 */
void setHotelIdHOTEL(HOTEL hotel, char *hotel_id);

/**
 * @brief Gets the hotel id
 *
 * @param hotel - The hotel of type `HOTEL`
 *
 * @return id - The hotel id of type `char*`
 */
char *getHotelIdHOTEL(HOTEL hotel);

/**
 * @brief Sets the hotel rating
 *
 * @param hotel - The hotel of type `HOTEL`
 * @param rating - The ratingINT int of type `int`
 */
void setHOTELRating(HOTEL hotel, int ratingINT);

/**
 * @brief Gets the hotel rating
 *
 * @param hotel - The hotel of type `HOTEL`
 *
 * @return rating - The hotel rating of type `int`
 */
int getHOTELRating(HOTEL hotel);

/**
 * @brief Sets the number of ratings of an hotel
 *
 * @param hotel - The hotel of type `HOTEL`
 * @param NumberOfRatings - The number of ratings type `int`
 */
void setNumberofRating(HOTEL hotel);

/**
 * @brief Gets the number of ratings
 *
 * @param hotel - The hotel of type `HOTEL`
 *
 * @return NumberOfRatings - The number of ratings type `int`
 */
int getNumberofRating(HOTEL hotel);

#endif