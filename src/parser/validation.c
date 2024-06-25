#include "parser/validation.h"

int is_digit(char character)
{
    return (character >= '0' && character <= '9');
}

struct tm parse_date(const char *date_str)
{
    struct tm date;
    memset(&date, 0, sizeof(struct tm));

    sscanf(date_str, "%d/%d/%d", &date.tm_year, &date.tm_mon, &date.tm_mday);

    // Adjusting the values to match the structure's expectations
    date.tm_year -= 1900;
    date.tm_mon -= 1;

    return date;
}

struct tm parse_datetime(const char *datetime_str)
{
    struct tm datetime;
    memset(&datetime, 0, sizeof(struct tm));
    sscanf(datetime_str, "%d/%d/%d %d:%d:%d",
           &datetime.tm_year, &datetime.tm_mon, &datetime.tm_mday,
           &datetime.tm_hour, &datetime.tm_min, &datetime.tm_sec);

    // Adjustments
    datetime.tm_year -= 1900;
    datetime.tm_mon -= 1;

    return datetime;
}

int is_valid_date(char *date_str)
{

    if (strlen(date_str) != 10)
        return 0;
    if (date_str[4] != '/' || date_str[7] != '/')
        return 0;

    int temp = 0;
    if (is_digit(date_str[0]))
        temp = (date_str[0] - '0') * 1000;
    if (is_digit(date_str[1]))
        temp += (date_str[1] - '0') * 100;
    if (is_digit(date_str[2]))
        temp += (date_str[2] - '0') * 10;
    if (is_digit(date_str[3]))
        temp += (date_str[3] - '0');
    if (temp > 2023)
        return 0;

    if (is_digit(date_str[5]))
        temp = (date_str[5] - '0') * 10;
    if (is_digit(date_str[6]))
        temp += (date_str[6] - '0');
    if (temp > 12 || temp < 1)
        return 0;

    if (is_digit(date_str[8]))
        temp = (date_str[8] - '0') * 10;
    if (is_digit(date_str[9]))
        temp += (date_str[9] - '0');
    if (temp > 31 || temp < 1)
        return 0;

    return 1;
}

int is_valid_date_and_hour(char *date_str)
{

    if (strlen(date_str) != 19)
        return 0;
    if (date_str[4] != '/' || date_str[7] != '/' || date_str[13] != ':' || date_str[16] != ':' || date_str[10] != ' ')
        return 0;

    int temp = 0;
    if (is_digit(date_str[0]))
        temp = (date_str[0] - '0') * 1000;
    if (is_digit(date_str[1]))
        temp += (date_str[1] - '0') * 100;
    if (is_digit(date_str[2]))
        temp += (date_str[2] - '0') * 10;
    if (is_digit(date_str[3]))
        temp += (date_str[3] - '0');
    if (temp > 2023)
        return 0;

    if (is_digit(date_str[5]))
        temp = (date_str[5] - '0') * 10;
    if (is_digit(date_str[6]))
        temp += (date_str[6] - '0');
    if (temp > 12 || temp < 1)
        return 0;

    if (is_digit(date_str[8]))
        temp = (date_str[8] - '0') * 10;
    if (is_digit(date_str[9]))
        temp += (date_str[9] - '0');
    if (temp > 31 || temp < 1)
        return 0;

    if (is_digit(date_str[11]))
        temp = (date_str[11] - '0') * 10;
    if (is_digit(date_str[12]))
        temp += (date_str[12] - '0');
    if (temp > 23 || temp < 0)
        return 0;

    if (is_digit(date_str[14]))
        temp = (date_str[14] - '0') * 10;
    if (is_digit(date_str[15]))
        temp += (date_str[15] - '0');
    if (temp > 59 || temp < 0)
        return 0;

    if (is_digit(date_str[17]))
        temp = (date_str[17] - '0') * 10;
    if (is_digit(date_str[18]))
        temp += (date_str[18] - '0');
    if (temp > 59 || temp < 0)
        return 0;

    return 1;
}

