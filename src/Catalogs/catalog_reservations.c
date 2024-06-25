#include "catalogs/catalog_reservations.h"

struct reservations_catalog
{
    GHashTable *reservations;
};

RESERVATIONS_CATALOG create_reservation_catalog()
{
    RESERVATIONS_CATALOG new_catalog = g_malloc(sizeof(struct reservations_catalog));

    new_catalog->reservations = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)free_reservation);
    
    return new_catalog;
}

void insert_reservation(RESERVATIONS_CATALOG catalog, RESERVATION reservation, void *key)
{
    g_hash_table_insert(catalog->reservations, key, reservation);
}

int is_reservation_on_the_table(RESERVATIONS_CATALOG catalog, int id)
{
    if (g_hash_table_lookup(catalog->reservations, GINT_TO_POINTER(id)) == NULL)
        return 0;
    else
        return 1;
}

RESERVATION get_reservation_by_id(RESERVATIONS_CATALOG catalog, int id)
{
    return g_hash_table_lookup(catalog->reservations, GINT_TO_POINTER(id));
}

void free_reservations_catalog(RESERVATIONS_CATALOG catalog)
{
    g_hash_table_destroy(catalog->reservations);
    g_free(catalog);
}

double total_spent(char *parameters, RESERVATIONS_CATALOG catalog){
    
    double total_spent=0.0;
    GHashTableIter iter;
    gpointer key, value;
    g_hash_table_iter_init(&iter, catalog->reservations);
    while (g_hash_table_iter_next(&iter, &key, &value))
    {

        RESERVATION reservation = (RESERVATION)value;
        const char *user_id = getUserIdReservations(reservation);
        if (strcmp(user_id, parameters) == 0)
        {

            double total = getPricePerNight_reservation(reservation);
            const char *begin_date = getBeginDate(reservation);
            const char *end_date = getEndDate(reservation);
            int number_nights = calculate_number_of_nights(begin_date, end_date);
            float city_tax = getCityTax(reservation);

            total_spent = total_spent + ((total * number_nights) + ((total * number_nights) / 100 * city_tax));
        }
    }
    return total_spent;
}



void information_query4(RESERVATIONS_CATALOG catalog, char *arg, GArray *listaReservas){

    GHashTableIter iter;
    gpointer key, value;

   g_hash_table_iter_init(&iter, catalog->reservations);

   while (g_hash_table_iter_next(&iter, &key, &value))
   {
      RESERVATION reserva_nova = (RESERVATION)value;
      char *hotel_id=getHotelId(reserva_nova);
      if (strcmp(hotel_id, arg) == 0)
      {
         g_array_append_val(listaReservas, reserva_nova);
      }
      free(hotel_id);
   }

}

void information_query8(RESERVATIONS_CATALOG catalog, char *parametros, char *id, char *dataInicial, char *dataFinal, int *receitaFinal){

    int receita = 0;

    GHashTableIter iter;
    gpointer key, value;

    g_hash_table_iter_init(&iter, catalog->reservations);

    while (g_hash_table_iter_next(&iter, &key, &value))
    {
        char* hotel_id = getHotelId(value);
        if (strcmp(id, hotel_id) == 0)
        {
            receita = receita + busca_receita(value, dataInicial, dataFinal);
        }
        free(hotel_id);
    }

    *receitaFinal = receita;
}
