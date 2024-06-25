#include "queries/query9.h"
#include "catalogs/catalog_users.h"
#include <glib.h>

int compare_user_info(const void *a, const void *b)
{
    USER_INFO *user_info_a = (USER_INFO *)a;
    USER_INFO *user_info_b = (USER_INFO *)b;

    int result = g_utf8_collate(user_info_a->username, user_info_b->username);

    if (result == 0)
        return g_utf8_collate(user_info_a->user_id, user_info_b->user_id);

    return result;
}

int verify_name_prefix(USER user, char *args)
{
    char *name = getName(user);
    int result = 0;
    if (strncmp(name, args, strlen(args)) == 0)
        result = 1;
    free(name);
    return result;
}

void query9(USERS_CATALOG catalog, char *args, char *output)
{

    FILE *outputFile = fopen(output, "w");

    int length = strlen(args);
    if (length >= 2 && args[0] == '"' && args[length - 1] == '"')
    {
        memmove(args, args + 1, (strlen(args) - 1) * sizeof(char));
        args[length - 2] = '\0';
    }

    setlocale(LC_COLLATE, "en_US.UTF-8");

    GArray *userArray = g_array_new(FALSE, FALSE, sizeof(USER_INFO));
 
    iter_hash_query9(catalog, userArray, args);

    if (userArray->len > 0) {
        qsort(userArray->data, userArray->len, sizeof(USER_INFO), compare_user_info);
    }

    for (guint i = 0; i < userArray->len; i++)
    {
        USER_INFO info = g_array_index(userArray, USER_INFO, i);
        fprintf(outputFile, "%s;%s\n", info.user_id, info.username);
    }

    fclose(outputFile);
    g_array_free(userArray, TRUE);
}