#include "entities/hotel.h"

struct hotel
{
    char *hotel_id;
    int rating;
    int number_of_ratings;

};

HOTEL create_hotel()
{
    HOTEL new_hotel = malloc(sizeof(struct hotel));
    new_hotel->rating=0;
    new_hotel->number_of_ratings=0;
    return new_hotel;
}

void free_hotel(gpointer data)
{
    HOTEL hotel = (HOTEL)data;
    free(hotel->hotel_id);

    free(hotel);
}

void build_hotel(void *catalog, char *reservation_details)
{
   
    HOTELS_CATALOG hotels_catalog = (HOTELS_CATALOG)catalog;

    int i =0;
    char *token;
    char *hotel_id;
    char *rating;
    int ratingINT=0;
    token= strsep(&reservation_details,";");

    while (token != NULL)
    {
    
    if (i==2)
    {
    hotel_id=strdup(token);
    }   
    if (i ==12)
    {
    rating=strdup(token);
    }

    token=strsep(&reservation_details, ";");
    i++;
    }
    
    free(token);
    
    
    ratingINT=atoi(rating);

    if (is_hotel_on_the_table(hotels_catalog,hotel_id)==1)
    {   
       
        HOTEL hotel=get_hotel_by_id(catalog,hotel_id); 

        setHOTELRating(hotel, ratingINT);
        setNumberofRating(hotel);
       
    }
    
    else
    {   
        HOTEL hotel = create_hotel(); 
    
        setHotelIdHOTEL(hotel,hotel_id);
        setHOTELRating(hotel, ratingINT);
        setNumberofRating(hotel);

        insert_hotel(catalog,hotel,hotel_id);
    }
    
    free(hotel_id);
    free(rating);
}

void setHotelIdHOTEL(HOTEL hotel, char *hotel_id)
{
    hotel->hotel_id = strdup(hotel_id);
}

char *getHotelIdHOTEL(HOTEL hotel)
{
    return strdup(hotel->hotel_id);
}

void setHOTELRating(HOTEL hotel, int ratingINT)
{
    hotel->rating += ratingINT;
}

int getHOTELRating(HOTEL hotel)
{
    return hotel->rating;
}
    
void setNumberofRating(HOTEL hotel)
{
    hotel->number_of_ratings += 1;
}

int getNumberofRating(HOTEL hotel)
{
    return hotel->number_of_ratings;
}