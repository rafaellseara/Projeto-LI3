#ifndef USERS_H
#define USERS_H

#include <glib.h>
#include "catalogs/catalog_users.h"

typedef struct user *USER;

/**
 * @brief Allocates memory for a new User
 *
 * @return new_user - The newly created User
 */
USER create_user();

/**
 * @brief Frees the memory space of the User
 *
 * @param user - User in the table
 */
void free_user(USER user);

/**
 * @brief Builds the User using parameters read from files. Allocates memory and then inserts into the catalog.
 *
 * @param user_details - List of Strings with information to place in the User
 * @param catalog - Catalog where the HashTable is located to insert the constructed User
 */
void build_user(char *user_details, void *catalog);

/**
 * @brief Sets the User's ID
 *
 * @param user - User in the table
 * @param id - ID to set
 */
void setIdUser(USER user, char *id);

/**
 * @brief Returns the ID of the User to search for
 *
 * @param user - User in the table
 *
 * @return id - ID of the searched User
 */
char *getIdUser(USER user);

/**
 * @brief Sets the User's name
 *
 * @param user - User in the table
 * @param name - Name to set
 */
void setName(USER user, char *name);

/**
 * @brief Returns the name of the User to search for
 *
 * @param user - User in the table
 *
 * @return name - Name of the searched User
 */
char *getName(USER user);

/**
 * @brief Sets the User's birth date
 *
 * @param user - User in the table
 * @param birth_date - Birth date to set
 */
void setBirthDate(USER user, char *birth_date);

/**
 * @brief Returns the birth date of the User to search for
 *
 * @param user - User in the table
 *
 * @return birth_date - Birth date of the searched User
 */
char *getBirthDate(USER user);

/**
 * @brief Sets the User's gender
 *
 * @param user - User in the table
 * @param sex - Gender to set
 */
void setSex(USER user, char *sex);

/**
 * @brief Returns the gender of the User to search for
 *
 * @param user - User in the table
 *
 * @return sex - Gender of the searched User
 */
char *getSex(USER user);

/**
 * @brief Sets the User's passport
 *
 * @param user - User in the table
 * @param passport - Passport to set
 */
void setPassport(USER user, char *passport);

/**
 * @brief Returns the passport of the User to search for
 *
 * @param user - User in the table
 *
 * @return passport - Passport of the searched User
 */
char *getPassport(USER user);

/**
 * @brief Sets the User's country code
 *
 * @param user - User in the table
 * @param country_code - Country code to set
 */
void setCountryCode(USER user, char *country_code);

/**
 * @brief Returns the country code of the User to search for
 *
 * @param user - User in the table
 *
 * @return country_code - Country code of the searched User
 */
char *getCountryCode(USER user);

/**
 * @brief Sets the User's account creation date
 *
 * @param user - User in the table
 * @param account_creation - Account creation date to set
 */
void setAccountCreation(USER user, char *account_creation);

/**
 * @brief Returns the account creation date of the User to search for
 *
 * @param user - User in the table
 *
 * @return account_creation - Account creation date of the searched User
 */
char *getAccountCreation(USER user);

/**
 * @brief Sets the User's account status
 *
 * @param user - User in the table
 * @param account_status - Account status to set
 */
void setAccountStatus(USER user, char *account_status);

/**
 * @brief Returns the account status of the User to search for
 *
 * @param user - User in the table
 *
 * @return account_status - Account status of the searched User
 */
char *getAccountStatus(USER user);

/**
 * @brief Returns the list of flights the User has been on
 *
 * @param user - User in the table
 *
 * @return flight_list - List of flights of the searched User
 */
GArray *get_user_flight_list(USER user);

/**
 * @brief Adds a flight ID where the User has been present
 *
 * @param user - User in the table
 * @param id_flight - Flight ID to set
 */
void set_user_flight_list(USER user, char *id_flight);

/**
 * @brief Returns the list of reservations the User has made
 *
 * @param user - User in the table
 *
 * @return reservation_list - List of reservations of the searched User
 */
GArray *get_user_reservation_list(USER user);

/**
 * @brief Adds a reservation ID where the User has been present
 *
 * @param user - User in the table
 * @param id_reservation - Reservation ID to set
 */
void set_user_reservation_list(USER user, char *id_reservation);


int get_user_flight_length_list(USER user);
int get_user_reservation_length_list(USER user);
#endif
