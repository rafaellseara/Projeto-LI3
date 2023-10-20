#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


// Verifies if the character is a digit
int is_digit(char character) { return (character >= '0' && character <= '9'); }

/*
Parsing the date string to a date struct
First we use the tm struct from the time library to create a struct for the date
Then we use memset to atribute 0 to all the variables in the struct
After that we use strtime with the specific format to transform the date in the string to our date in the struct
*/
struct tm parse_date(const char *date_str) {
    struct tm date;
    memset(&date, 0, sizeof(struct tm));
    strptime(date_str, "%Y/%m/%d", &date);
    return date;
}

/*
Parsing the date string to a date struct
First we use the tm struct from the time library to create a struct for the date
Then we use memset to atribute 0 to all the variables in the struct
After that we use strtime with the specific format to transform the date in the string to our date in the struct
*/
struct tm parse_datetime(const char *datetime_str) {
    struct tm datetime;
    memset(&datetime, 0, sizeof(struct tm));
    strptime(datetime_str, "%Y/%m/%d %H:%M:%S", &datetime);
    return datetime;
}

//Verifies the date format
int validate_date(char* date_string){

    if (strlen(date_string) != 10) return 0;
    if (date_string[4] != '/' || date_string[7] != '/') return 0;
    
    int temp;
    if (is_digit(date_string[0])) temp = (date_string[0] - '0') * 1000;
    if (is_digit(date_string[1])) temp += (date_string[1] - '0') * 100;
    if (is_digit(date_string[2])) temp += (date_string[2] - '0') * 10;
    if (is_digit(date_string[3])) temp += (date_string[3] - '0');
    if (temp > 2023) return 0;

    if (is_digit(date_string[5])) temp = (date_string[5] - '0') * 10;
    if (is_digit(date_string[6])) temp += (date_string[6] - '0');
    if (temp > 12 || temp < 1) return 0;

    if (is_digit(date_string[8])) temp = (date_string[8] - '0') *10;
    if (is_digit(date_string[9])) temp += (date_string[9] - '0');
    if (temp > 31 || temp < 1) return 0;

    return 1;
}

//Verifies the date and hour format
int validate_date_and_hour(char* date_string){
    
    if (strlen(date_string) != 19) return 0;
    if (date_string[4] != '/' || date_string[7] != '/' || date_string[13] != ':' || date_string[16] != ':') return 0;
    
    int temp;
    if (is_digit(date_string[0])) temp = (date_string[0] - '0') * 1000;
    if (is_digit(date_string[1])) temp += (date_string[1] - '0') * 100;
    if (is_digit(date_string[2])) temp += (date_string[2] - '0') * 10;
    if (is_digit(date_string[3])) temp += (date_string[3] - '0');
    if (temp > 2023) return 0;

    if (is_digit(date_string[5])) temp = (date_string[5] - '0') * 10;
    if (is_digit(date_string[6])) temp += (date_string[6] - '0');
    if (temp > 12 || temp < 1) return 0;

    if (is_digit(date_string[8])) temp = (date_string[8] - '0') *10;
    if (is_digit(date_string[9])) temp += (date_string[9] - '0');
    if (temp > 31 || temp < 1) return 0;

    if (is_digit(date_string[11])) temp = (date_string[11] - '0') *10;
    if (is_digit(date_string[12])) temp += (date_string[12] - '0');
    if (temp > 23 || temp < 0) return 0;

    if (is_digit(date_string[14])) temp = (date_string[14] - '0') *10;
    if (is_digit(date_string[15])) temp += (date_string[15] - '0');
    if (temp > 59 || temp < 0) return 0;

    if (is_digit(date_string[17])) temp = (date_string[11] - '0') *10;
    if (is_digit(date_string[18])) temp += (date_string[12] - '0');
    if (temp > 59 || temp < 0) return 0;

    return 1;
}

int is_date_after(char *date1_str, char *date2_str) {
    struct tm date1 = parse_date(date1_str);
    struct tm date2 = parse_date(date2_str);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return (time1 >= time2);
}

int is_datetime_after(char *date1_str, char *date2_str) {
    struct tm date1 = parse_datetime(date1_str);
    struct tm date2 = parse_datetime(date2_str);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return (time1 >= time2);
}

int main() {
    int result;
    char data1[20] = "2022/10/01 12:02:12";
    char data2[20] = "2022/10/01 11:01:12";

    result = is_datetime_after(data1, data2);
    
    printf("resultado %d \n", result);
}