int is_date_after(char *date1_str, char *date2_str)
{
    struct tm date1 = parse_date(date1_str);
    struct tm date2 = parse_date(date2_str);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return (time1 <= time2);
}

int is_datetime_after(char *date1_str, char *date2_str)
{
    struct tm date1 = parse_datetime(date1_str);
    struct tm date2 = parse_datetime(date2_str);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return (time1 <= time2);
}

int is_email_format(char *email)
{

    int i, atpos = -1, dotpos = -1;
    int len = strlen(email);

    for (i = 0; i < len; i++)
    {
        if (email[i] == '@')
        {
            if (atpos != -1)
            {
                return 0;
            }
            atpos = i;
        }
    }

    for (i = atpos + 1; i < len; i++)
    {
        if (email[i] == '.')
        {
            dotpos = i;
            break;
        }
    }

    if (atpos > 0 && dotpos - atpos > 1 && dotpos < len - 1 && len - dotpos > 2)
        return 1;

    else
        return 0;
}

int is_country_code_format(char *code_str)
{
    return (strlen(code_str) == 2);
}

int is_valid_account_status(const char *status)
{
    char lower_status[50];
    int i;
    for (i = 0; status[i] != '\0'; i++)
        lower_status[i] = tolower(status[i]);

    lower_status[i] = '\0';

    if (strcmp(lower_status, "active\n") == 0 || strcmp(lower_status, "inactive\n") == 0 || strcmp(lower_status, "active") == 0 || strcmp(lower_status, "inactive") == 0)
        return 1;
    return 0;
}

int is_user_active(const char *status)
{
    char lower_status[50];
    int i;
    for (i = 0; status[i] != '\0'; i++)
        lower_status[i] = tolower(status[i]);

    lower_status[i] = '\0';

    if (strcmp(lower_status, "active") == 0)
        return 1;
    else
        return 0;
}

int is_sufficient_seats(char *total_seats, char *total_passengers)
{
    int seats = atoi(total_seats);
    int passengers = atoi(total_passengers);

    return (seats >= passengers);
}

int is_airports_different(char *origin, char *destination)
{
    if (strlen(origin) != 3 || strlen(destination) != 3)
        return 0;

    char org[4];
    char dest[4];
    for (int i = 0; i < 3; i++)
    {
        org[i] = tolower(origin[i]);
        dest[i] = tolower(destination[i]);
    }
    org[3] = '\0';
    dest[3] = '\0';

    if (strcmp(org, dest) == 0)
        return 0;
    return 1;
}

int is_valid_hotel_stars(char *hotel_stars)
{

    char *endptr;
    long stars = strtol(hotel_stars, &endptr, 10);

    if (*endptr == '\0' && stars >= 1 && stars <= 5)
        return 1;
    return 0;
}

int is_valid_city_tax(char *city_tax)
{

    char *endptr;
    long tax = strtol(city_tax, &endptr, 10);

    if (*endptr == '\0' && tax >= 0)
        return 1;
    return 0;
}

int is_valid_includes_breakfast(char *input)
{
    char lowercaseInput[20];
    int i;
    for (i = 0; i < strlen(input); i++)
        lowercaseInput[i] = tolower(input[i]);

    lowercaseInput[i] = '\0';

    if (strcmp(lowercaseInput, "f") == 0 || strcmp(lowercaseInput, "false") == 0 || strcmp(lowercaseInput, "0") == 0 || strcmp(lowercaseInput, "") == 0)
        return 1;
    if (strcmp(lowercaseInput, "t") == 0 || strcmp(lowercaseInput, "true") == 0 || strcmp(lowercaseInput, "1") == 0)
        return 1;
    return 0;
}

int is_string_not_empty(char *str)
{
    return (strlen(str) > 0);
}

