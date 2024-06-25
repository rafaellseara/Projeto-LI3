#include "queries/query4f.h"

void query4F(char *args_for_query, RESERVATIONS_CATALOG res_catalog, char *output)
{
   FILE *outputFile = fopen(output, "w");

   GArray *listaReservas = g_array_new(FALSE, FALSE, sizeof(gchar *));

   information_query4(res_catalog, args_for_query, listaReservas); // n tenho de passar como argumento??? listaReservas

   g_array_sort(listaReservas, comparaReservations);

   int i = 0;
   int c = 1;
   // devíamos dar handle no caso de não haver nenhuma reserva na lista (o len - 1 não é boa ideia)
   while (i < (listaReservas->len) - 1)
   {
      RESERVATION line = g_array_index(listaReservas, RESERVATION, i);
      int id_reserva = getIdReservations(line);
      char *book = createBook(id_reserva);
      double total = calculate_stay_price(getBeginDate(line), getEndDate(line), getPricePerNight_reservation(line), getCityTax(line));

      fprintf(outputFile, "--- %d ---\n", c);
      fprintf(outputFile, "id: %s\nbegin_date: %s\nend_date: %s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n\n",
             book, getBeginDate(line), getEndDate(line), getUserIdReservations(line), getRating(line), total);

      c++;
      i++;
      free(book);
   }

    RESERVATION line = g_array_index(listaReservas, RESERVATION, i);
    int id_reserva = getIdReservations(line);
    char *book = createBook(id_reserva);
    double totals = calculate_stay_price(getBeginDate(line), getEndDate(line), getPricePerNight_reservation(line), getCityTax(line));

    fprintf(outputFile, "--- %d ---\n", c);
    fprintf(outputFile, "id: %s\nbegin_date: %s\nend_date: %s\nuser_id: %s\nrating: %d\ntotal_price: %.3f\n",
           book, getBeginDate(line), getEndDate(line), getUserIdReservations(line), getRating(line), totals);
    free(book);

   g_array_free(listaReservas, TRUE);
   fclose(outputFile);
}
