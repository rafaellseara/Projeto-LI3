#ifndef CATALOG_USERS_H
#define CATALOG_USERS_H

#include <glib.h>
#include "entities/user.h"

typedef struct users_catalog *USERS_CATALOG;

typedef struct user *USER; // Forward declaration

/**
 * @brief Function that creates a new users catalog
 *
 * @return new_catalog - The users catalog of type `USERS_CATALOG`
 */
USERS_CATALOG create_users_catalog();

/**
 * @brief Function that inserts a user into the users catalog struct
 *
 * @param catalog - The catalog of type `USERS_CATALOG`
 * @param flight - The user of type `USER`
 * @param key - The key of type `char*`
 */
void insert_user(USERS_CATALOG catalog, USER user, void *key);

/**
 * @brief Function that verifies if a user is on the catalog
 *
 * @param catalog - The catalog of type `USERS_CATALOG`
 * @param id - The id of type `int`
 *
 * @return a bool in of type `int`
 */
int is_user_on_the_table(USERS_CATALOG catalog, void *id);

/**
 * @brief Function that gets a user from the user catalog struct with a given id
 *
 * @param catalog - The catalog of type `USERS_CATALOG`
 * @param id - The id to be fetch of type `int`
 *
 * @return user - The user of type `USER`
 */
USER get_user_by_id(USERS_CATALOG catalog, void *id);

/**
 * @brief Function frees memory allocated for the users catalog struct
 *
 * @param catalog of type `USERS_CATALOG`
 */
void free_users_catalog(USERS_CATALOG catalog);

/**
 * @brief Function that adds a reservation to a list
 *
 * @param catalog of type `USERS_CATALOG`
 */
void add_reservation_to_list(USERS_CATALOG catalog, char *id_user, char *id_res);

/**
 * @brief Function that iterates over the hash table of the users
 *
 * @param catalog of type `USERS_CATALOG`
 */
void iter_hash_query9(USERS_CATALOG catalog, GArray *userArray, char *args);

#endif