#include "queries/query1.h"

double total_spent_in_reservations(char *parameters, RESERVATIONS_CATALOG catalog)
{
    double total_spent_in_reservation = total_spent(parameters, catalog);

    return total_spent_in_reservation;
}


void query1(char *parameters, RESERVATIONS_CATALOG reservations_catalog, USERS_CATALOG users_catalog,
            FLIGHTS_CATALOG flights_catalog, char *output)
{
    
    FILE *outputFile = fopen(output, "w");

    int parameters_int = strtol(parameters, NULL, 10);

    if (parameters_int != 0 && is_flight_on_the_table(flights_catalog, parameters_int) == 1)
    {
        FLIGHT flight = get_flight_by_id(flights_catalog, parameters_int);

        char *airline = getAirline(flight);
        char *plane_model = getPlaneModel(flight);
        char *origin = getOrigin(flight);
        char *destination = getDestination(flight);
        char *schedule_departure_date = getScheduleDepartureDate(flight);
        char *schedule_arrival_date = getScheduleArrivalDate(flight);
        char *real_departure_date = getRealDepartureDate(flight);
        int number_of_passengers = getNumPass(flight);
        int delay = calculate_delay(real_departure_date, schedule_departure_date);

        fprintf(outputFile, "%s;%s;%s;%s;%s;%s;%d;%.0f\n",
                airline, plane_model, origin, destination, schedule_departure_date, schedule_arrival_date, number_of_passengers, delay);

        free(airline);
        free(plane_model);
        free(origin);
        free(destination);
        free(schedule_departure_date);
        free(schedule_arrival_date);
        free(real_departure_date);
    }
    else if (strncmp(parameters, "Book", 4) == 0)
    {
        int id_int;
        sscanf(parameters, "Book%d", &id_int);

        if (is_reservation_on_the_table(reservations_catalog, id_int) == 1)
        {
            RESERVATION reserva = get_reservation_by_id(reservations_catalog, id_int);

            char *hotel_name = getHotelName(reserva);
            char *hotel_id = getHotelId(reserva);
            int hotel_stars = getHotelStars(reserva);
            const char *begin_date = getBeginDate(reserva);
            const char *end_date = getEndDate(reserva);
            int includes_breakfast = getIncludesBreakfast(reserva);
            double price_per_night = getPricePerNight_reservation(reserva);
            float city_tax = getCityTax(reserva);
            double stay_price = calculate_stay_price(begin_date, end_date, price_per_night, city_tax);
            int number_nights = calculate_number_of_nights(begin_date, end_date);
            char includes_breakfast_char[10];

            if (includes_breakfast == 0)
                strcpy(includes_breakfast_char, "False");
            else
                strcpy(includes_breakfast_char, "True");

            fprintf(outputFile, "%s;%s;%d;%s;%s;%s;%d;%.3f\n",
                    hotel_id, hotel_name, hotel_stars, begin_date, end_date, includes_breakfast_char, number_nights, stay_price);

            free(hotel_name);
            free(hotel_id);
            // free(begin_date);
            // free(end_date);
        }
    }
    /*else
    {
        if (is_user_on_the_table(users_catalog, parameters) == 1)
        {
            USER user = get_user_by_id(users_catalog, parameters);
            char *accountStatus = getAccountStatus(user);
            if (strcmp(accountStatus, "active") == 0)
            {

                char *name = getName(user);
                char *sex = getSex(user);
                char *birth_date = getBirthDate(user);
                int age = user_age(birth_date);
                char *country_code = getCountryCode(user);
                char *passport = getPassport(user);
                double total_spent_reservation = total_spent_in_reservations(parameters, reservations_catalog);
                int res_num = get_user_reservation_length_list(user);
                int fli_num = get_user_flight_length_list(user);
                fprintf(outputFile, "%s;%s;%d;%s;%s;%d;%d;%.3f\n",
                        name, sex, age, country_code, passport, fli_num, res_num, total_spent_reservation);

                free(name);
                free(sex);
                free(birth_date);
                free(country_code);
                free(passport);
            }
            free(accountStatus);
        }
    }*/

    fclose(outputFile);
}
