/*#include "queries/query2.h"
#include "queries/query4.h"

#include <glib.h>

void query2(char *parameters, RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, char *output)
{
    FILE *outputFile = fopen(output, "w");
    char *id, *type;
    id = strsep(&parameters, " ");
    type = strsep(&parameters, " ");

    USER user = get_user_by_id(users_catalog, id);
    if (type != NULL && strcmp(type, "flights") == 0)
    {
        // dar print aos voos ordenados do user com id passado como argumento???

        GArray *flights = get_user_flight_list(user);

        // ordenar, vai ser precCDiso iterar pela tabela de flights para aceder as datas no catalogo por causa do encapsulamento
        // pode-se usar g_array_sort_with_data que dá para dar como arg o que for preciso
        // g_array_sort_with_data(flights, comparaFLights, flights_catalog);

        for (size_t i = 0; i < flights->len; i++)
        {
            FLIGHT flight = get_flight_by_id(flights_catalog, atoi(g_array_index(flights, char *, i)));
            char *departure_date = getScheduleDepartureDate(flight);
            char *date;
            date = strsep(&departure_date, " "); // para tirar os minutos e segundos

            fprintf(outputFile, "%s;%s\n", g_array_index(flights, char *, i), date);

            // free(departure_date);
        }

        // g_array_free(flights, TRUE);
    }
    else if (type != NULL && strcmp(type, "reservations") == 0)
    {
        // dar print as reservas ordenadas do user com id passado como argumento

        GArray *res = get_user_reservation_list(user);

        // g_array_sort_with_data(res, comparaReservations, reservations_catalog);

        // ordenar, vai ser preciso iterar pela tabela de reservas para aceder as datas no catalogo por causa do encapsulamento
        // pode-se usar g_array_sort_with_data que dá para dar como arg o que for preciso

        for (size_t i = 0; i < res->len; i++)
        {
            RESERVATION reservation = get_reservation_by_id(reservations_catalog, atoi(g_array_index(res, char *, i)));
            char *begin_date = getBeginDate(reservation);
            char *date;
            date = strsep(&begin_date, " "); // para tirar os minutos e segundos

            fprintf(outputFile, "%s;%s\n", g_array_index(res, char *, i), date);

            // free(begin_date);
        }

        // g_array_free(res, TRUE);
    }
    else
    {
        GArray *flights = get_user_flight_list(user);
        GArray *reservations = get_user_reservation_list(user);

        printf("UIUI\n");

        // // ordenar os 2 de cima
        g_array_sort_with_data(flights, comparaFLights, flights_catalog);
        g_array_sort_with_data(reservations, comparaReservas, reservations_catalog);
        //qsort(reservations, reservations->len, sizeof(int), comparaReservas);
        printf("saiu?\n");
        // // Combinar e ordenar as listas intercaladamente por data
        // // Imprimir intercaladamente comparando datas entre voos e reservas

        // GArray *combined = combine_and_sort_lists_by_date(flights, reservations, flights_catalog, reservations_catalog);
        //
        // for (size_t i = 0; i < combined->len; i++)
        // {
        //     char *id = g_array_index(combined, char *, i);
        //     char *date;

        //     if (is_id_in_array(id, flights))
        //     {
        //         FLIGHT flight = get_flight_by_id(flights_catalog, atoi(id));
        //         char *departure_date = getScheduleDepartureDate(flight);
        //         date = strsep(&departure_date, " ");
        //         // free(departure_date);
        //     }
        //     else
        //     {
        //         RESERVATION reservation = get_reservation_by_id(reservations_catalog, atoi(id));
        //         char *begin_date = getBeginDate(reservation);
        //         date = strsep(&begin_date, " ");
        //         // free(begin_date);
        //     }

        //     fprintf(outputFile, "%s;%s\n", id, date);
        // }

        // g_array_free(flights, TRUE);
        // g_array_free(reservations, TRUE);
        // g_array_free(combined, TRUE);
        // dar print aos voos e reservas ordenados do user com id passado como argumento

        // vai ser seguir a mesma logica do de cima, mas dar print intercalado ao que for mais recente
        // deixo para pensar :)
    }
    fclose(outputFile);

    printf("ESTOU AQUI\n");
}

int extrairNumeroDaReserva(const char *idReserva)
{
    int numero;

    if (sscanf(idReserva, "Book%d", &numero) == 1)
    {
        return numero;
    }
    else
    {
        // retornar -1 para indicar que a extração falhou.
        return -1;
    }
}

void comparaReservas(const void* a, const void* b)
{
    // RESERVAS comparacao
    int x = GPOINTER_TO_INT(a);

    printf("entrou\n");
    printf("%d\n", x);
    printf("aqui?\n");
    // RESERVATIONS_CATALOG catalogo = (RESERVATIONS_CATALOG)user_data;
    printf("entrou2\n");
    // RESERVATION reservaA = get_reservation_by_id(catalogo, atoi(idReservaA));
    // RESERVATION reservaB = get_reservation_by_id(catalogo, atoi(idReservaB));
    printf("entrou3\n");
    // char *dataA = getBeginDate(reservaA);
    // char *dataB = getBeginDate(reservaB);
    // printf("entrou4, 1: %s , 2: %s\n", idReservaA, idReservaB);

    // int result = -(data_para_numero(getBeginDate(idReservaA)) - data_para_numero(getBeginDate(idReservaB)));
    // printf("wtf1\n");
    // if (data_para_numero(idReservaA) - data_para_numero(idReservaB) == 0)
    // {
    //     return extrairNumeroDaReserva(idReservaA) - extrairNumeroDaReserva(idReservaB);
    // }
    // printf("wtf2\n");
    // return result;
    return 1;
}

gint comparaFLights(gconstpointer a, gconstpointer b, gpointer user_data)
{
    // VOOS comparacao
    const FLIGHT vooA = *(const FLIGHT *)a;
    const FLIGHT vooB = *(const FLIGHT *)b;
    char *scheduleDateA = getScheduleDepartureDate(vooA);
    char *scheduleDateB = getScheduleDepartureDate(vooB);

    int result = -(data_para_numero(scheduleDateA) - data_para_numero(scheduleDateB));

    if (data_para_numero(scheduleDateA) - data_para_numero(scheduleDateB) == 0)
    {
        return (getIdFlights(vooA)) - (getIdFlights(vooB));
    }

    return result;
}

GArray *combine_and_sort_lists_by_date(GArray *list1, GArray *list2, FLIGHTS_CATALOG flights_catalog, RESERVATIONS_CATALOG reservations_catalog)
{
    GArray *combined = g_array_new(FALSE, FALSE, sizeof(char *));

    // Adiciona elementos das duas listas à lista combinada
    for (size_t i = 0; i < list1->len; i++)
    {
        g_array_append_val(combined, g_array_index(list1, char *, i));
    }

    for (size_t i = 0; i < list2->len; i++)
    {
        g_array_append_val(combined, g_array_index(list2, char *, i));
    }

    // Ordena a lista combinada usando a função de comparação de datas
    // g_array_sort_with_data(combined, comparaFLights, NULL);

    return combined;
}

// Função para verificar se um ID está em uma lista
gboolean is_id_in_array(const char *id, GArray *array)
{
    for (size_t i = 0; i < array->len; i++)
    {
        const char *current_id = g_array_index(array, const char *, i);

        if (strcmp(current_id, id) == 0)
        {
            return TRUE; // ID encontrado na lista
        }
    }
    return FALSE; // ID não encontrado na lista
} 
*/