#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "catalogs/catalog_hotels.h"
#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"

typedef struct reservation *RESERVATION;

/**
 * @brief Creates a new reservation
 *
 * @return new_reservation  - The new reservation of type `RESERVATION`
 */
RESERVATION create_reservation();

/**
 * @brief Frees the memory allocated to store the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 */
void free_reservation(RESERVATION reservation);

/**
 * @brief Builds the reservation with the given parameters
 *
 * @param reservation_details - The reservation parameters of type `char**`
 */
void build_reservation(char *reservation_details, void *catalog, USERS_CATALOG users_catalog);

/**
 * @brief Sets the reservation id
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param id - The id string of type `char*`
 */
void setIdReservations(RESERVATION reservation, char *id);

/**
 * @brief Gets the reservation id
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return id - The reservation id of type `char*`
 */
int getIdReservations(RESERVATION reservation);

/**
 * @brief Sets the user id for the reservation catalog
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param id - The user id string of type `char*`
 */
void setUserIdReservations(RESERVATION reservation, char *user_id);

/**
 * @brief Gets the user id for the reservation catalog
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return UserId - The user id of type `char*`
 */
char *getUserIdReservations(RESERVATION reservation);

/**
 * @brief Sets the hotel id
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param hotel_id - The hotel id string of type `char*`
 */
void setHotelId(RESERVATION reservation, char *hotel_id);

/**
 * @brief Gets the hotel id
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return HotelId - The hotel id of type `char*`
 */
char *getHotelId(RESERVATION reservation);

/**
 * @brief Sets the hotel id
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param hotel_name - The hotel name string of type `char*`
 */
void setHotelName(RESERVATION reservation, char *hotel_name);

/**
 * @brief Gets the hotel name
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return HotelName - The hotel name of type `char*`
 */
char *getHotelName(RESERVATION reservation);

/**
 * @brief Sets the hotel stars
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param hotel_stars - The hotel stars string of type `char*`
 */
void setHotelStars(RESERVATION reservation, char *hotel_stars);

/**
 * @brief Gets the hotel stars
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return HotelStarsInt - The hotel stars of type `int`
 */
int getHotelStars(RESERVATION reservation);

/**
 * @brief Sets the city tax
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param city_tax - The city tax string of type `char*`
 */
void setCityTax(RESERVATION reservation, char *city_tax);

/**
 * @brief Gets the city tax
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return CityTaxFloat - The city tax of type `float`
 */
float getCityTax(RESERVATION reservation);

/**
 * @brief Sets the begin date of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param begin_date - The begin date string of type `char*`
 */
void setBeginDate(RESERVATION reservation, char *begin_date);

/**
 * @brief Gets the begin date of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return begin_date - The begin date of type `char*`
 */
char *getBeginDate(RESERVATION reservation);

/**
 * @brief Sets the end date of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param end_date - The end date string of type `char*`
 */
void setEndDate(RESERVATION reservation, char *end_date);

/**
 * @brief Gets the end date of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return end_date - The end date of type `char*`
 */
char *getEndDate(RESERVATION reservation);

/**
 * @brief Sets the price per night of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param price_per_night - The price per night string of type `char*`
 */
void setPricePerNight_reservation(RESERVATION reservation, char *price_per_night);

/**
 * @brief Gets the price per night of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return PricePerNight - The price per night of type `double`
 */
double getPricePerNight_reservation(RESERVATION reservation);

/**
 * @brief Sets the include breakfast of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param includes_breakfast - The includes breakfast string of type `char*`
 */
void setIncludesBreakfast(RESERVATION reservation, char *includes_breakfast);

/**
 * @brief Gets the includes breakfast of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return IncludesBreakfast - The include breakfast of type `int`
 */
int getIncludesBreakfast(RESERVATION reservation);

/**
 * @brief Sets the rating of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 * @param rating - The rating string of type `char*`
 */
void setRating(RESERVATION reservation, char *rating);

/**
 * @brief Gets the rating of the reservation
 *
 * @param reservation - The reservation of type `RESERVATION`
 *
 * @return rating - The rating of type `int`
 */
int getRating(RESERVATION reservation);

#endif