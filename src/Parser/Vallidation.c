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
int validate_date(char* date_str){

    if (strlen(date_str) != 10) return 0;
    if (date_str[4] != '/' || date_str[7] != '/') return 0;
    
    int temp;
    if (is_digit(date_str[0])) temp = (date_str[0] - '0') * 1000;
    if (is_digit(date_str[1])) temp += (date_str[1] - '0') * 100;
    if (is_digit(date_str[2])) temp += (date_str[2] - '0') * 10;
    if (is_digit(date_str[3])) temp += (date_str[3] - '0');
    if (temp > 2023) return 0;

    if (is_digit(date_str[5])) temp = (date_str[5] - '0') * 10;
    if (is_digit(date_str[6])) temp += (date_str[6] - '0');
    if (temp > 12 || temp < 1) return 0;

    if (is_digit(date_str[8])) temp = (date_str[8] - '0') *10;
    if (is_digit(date_str[9])) temp += (date_str[9] - '0');
    if (temp > 31 || temp < 1) return 0;

    return 1;
}

//Verifies the date and hour format
int validate_date_and_hour(char* date_str){
    
    if (strlen(date_str) != 19) return 0;
    if (date_str[4] != '/' || date_str[7] != '/' || date_str[13] != ':' || date_str[16] != ':') return 0;
    
    int temp;
    if (is_digit(date_str[0])) temp = (date_str[0] - '0') * 1000;
    if (is_digit(date_str[1])) temp += (date_str[1] - '0') * 100;
    if (is_digit(date_str[2])) temp += (date_str[2] - '0') * 10;
    if (is_digit(date_str[3])) temp += (date_str[3] - '0');
    if (temp > 2023) return 0;

    if (is_digit(date_str[5])) temp = (date_str[5] - '0') * 10;
    if (is_digit(date_str[6])) temp += (date_str[6] - '0');
    if (temp > 12 || temp < 1) return 0;

    if (is_digit(date_str[8])) temp = (date_str[8] - '0') *10;
    if (is_digit(date_str[9])) temp += (date_str[9] - '0');
    if (temp > 31 || temp < 1) return 0;

    if (is_digit(date_str[11])) temp = (date_str[11] - '0') *10;
    if (is_digit(date_str[12])) temp += (date_str[12] - '0');
    if (temp > 23 || temp < 0) return 0;

    if (is_digit(date_str[14])) temp = (date_str[14] - '0') *10;
    if (is_digit(date_str[15])) temp += (date_str[15] - '0');
    if (temp > 59 || temp < 0) return 0;

    if (is_digit(date_str[17])) temp = (date_str[11] - '0') *10;
    if (is_digit(date_str[18])) temp += (date_str[12] - '0');
    if (temp > 59 || temp < 0) return 0;

    return 1;
}

//Verifies if the dates are in order
int is_date_after(char *date1_str, char *date2_str) {
    struct tm date1 = parse_date(date1_str);
    struct tm date2 = parse_date(date2_str);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return (time1 <= time2);
}

//Verifies if the dates and hours are in order
int is_datetime_after(char *date1_str, char *date2_str) {
    struct tm date1 = parse_datetime(date1_str);
    struct tm date2 = parse_datetime(date2_str);

    time_t time1 = mktime(&date1);
    time_t time2 = mktime(&date2);

    return (time1 <= time2);
}

//The function verifies if a given string adheres to the standard email format
int is_email_format(char *email_str){

    //It verifies whether the email address contains the '@' symbol and that the username is at least one character in width
    int i;
    for(i = 0; (email_str[i] != '@') && (email_str[i] != '\0'); i++);
    if (i < 1) return 0;
    if (strlen(email_str) == i) return 0; 
    
    //It verifies if the email address contain a '.' and if the domain is at least one character in width
    int n = 0;
    for (i++; (email_str[i] != '.') && (email_str[i] != '\0'); i++ && n++);
    if (n < 1) return 0;
    if (strlen(email_str) == i) return 0;

    //It verifies if the TLD is at least two character in width
    for((i++) && (n = 0); email_str[i] != '\0'; i++ && n++);
    if (n < 2) return 0;

    return 1;
}

int main() {
    int result;
    char data1[20] = "2022/10/01 11:02:12";
    char data2[20] = "2022/10/01 10:02:12";
    char email[9] = "aas@as.da";

    result = is_email_format(email);
    
    printf("resultado %d \n", result);
}