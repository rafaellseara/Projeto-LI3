#include "entities/user.h"

#include <glib.h>
#include <stdio.h>
#include <string.h>

struct user
{
    GArray *flight_list;
    GArray *reservation_list;
    char *id;
    char *name;
    char *birth_date;
    char *sex; // Use bool it has to be male or female
    char *passport;
    char *country_code;
    char *account_status;
};

USER create_user()
{
    USER new_user = malloc(sizeof(struct user));
    new_user->flight_list = g_array_new(FALSE, FALSE, sizeof(gchar *));
    new_user->reservation_list = g_array_new(FALSE, FALSE, sizeof(gchar *));

    return new_user;
}

void free_user(USER user)
{

    free(user->name);
    free(user->birth_date);
    free(user->sex);
    free(user->passport);
    free(user->country_code);
    free(user->account_status);

    if (user->flight_list)
    {
        g_array_free(user->flight_list, TRUE);
    }
    if (user->reservation_list)
    {
        g_array_free(user->reservation_list, TRUE);
    }

    free(user);
}

void build_user(char *user_details, void *catalog)
{
    USER user = create_user();
    USERS_CATALOG users_catalog = (USERS_CATALOG)catalog;

    int i = 0;
    char *token;
    token = strsep(&user_details, ";");
    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            setIdUser(user, token);
            break;
        case 1:
            setName(user, token);
            break;
        case 4:
            setBirthDate(user, token);
            break;
        case 5:
            setSex(user, token);
            break;
        case 6:
            setPassport(user, token);
            break;
        case 7:
            setCountryCode(user, token);
            break;
        case 11:
            setAccountStatus(user, token);
        }

        token = strsep(&user_details, ";");
        i++;
    }
    free(token);

    insert_user(users_catalog, user, user->id);
}

void setIdUser(USER user, char *id)
{
    user->id = strdup(id);
}

char *getIdUser(USER user)
{
    return (strdup(user->id));
}

void setName(USER user, char *name)
{
    user->name = strdup(name);
}

char *getName(USER user)
{
    return (strdup(user->name));
}

void setBirthDate(USER user, char *birth_date)
{
    user->birth_date = strdup(birth_date);
}

char *getBirthDate(USER user)
{
    return (strdup(user->birth_date));
}

void setSex(USER user, char *sex)
{
    user->sex = strdup(sex);
}

char *getSex(USER user)
{
    return (strdup(user->sex));
}

void setPassport(USER user, char *passport)
{
    user->passport = strdup(passport);
}

char *getPassport(USER user)
{
    return (strdup(user->passport));
}

void setCountryCode(USER user, char *country_code)
{
    user->country_code = strdup(country_code);
}

char *getCountryCode(USER user)
{
    return (strdup(user->country_code));
}

void setAccountStatus(USER user, char *account_status)
{
    size_t len = strlen(account_status);
    if (len > 0 && account_status[len - 1] == '\n') account_status[len - 1] = '\0';
    
    user->account_status = strdup(account_status);
}

char *getAccountStatus(USER user)
{
    return (strdup(user->account_status));
}

void set_user_flight_list(USER user, char *id_flight)
{
    g_array_append_val(user->flight_list, id_flight);
}

GArray *get_user_flight_list(USER user)
{   
    if(user != NULL && user->flight_list != NULL)
        return g_array_copy(user->flight_list);
    else 
        return NULL;
}

int get_user_flight_length_list(USER user)
{
    return user->flight_list->len;
}

int get_user_reservation_length_list(USER user)
{
    return user->reservation_list->len;
}

void set_user_reservation_list(USER user, char *id_reservation)
{
    char *copy = strdup(id_reservation);
    g_array_append_val(user->reservation_list, copy);
}

GArray *get_user_reservation_list(USER user)
{
    if(user != NULL && user->reservation_list != NULL)
        return g_array_copy(user->reservation_list);
    else
        return NULL;
}
