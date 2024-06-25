#include "queries/query4.h"

void query4(char *args_for_query,RESERVATIONS_CATALOG res_catalog, char *output)
{
   FILE *outputFile = fopen(output, "w");

   GArray *listaReservas = g_array_new(FALSE, FALSE, sizeof(gchar *));

   information_query4(res_catalog, args_for_query, listaReservas); // n tenho de passar como argumento??? listaReservas

   g_array_sort(listaReservas, comparaReservations);

   int i = 0;

   while (i < listaReservas->len)
   {
      RESERVATION res = g_array_index(listaReservas, RESERVATION, i);
      char id_res[20];
      int id_reservation=getIdReservations(res);
      strcpy(id_res, createBook(id_reservation));
      char *begin_date_query4=getBeginDate(res);
      char *end_date_query4=getEndDate(res);
      double price_per_night_query4= getPricePerNight_reservation(res);
      char city_tax_query4=getCityTax(res);
      char *user_id_query4=getUserIdReservations(res);
      char rating_query4=getRating(res);
      double total = calculate_stay_price(begin_date_query4, end_date_query4, price_per_night_query4, city_tax_query4);

      fprintf(outputFile, "%s;%s;%s;%s;%d;%.3f\n",
              id_res, begin_date_query4, end_date_query4, user_id_query4, rating_query4, total);
      
       free(begin_date_query4);
       free(end_date_query4);
       free(user_id_query4);

      i++;
   }

   g_array_free(listaReservas, TRUE);

   fclose(outputFile);
}

gint comparaReservations(gconstpointer a, gconstpointer b)
{
   // RESERVAS A comparacao
   const RESERVATION reservaA = *(const RESERVATION *)a;
   const RESERVATION reservaB = *(const RESERVATION *)b;

   char *begin_date_reservaA = getBeginDate(reservaA);
   char *begin_date_reservaB = getBeginDate(reservaB);

   int reservationid_reservaA = getIdReservations(reservaA);
   int reservationid_reservaB = getIdReservations(reservaB);

   int result = -(data_para_numero(begin_date_reservaA) - data_para_numero(begin_date_reservaB));

   if (data_para_numero(begin_date_reservaA) - data_para_numero(begin_date_reservaB) == 0){
      free(begin_date_reservaA);
      free(begin_date_reservaB);
      return (reservationid_reservaA) - (reservationid_reservaB);
   }

   free(begin_date_reservaA);
   free(begin_date_reservaB);
   return result;
}
