#include "utils/stats.h"

#include <glib.h>
#include <ctype.h>

double calculate_stay_price(const char *begin_date, const char *end_date, double price_per_night, float city_tax)
{
    int first_day;
    int first_month;
    int first_year;
    sscanf(begin_date, "%d/%d/%d", &first_year, &first_month, &first_day);
    int last_day;
    int last_month;
    int last_year;
    sscanf(end_date, "%d/%d/%d", &last_year, &last_month, &last_day);
    double stay_price = (price_per_night * (last_day - first_day)) + ((price_per_night * (last_day - first_day)) / 100 * city_tax);
    return stay_price;
}

int calculate_number_of_nights(const char *begin_date, const char *end_date)
{
    int first_day;
    int first_month;
    int first_year;
    sscanf(begin_date, "%d/%d/%d", &first_year, &first_month, &first_day);
    int last_day;
    int last_month;
    int last_year;
    sscanf(end_date, "%d/%d/%d", &last_year, &last_month, &last_day);

    int number_of_nights = last_day - first_day;
    return number_of_nights;
}

int calculate_delay(char *real_departure_date, char *schedule_departure_date)
{
    int year, month, day, hour, minute, second;
    sscanf(real_departure_date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    long long date_number = year * 31536000 + month * 2678400 + day * 86400 + hour * 3600 + minute * 60 + second;
    sscanf(schedule_departure_date, "%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

    long long date_number_2 = year * 31536000 + month * 2678400 + day * 86400 + hour * 3600 + minute * 60 + second;

    return date_number - date_number_2;
}

int user_age(char *birth_date)
{
    int year_of_birth;
    int month_of_birth;
    int day_of_birth;
    sscanf(birth_date, "%d/%d/%d", &year_of_birth, &month_of_birth, &day_of_birth);

    char *current_date = "2023/10/01";

    int current_year;
    int current_month;
    int current_day;
    sscanf(current_date, "%d/%d/%d", &current_year, &current_month, &current_day);

    int age = current_year - year_of_birth;
    if (current_month < month_of_birth || (current_month == month_of_birth && current_day < day_of_birth))
    {
        age--;
    }

    return age;
}


int data_para_numero(char *data)
{

    int ano, mes, dia;
    sscanf(data, "%d/%d/%d", &ano, &mes, &dia);

    return ano * 365 + mes * 30 + dia;
}

char *createBook(int id)
{
   char *res_id = malloc(20 + sizeof(char));
   char id_str[20];
   sprintf(id_str, "%d", id);
   size_t length = strlen(id_str);
   strcpy(res_id, "Book");

   for (int i = 10; i > length; i--)
   {
      strcat(res_id, "0");
   }
   strcat(res_id, id_str);
   return res_id;
}

// int rating_media(int rating, int acc)
// {
//     int rating_media_1 = rating / acc;
//     return rating_media_1;
// }

// int verify_if_is_RESERVATION(char *parameters)
// {

//     char *prefix = "Book";
//     int length = strlen(prefix);
//     if (strncmp(parameters, prefix, length) == 0)
//     {
//         return 0;
//     }
//     else
//     {
//         return 1;
//     }
// }

// int verify_if_is_FLIGHT(char *parameters)
// {
//     while (*parameters)
//     {
//         if (!isdigit(*parameters))
//         {
//             return 0; // Se encontrou um caractere que não é um dígito, retorna falso
//         }
//         parameters++;
//     }
//     return 1; // Se todos os caracteres são dígitos, retorna verdadeiro
// }

// int dateToInt(char *date)
// {
//     return atoi(date);
// }

// // Verifica se a data fornecida está entre duas datas
// bool isDateBetween(char *targetDate, char *startDate, char *endDate)
// {
//     int target = dateToInt(targetDate);
//     int start = dateToInt(startDate);
//     int end = dateToInt(endDate);

//     return target >= start && target <= end;
// }

void to_upper(char* linha) {
    for (int i = 0; i < strlen(linha); i++) {
        linha[i] = toupper((unsigned char)linha[i]);
    }
}


int compare_integers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Função para calcular a mediana de um GArray de inteiros
int calcularMediana(GArray *array) {
    if (array == NULL || array->len == 0) {
        // Tratar caso de array vazio ou nulo
        return 0; // ou outro valor padrão
    }

    // Ordenar o array
    g_array_sort(array, compare_integers);

    // Calcular a posição do elemento do meio
    int meio = array->len / 2;

    // Se o tamanho do array for ímpar, retornar o valor do meio
    if (array->len % 2 != 0) {
        return g_array_index(array, int, meio);
    }
    // Se o tamanho do array for par, calcular a média dos dois elementos do meio
    else {
        int valor1 = g_array_index(array, int, meio - 1);
        int valor2 = g_array_index(array, int, meio);
        return (valor1 + valor2) / 2;
    }
}

int busca_receita(RESERVATION reserva, char *dataInicial, char *dataFinal)
{
    int r = 1;
    const char *dataInicialReserva = getBeginDate(reserva); // 1
    const char *dataFinalReserva = getEndDate(reserva); // 2 
    int precoPorNoite = getPricePerNight_reservation(reserva); 

    if (strcmp(dataInicial, dataFinalReserva) == 1 || strcmp(dataInicialReserva, dataFinal) == 1)
    {
        free(dataFinalReserva);
        free(dataInicialReserva);
        return 0;
    }

    int dataInicialNumero = data_para_numero(dataInicial);
    int dataFinalNumero = data_para_numero(dataFinal);
    int dataInicialReservaNumero = data_para_numero(dataInicialReserva);
    int dataFinalReservaNumero = data_para_numero(dataFinalReserva);

    int inicio_reserva = (dataInicialReservaNumero > dataInicialNumero) ? dataInicialReservaNumero : dataInicialNumero;
    int fim_reserva = (dataFinalReservaNumero <= dataFinalNumero) ? dataFinalReservaNumero : dataFinalNumero + 1;

    int number_of_nights = (fim_reserva - inicio_reserva) > 0 ? (fim_reserva - inicio_reserva) : 0;

    int receita = precoPorNoite * number_of_nights;

    return receita;
}

