#ifndef QUERY9F_H
#define QUERY9F_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "catalogs/catalog_users.h"

typedef struct
{
    char username[50];
    char user_id[50];
} USER_INFO_F;

int compare_user_infoF(const void *a, const void *b);

int verify_name_prefixF(USER user, char *args);

void query9F(USERS_CATALOG catalog, char *args, char *output);

#endif
