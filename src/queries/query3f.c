#include "queries/query3f.h"

void query3F(char *hotel_id, HOTELS_CATALOG  catalog, char *output)
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

              fprintf(outputFile, "--- 1 ---\n");
              fprintf(outputFile, "rating: %.3f\n", rating_total);
       }

       }
       
       fclose(outputFile);
}
