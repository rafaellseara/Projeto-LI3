#include "entities/reservation.h"
#include "catalogs/catalog_users.h"

struct reservation
{
    int id;
    char *user_id;
    char *hotel_id;
    char *hotel_name;
    char *begin_date;
    char *end_date;
    double price_per_night;
    char city_tax;
    char includes_breakfast;
    char rating;
    char hotel_stars;
};

RESERVATION create_reservation()
{
    RESERVATION new_reservation = malloc(sizeof(struct reservation));
    return new_reservation;
}

void free_reservation(RESERVATION reservation)
{
     free(reservation->user_id);
     free(reservation->hotel_id);
     free(reservation->hotel_name);
     free(reservation->begin_date);
     free(reservation->end_date);

     free(reservation);
}

void build_reservation(char *reservation_details, void *catalog, USERS_CATALOG users_catalog)
{
    RESERVATION reservation = create_reservation();
    RESERVATIONS_CATALOG reservations_catalog = (RESERVATIONS_CATALOG)catalog;

    int i = 0;
    char *token;
    char *res_id;
    char* user_id;
    token = strsep(&reservation_details, ";");
    while (token != NULL)
    {
        switch (i)
        {
        case 0:
            setIdReservations(reservation, token);
            res_id = strdup(token);
            break;
        case 1:
            setUserIdReservations(reservation, token);
            if (is_user_on_the_table(users_catalog, token) == 1){
                set_user_reservation_list(get_user_by_id(users_catalog, token), res_id);
            }   
            break;
        case 2:
            setHotelId(reservation, token);
            break;
        case 3:
            setHotelName(reservation, token);
            break;
        case 4:
            setHotelStars(reservation, token);
            break;
        case 5:
            setCityTax(reservation, token);
            break;
        case 7:
            setBeginDate(reservation, token);
            break;
        case 8:
            setEndDate(reservation, token);
            break;
        case 9:
            setPricePerNight_reservation(reservation, token);
            break;
        case 10:
            setIncludesBreakfast(reservation, token);
            break;
        case 12:
            setRating(reservation, token);
            break;
        }

        token = strsep(&reservation_details, ";");
        i++;
    }
    free(token);
    free(res_id);
  
    insert_reservation(reservations_catalog, reservation, reservation->id);
}

void setIdReservations(RESERVATION reservation, char *id)
{
    int id_int;
    sscanf(id, "Book%d", &id_int);
    reservation->id = id_int;
}

int getIdReservations(RESERVATION reservation)
{
    int id = reservation->id;
    return id;
}

void setUserIdReservations(RESERVATION reservation, char *user_id)
{
    reservation->user_id = strdup(user_id);
}

char *getUserIdReservations(RESERVATION reservation)
{
    return strdup(reservation->user_id);
}

void setHotelId(RESERVATION reservation, char *hotel_id)
{
    reservation->hotel_id = strdup(hotel_id);
}

char *getHotelId(RESERVATION reservation)
{
    return strdup(reservation->hotel_id);
}

void setHotelName(RESERVATION reservation, char *hotel_name)
{
    reservation->hotel_name = strdup(hotel_name);
}

char *getHotelName(RESERVATION reservation)
{
    return strdup(reservation->hotel_name);
}

void setHotelStars(RESERVATION reservation, char *hotel_stars)
{
    int HotelStarsInt = strtol(hotel_stars, NULL, 10);
    reservation->hotel_stars = HotelStarsInt;
}

int getHotelStars(RESERVATION reservation)
{
    int HotelStars = reservation->hotel_stars;
    return HotelStars;
}

void setCityTax(RESERVATION reservation, char *city_tax)
{
    float CityTaxFloat = atof(city_tax);
    reservation->city_tax = CityTaxFloat;
}

float getCityTax(RESERVATION reservation)
{
    float CityTax = reservation->city_tax;
    return CityTax;
}

void setBeginDate(RESERVATION reservation, char *begin_date)
{
    reservation->begin_date = strdup(begin_date);
}

char *getBeginDate(RESERVATION reservation)
{
    return strdup(reservation->begin_date);
}

void setEndDate(RESERVATION reservation, char *end_date)
{
    reservation->end_date = strdup(end_date);
}

char *getEndDate(RESERVATION reservation)
{
    return strdup(reservation->end_date);
}

void setPricePerNight_reservation(RESERVATION reservation, char *price_per_night)
{

    double price_per_night_double = strtod(price_per_night, NULL);
    reservation->price_per_night = price_per_night_double;
}

double getPricePerNight_reservation(RESERVATION reservation)
{
    double PricePerNight = reservation->price_per_night;
    return PricePerNight;
}

void setIncludesBreakfast(RESERVATION reservation, char *includes_breakfast)
{
    if (strcmp(includes_breakfast, "true") == 0 || strcmp(includes_breakfast, "t") == 0 || strcmp(includes_breakfast, "1") == 0)
    {
        reservation->includes_breakfast = 1;
    }
    else
    {
        reservation->includes_breakfast = 0;
    }
}

int getIncludesBreakfast(RESERVATION reservation)
{
    int IncludesBreakfast = reservation->includes_breakfast;
    return IncludesBreakfast;
}

void setRating(RESERVATION reservation, char *rating)
{
    int rating_int = strtol(rating, NULL, 10);
    reservation->rating = rating_int;
}

int getRating(RESERVATION reservation)
{
    int rating = reservation->rating;
    return rating;
}
