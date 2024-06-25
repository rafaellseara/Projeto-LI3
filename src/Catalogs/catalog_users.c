#include "catalogs/catalog_users.h"
#include "parser/validation.h"
#include "queries/query9.h"
#include <glib.h>   

struct users_catalog
{
    GHashTable *users;
};

USERS_CATALOG create_users_catalog()
{
    USERS_CATALOG new_catalog = g_malloc(sizeof(struct users_catalog));

    new_catalog->users = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify)free_user);

    return new_catalog;
}

void insert_user(USERS_CATALOG catalog, USER user, void *key)
{
    g_hash_table_insert(catalog->users, key, user);
}

int is_user_on_the_table(USERS_CATALOG catalog, void *id)
{
    if (g_hash_table_lookup(catalog->users, id) == NULL)
        return 0;
    else
        return 1;
}

USER get_user_by_id(USERS_CATALOG catalog, void *id)
{
    return g_hash_table_lookup(catalog->users, id);
}

void free_users_catalog(USERS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->users);
    g_free(catalog);
}

void add_reservation_to_list(USERS_CATALOG catalog, char *id_user, char *id_res)
{  
    set_user_reservation_list(get_user_by_id(catalog, id_user), id_res);
}

void iter_hash_query9(USERS_CATALOG catalog, GArray *userArray, char *args){
    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->users);

    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        USER user = (USER)value;
        USER_INFO user_info;

        char *name = getName(user);
        char *account_status = getAccountStatus(user);
        char *id = getIdUser(user);

        strcpy(user_info.username, name);
        strcpy(user_info.user_id, id);

        if (is_user_active(account_status) && verify_name_prefix(user, args))
        {
            g_array_append_val(userArray, user_info);
        }

        free(name);
        free(id);
    }
}