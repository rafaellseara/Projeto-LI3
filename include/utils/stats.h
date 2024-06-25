#ifndef STATS_H
#define STATS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "catalogs/catalog_reservations.h"
#include "entities/reservation.h"

typedef struct reservation *RESERVATION; // Forward declaration

double calculate_stay_price(const char *begin_date, const char *end_date, double price_per_night, float city_tax);
int calculate_number_of_nights(const char *begin_date, const char *end_date);
int calculate_delay(char *real_departure_date, char *schedule_departure_date);
int user_age(char *birth_date);
//int busca_receita(RESERVATION reserva, char *dataInicial, char *dataFinal);
int data_para_numero(char *data);
char *createBook(int id);
// int rating_media(int rating, int acc);
// int verify_if_is_RESERVATION(char *parameters);
// int verify_if_is_FLIGHT(char *parameters);
void to_upper(char* linha);
int busca_receita(RESERVATION reserva, char *dataInicial, char *dataFinal);
#endif