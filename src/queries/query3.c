#include "queries/query3.h"


void query3(char *hotel_id, HOTELS_CATALOG  catalog, char *output)
{

       FILE *outputFile = fopen(output, "w");

       if (is_hotel_on_the_table(catalog, hotel_id)==1)
       {
            HOTEL hotel = get_hotel_by_id(catalog, hotel_id);
            int number_of_rating= getNumberofRating(hotel);
            int rating=getHOTELRating(hotel);
            double rating_total=0.0;

            if (number_of_rating > 0)
       {
              rating_total = (double)rating / number_of_rating;

              fprintf(outputFile, "%.3f\n", rating_total);
       }

       }
     
       fclose(outputFile);
}

     
       

       