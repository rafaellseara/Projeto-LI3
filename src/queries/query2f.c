// #include "queries/query2f.h"

// void query2F(char *parameters, RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog, FLIGHTS_CATALOG flights_catalog, char *output)
// {
//     FILE *outputFile = fopen(output, "w");
//     char *id, *type;
//     id = strsep(&parameters, " ");
//     type = strsep(&parameters, " ");

//     USER user = get_user_by_id(users_catalog, id);

//     if (strcmp(type, "flights") == 0)
//     {
//         // dar print aos voos ordenados do user com id passado como argumento

//         GArray *flights = get_user_flight_list(user);

//         // ordenar, vai ser preciso iterar pela tabela de flights para aceder as datas no catalogo por causa do encapsulamento
//         // pode-se usar g_array_sort_with_data que dá para dar como arg o que for preciso

//         for (size_t i = 0; i < flights->len; i++)
//         {
//             FLIGHT flight = get_flight_by_id(flights_catalog, g_array_index(flights, char*, i));
//             char *departure_date = getScheduleDepartureDate(flight);
//             char *date;
//             date = strsep(&departure_date, " "); // para tirar os minutos e segundos

//             fprintf(outputFile, "%s;%s\n", g_array_index(flights, char*, i), date); // mudar 

//             free(departure_date);
//         }
        
//         g_array_free(flights, TRUE);
//     }
//     else if (strcmp(type, "reservations") == 0)
//     {
//         // dar print as reservas ordenadas do user com id passado como argumento

//         GArray *res = get_user_reservation_list(user);

//         // ordenar, vai ser preciso iterar pela tabela de reservas para aceder as datas no catalogo por causa do encapsulamento
//         // pode-se usar g_array_sort_with_data que dá para dar como arg o que for preciso
        
//         for (size_t i = 0; i < res->len; i++)
//         {
//             RESERVATION reservation = get_reservation_by_id(reservations_catalog, g_array_index(res, char*, i));
//             char *begin_date = getBeginDate(reservation);
//             char *date;
//             date = strsep(&begin_date, " "); // para tirar os minutos e segundos

//             fprintf(outputFile, "%s;%s\n", g_array_index(res, char*, i), date); // mudar

//             free(begin_date);
//         }
        
//         g_array_free(res, TRUE);
//     }
//     else
//     {
//         // dar print aos voos e reservas ordenados do user com id passado como argumento

//         // vai ser seguir a mesma logica do de cima, mas dar print intercalado ao que for mais recente
//         // deixo para pensar :)
//     }

//     fclose(outputFile);
// } 