int is_valid_rating(char *rating)
{
    char *endptr;
    long rating_long = strtol(rating, &endptr, 10);

    if (*endptr == '\0' || (*endptr == '\n' && *(endptr + 1) == '\0'))
        return (rating_long >= 1 && rating_long <= 5);
    return 0;

}

int is_price_per_night_valid(char *price_per_night)
{
    char *endptr;
    long int price = strtol(price_per_night, &endptr, 10);
    if (*endptr != '\0' && *endptr != '\n')
        return 0;
    if (price < 0)
        return 0;
    return 1;
}

int is_notes_valid(char *notes)
{
    if (strlen(notes) > 0 || strlen(notes) == 0)
        return 1;

    return 0;
}

int is_number(char *str)
{
    char *endptr;
    strtol(str, &endptr, 10);

    return *endptr == '\0';
}

int is_user_valid(char *param)
{
    int i = 0;
    char *token;
    token = strsep(&param, ";");
    while (token != NULL)
    {
        if (!is_string_not_empty(token) && i != 12) return 0;

        switch (i){
            case 2:
                if (!is_email_format(token)) return 0;
                break;
            case 4:
                if (!is_valid_date(token)) return 0;
                break;
            case 7:
                if (!is_country_code_format(token)) return 0;
                break;
            case 9:
                if (!is_valid_date_and_hour(token)) return 0;
                break;
            case 11:
                if (!is_valid_account_status(token)) return 0;
                break;
            default:
                break;
        }

        token = strsep(&param, ";");
        i++;
    }
    
    free(token);
    return 1;
}

int is_reservation_valid(char *param, USERS_CATALOG users_catalog)
{
    int i = 0;
    char *token;
    char before_date[50];
    token = strsep(&param, ";");
    while (token != NULL)
    {
        if (!is_string_not_empty(token) && i != 13 && i != 10) return 0;

        switch (i){
            case 1:
                if (!is_user_on_the_table(users_catalog, token)) return 0;
                break;
            case 4:
                if (!is_valid_hotel_stars(token)) return 0;
                break;
            case 5:
                if (!is_valid_city_tax(token)) return 0;
                break;
            case 7:
                if (!is_valid_date(token)) return 0;
                strcpy(before_date, token);
                break;
            case 8:
                if (!is_valid_date(token)) return 0;
                if (!is_date_after(before_date, token)) return 0;
                break;
            case 9:
                if (!is_price_per_night_valid(token)) return 0;
                break;
            case 10:
                if (!is_valid_includes_breakfast(token)) return 0;
                break;
            case 12:
                if (!is_valid_rating(token)) return 0;
                break;
            default:
                break;
        }

        token = strsep(&param, ";");
        i++;
    }

    free(token);
    return 1;
}

int is_flight_valid(char *param)
{
    int i = 0;
    char *token;
    char before_airport[50];
    char before_date_sch[50];
    char before_date_real[50];
    token = strsep(&param, ";");
    while (token != NULL)
    {
        if (!is_string_not_empty(token) && i != 12) return 0;

        switch (i){
            case 3:
                if (!is_number(token)) return 0;
                break;
            case 4:
                strcpy(before_airport, token);
                break;
            case 5:
                if (!is_airports_different(before_airport, token)) return 0;
                break;
            case 6:
                if (!is_valid_date_and_hour(token)) return 0;
                strcpy(before_date_sch, token);
                break;
            case 7:
                if (!is_valid_date_and_hour(token)) return 0;
                if (!is_datetime_after(before_date_sch, token)) return 0;
                break;
            case 8:
                if (!is_valid_date_and_hour(token)) return 0;
                strcpy(before_date_real, token);
                break;
            case 9:
                if (!is_valid_date_and_hour(token)) return 0;
                if (!is_datetime_after(before_date_real, token)) return 0;
                break;
            default:
                break;
        }

        token = strsep(&param, ";");
        i++;
    }

    free(token);
    return 1;
}
