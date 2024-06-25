#ifndef VALIDATION_H
#define VALIDATION_H

#include "catalogs/catalog_users.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_digit(char character);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
struct tm parse_date(const char *date_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
struct tm parse_datetime(const char *datetime_str);

/**
 * @brief Function that verifies if the date is valid
 *
 * @param date_str - The date_str to be verified of type `cha*r`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_valid_date(char *date_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_valid_date_and_hour(char *date_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_date_after(char *date1_str, char *date2_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_datetime_after(char *date1_str, char *date2_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_email_format(char *email_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_country_code_format(char *code_str);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_valid_account_status(const char *status);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_sufficient_seats(char *total_seats, char *total_passengers);

/**
 * @brief Function that verifies if what is given is a digit
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_airports_different(char *origin, char *destination);

/**
 * @brief Function that verifies if the hotel stars given is valid
 *
 * @param hotel_stars - The hotel stars to be verified of type `char*`
 *
 * @return 1 if the date format is valid, 0 otherwise
 */
int is_valid_hotel_stars(char *hotel_stars);

/**
 * @brief Function that verifies if the city tax is given is valid
 *
 * @param city_tax - The city tax to be verified of type `char*`
 *
 * @return 1 if the city tax format is valid, 0 otherwise
 */
int is_valid_city_tax(char *city_tax);

/**
 * @brief Function that verifies if includes breakfast given is valid
 *
 * @param input - The includes breakfast to be verified of type `char*`
 *
 * @return 1 if the includes breakfast format is valid, 0 otherwise
 */
int is_valid_includes_breakfast(char *input);

/**
 * @brief Function that verifies if the string given is valid 0000000000000000000
 *
 * @param str - The str to be verified of type `char*`
 *
 * @return 1 if the string is not empty, 0 otherwise
 */
int is_string_not_empty(char *str);

/**
 * @brief Function that verifies if the rating given is valid
 *
 * @param rating - The rating to be verified of type `char*`
 *
 * @return 1 if the rating format is valid, 0 otherwise
 */
int is_valid_rating(char *rating);

/**
 * @brief Function that verifies if the price per night what given is valid
 *
 * @param price_per_night - The price_per_night to be verified of type `char*`
 *
 * @return 1 if the price per night format is valid, 0 otherwise
 */
int is_price_per_night_valid(char *price_per_night);

/**
 * @brief Function that verifies if the user given is valif
 *
 * @param param - The param to be verified of type `char*`
 *
 * @return 1 if the user format is valid, 0 otherwise
 */
int is_user_valid(char *param);

/**
 * @brief Function that verifies if the reservation given is valid
 *
 * @param param - The param to be verified of type `char*`
 *
 * @return 1 if the reservation format is valid, 0 otherwise
 */
int is_reservation_valid(char *param, USERS_CATALOG users_catalog);

/**
 * @brief Function that verifies if the flight given is valid
 *
 * @param character - The character to be verified of type `char`
 *
 * @return 1 if the flight format is valid, 0 otherwise
 */
int is_flight_valid(char *param);

/**
 * @brief Function that verifies if status given is valid
 *
 * @param status - The status to be verified of type `char*`
 *
 * @return 1 if the user format is valid, 0 otherwise
 */
int is_user_active(const char *status);

/**
 * @brief Function that verifies if notes given are valid
 *
 * @param notes - The notes to be verified of type `char*`
 *
 * @return 1 if the note format is valid, 0 otherwise
 */
int is_notes_valid(char *notes);

#endif