#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include <stdio.h>
#include <ncurses.h>
#include "catalogs/catalog_flights.h"
#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"
#include "parser/parser.h"
#include "queries/query1.h"
#include "queries/query8.h"
#include "queries/query4.h"
#include "queries/query3.h"
#include "queries/query9.h"
#include "queries/query5.h"
#include "queries/query6.h"

/**
 * @brief Get the parent directory of the given path.
 *
 * @param path The input path.
 * @return parent - The parent directory as a dynamically allocated string (`char*`).
 */
char* get_directory_parent(const char* path);

/**
 * @brief Get the contents of a directory.
 *
 * @param path The path of the directory.
 * @param num_entries Pointer to an integer where the number of entries will be stored.
 * @return contents - An array of strings representing the directory contents.
 */
char** get_directory_contents(const char* path, int* num_entries);

/**
 * @brief Print a menu with directory contents.
 *
 * @param menu_win The window where the menu will be displayed.
 * @param contents The array of strings representing the menu items.
 * @param highlight The index of the currently highlighted item.
 * @param num_entries The total number of entries in the menu.
 */
void print_menu(WINDOW* menu_win, char** contents, int highlight, int num_entries);

/**
 * @brief Allow the user to choose a directory using a menu.
 *
 * @param current_path The current directory path.
 * @param linhas The number of rows in the terminal.
 * @param colunas The number of columns in the terminal.
 * @return chosen_path - The chosen directory path as a dynamically allocated string (`char*`).
 */
char* choose_path_menu(const char* current_path, int linhas, int colunas);

/**
 * @brief Allow the user to choose a query using a menu.
 *
 * @param linhas The number of rows in the terminal.
 * @param colunas The number of columns in the terminal.
 * @return choice - The chosen query number.
 */
int choose_query_menu(int linhas, int colunas);

/**
 * @brief Allow the user to input a string using a menu.
 *
 * @param linhas The number of rows in the terminal.
 * @param colunas The number of columns in the terminal.
 * @return input - The user-inputted string as a dynamically allocated string (`char*`).
 */
char* choose_input_menu(int linhas, int colunas);

/**
 * @brief Perform batch processing for interactive mode based on user choices.
 *
 * @param path The path to the dataset directory.
 * @param query The chosen query number.
 * @param input The user-inputted string.
 */
void batch_for_interactive(char* path, int query, char* input);

/**
 * @brief Display the results from batch processing in a menu.
 *
 * @param linhas The number of rows in the terminal.
 * @param colunas The number of columns in the terminal.
 */
void result_menu(int linhas, int colunas);

/**
 * @brief Main interactive menu to guide the user through the application.
 */
void menu();

#endif