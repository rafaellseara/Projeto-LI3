#ifndef QUERY9_H
#define QUERY9_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "catalogs/catalog_users.h"

typedef struct
{
    char username[50];
    char user_id[50];
} USER_INFO;

int compare_user_info(const void *a, const void *b);

int verify_name_prefix(USER user, char *args);

void query9(USERS_CATALOG catalog, char *args, char *output);

#endif