#include "base/interactive.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_ENTRIES 100

char *get_directory_parent(const char *path)
{
    char *parent = strdup(path);
    char *last_slash = strrchr(parent, '/');
    if (last_slash != NULL)
    {
        *last_slash = '\0';
        return parent;
    }
    else
    {
        free(parent);
        return NULL;
    }
}

char **get_directory_contents(const char *path, int *num_entries)
{
    DIR *dir = opendir(path);
    if (!dir)
    {
        perror("Error opening directory");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;
    char **contents = (char **)malloc(MAX_ENTRIES * sizeof(char *));
    *num_entries = 0;

    while ((entry = readdir(dir)) != NULL && *num_entries < MAX_ENTRIES)
    {
        contents[*num_entries] = strdup(entry->d_name);
        (*num_entries)++;
    }

    closedir(dir);
    return contents;
}

void print_menu(WINDOW *menu_win, char **contents, int highlight, int num_entries)
{
    int x, y;
    getmaxyx(menu_win, y, x);
    wclear(menu_win);
    box(menu_win, 0, 0);
    mvwprintw(menu_win, 2, y / 2 - 14, "Choose a directory(navigate with the arrow keys)");

    for (int i = 0; i < num_entries; i++)
    {
        if (i == highlight)
        {
            wattron(menu_win, A_REVERSE);
        }
        mvwprintw(menu_win, y / 2 - num_entries / 2 + i - 5, x / 2 - strlen(contents[i]) / 2, "%s", contents[i]);
        wattroff(menu_win, A_REVERSE);
    }

    wrefresh(menu_win);
}

char *choose_path_menu(const char *current_path, int linhas, int colunas)
{
    char selected_string[200] = "";
    keypad(stdscr, true);

    int num_entries;
    char **contents = get_directory_contents(current_path, &num_entries);

    int choice;
    int highlight = 0;

    int start_y = linhas / 2 - 30, start_x = colunas / 2 - 40;
    WINDOW *menu_win = newwin(60, 80, start_y, start_x);
    box(menu_win, 0, 0);
    refresh();
    wrefresh(menu_win);

    print_menu(menu_win, contents, highlight, num_entries);

    while (1)
    {
        choice = getch();
        switch (choice)
        {
        case KEY_UP:
            highlight = (highlight - 1 + num_entries) % num_entries;
            break;
        case KEY_DOWN:
            highlight = (highlight + 1) % num_entries;
            break;
        case KEY_LEFT:
            if (strcmp(current_path, "/") != 0)
            {
                current_path = get_directory_parent(current_path);
                contents = get_directory_contents(current_path, &num_entries);
                highlight = 0;
            }
            break;
        case KEY_RIGHT:
            if (contents[highlight][0] != '.' && contents[highlight][0] != '\0')
            {
                char *new_path = malloc(strlen(current_path) + strlen(contents[highlight]) + 2);
                sprintf(new_path, "%s/%s", current_path, contents[highlight]);

                struct stat path_stat;
                if (stat(new_path, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
                {
                    current_path = new_path;
                    contents = get_directory_contents(current_path, &num_entries);
                    highlight = 0;
                }
                else
                {
                    free(new_path);
                }
            }
            break;
        case 10:
            strncpy(selected_string, contents[highlight], 200 - 1);
            selected_string[200 - 1] = '\0';
            break;
        }

        if (choice == 10)
        {
            free(contents);
            break;
        }
        print_menu(menu_win, contents, highlight, num_entries);
    }

    clear();
    refresh();
    
    return strdup(selected_string);
}

int choose_query_menu(int linhas, int colunas)
{
    const char option1[20] = "    QUERY 1    ";
    const char option2[20] = "    QUERY 2    ";
    const char option3[20] = "    QUERY 3    ";
    const char option4[20] = "    QUERY 4    ";
    const char option5[20] = "    QUERY 5    ";
    const char option6[20] = "    QUERY 6    ";
    const char option7[20] = "    QUERY 7    ";
    const char option8[20] = "    QUERY 8    ";
    const char option9[20] = "    QUERY 9    ";

    int choice = 1;
    int selected;
    int highlight = 0;
    int loop = 1;

    int start_y = linhas / 2 - 30, start_x = colunas / 2 - 40;
    WINDOW *win = newwin(60, 80, start_y, start_x);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    while (loop == 1)
    {
        box(win, 0, 0);
        for (int i = 0; i < 9; i++)
        {
            if (i == highlight)
                wattron(win, A_REVERSE);

            switch (i)
            {
            case 0:
                mvwprintw(win, 16 + i, 32, option1);
                break;
            case 1:
                mvwprintw(win, 18 + i, 32, option2);
                break;
            case 2:
                mvwprintw(win, 20 + i, 32, option3);
                break;
            case 3:
                mvwprintw(win, 22 + i, 32, option4);
                break;
            case 4:
                mvwprintw(win, 24 + i, 32, option5);
                break;
            case 5:
                mvwprintw(win, 26 + i, 32, option6);
                break;
            case 6:
                mvwprintw(win, 28 + i, 32, option7);
                break;
            case 7:
                mvwprintw(win, 30 + i, 32, option8);
                break;
            case 8:
                mvwprintw(win, 32 + i, 32, option9);
                break;
            }
            wattroff(win, A_REVERSE);
        }
        wrefresh(win);
        selected = getch();

        switch (selected)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 9)
                highlight = 8;
            break;
        }

        if (selected == 10)
        {
            switch (highlight)
            {
            case 0:
                loop = 0;
                break;
            case 1:
                choice = 2;
                loop = 0;
                break;
            case 2:
                choice = 3;
                loop = 0;
                break;
            case 3:
                choice = 4;
                loop = 0;
                break;
            case 4:
                choice = 5;
                loop = 0;
                break;
            case 5:
                choice = 6;
                loop = 0;
                break;
            case 6:
                choice = 7;
                loop = 0;
                break;
            case 7:
                choice = 8;
                loop = 0;
                break;
            case 8:
                choice = 9;
                loop = 0;
                break;
            }
        }
    }
    clear();
    refresh();
    return choice;
}

char *choose_input_menu(int linhas, int colunas)
{
    noecho();
    int start_y = linhas / 2 - 20, start_x = colunas / 2 - 40;
    WINDOW *win_final = newwin(40, 80, start_y, start_x);
    box(win_final, 0, 0);

    char nome[58] = {0};
    nome[0] = ' ';

    mvwprintw(win_final, 16, 28, "PLEASE WRITE YOUR INPUT:");
    wrefresh(win_final);

    WINDOW *win_nome = newwin(3, 60, start_y + 20, start_x + 10);
    box(win_nome, 0, 0);
    move(start_y + 26, start_x + 12);
    wrefresh(win_nome);

    for (int i = 0; i < 58;)
    {
        char selected = getch();
        if ((selected == 10) && (nome[0] != ' '))
        {
            break;
        }
        else if (i < 57 && isprint(selected))
        {
            nome[i] = selected;
            mvwprintw(win_nome, 1, i + 1, "%c", selected);
            wrefresh(win_nome);
            i++;
        }
        else if ((selected == 127) && (i > 0))
        {
            i--;
            nome[i] = ' ';
            mvwaddch(win_nome, 1, i + 1, ' ');
            wmove(win_nome, 1, i + 1);
            wrefresh(win_nome);
        }
    }

    clear();
    refresh();
    return strdup(nome);
}

void batch_for_interactive(char *path, int query, char *input)
{
    FLIGHTS_CATALOG flights_catalog = create_flight_catalog();
    RESERVATIONS_CATALOG reservations_catalog = create_reservation_catalog();
    USERS_CATALOG users_catalog = create_users_catalog();
    HOTELS_CATALOG hotels_catalog = create_hotel_catalog();

    char file_location_users[100];
    strcpy(file_location_users, path);
    strcat(file_location_users, "/users.csv");

    char file_location_reservations[100];
    strcpy(file_location_reservations, path);
    strcat(file_location_reservations, "/reservations.csv");

    char file_location_flights[100];
    strcpy(file_location_flights, path);
    strcat(file_location_flights, "/flights.csv");

    char file_location_passengers[100];
    strcpy(file_location_passengers, path);
    strcat(file_location_passengers, "/passengers.csv");

    parse_file_users(file_location_users, users_catalog);
    parse_file_reservations(file_location_reservations, reservations_catalog, users_catalog, hotels_catalog);
    parse_file_flights(file_location_flights, flights_catalog);
    parse_file_passengers(file_location_passengers, flights_catalog, users_catalog);

    char outputFileLocation[50] = "Resultados/interactive_result.txt";

    if (query == 1){
        query1(input, reservations_catalog, users_catalog, flights_catalog, outputFileLocation);
    }
    else if (query == 3)
    {
        query3(input, hotels_catalog, outputFileLocation);
    }
    else if (query == 4)
    {
        query4(input, reservations_catalog, outputFileLocation);
    }
    else if (query == 5)
    {
        query5(flights_catalog, input, outputFileLocation);
    }
    else if (query == 6){
        execute_query6(flights_catalog, input, outputFileLocation);
    }
    else if (query == 8)
    {
        //query8(reservations_catalog, args_for_query, acc);
    }
    else if (query == 9)
    {
        query9(users_catalog, input, outputFileLocation);
    }

    free_flights_catalog(flights_catalog);
    free_reservations_catalog(reservations_catalog);
    free_users_catalog(users_catalog);
}

void result_menu(int linhas, int colunas)
{
    FILE *file = fopen("Resultados/interactive_result.txt", "r");
    if (!file)
    {
        perror("Error opening file");
        return;
    }

    noecho();
    cbreak();

    char line[100];
    int row = 0;
    int page = 0;
    int max_pages = 1;

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (row == linhas - 1)
        {
            max_pages++;
            row = 0;
        }
        row++;
    }

    row = 0;
    int check_page = 0;

    rewind(file);

    for (int i = 0; i < linhas - 1; i++)
    {
        if (fgets(line, sizeof(line), file) == NULL)
        {
            break;
        }
        mvprintw(i, 0, "%s", line);
    }
    refresh();

    int key;
    while (1)
    {

        if (((page < max_pages) && (page > 0)) || (check_page != 0))
        {
            clear();
            while (check_page != 0)
            {
                for (int i = 0; i < linhas - 1; i++)
                {
                    if (fgets(line, sizeof(line), file) == NULL)
                    {
                        break;
                    }
                }
                check_page--;
            }

            for (int i = 0; i < linhas - 1; i++)
            {
                if (fgets(line, sizeof(line), file) == NULL)
                {
                    break;
                }
                mvprintw(i, 0, "%s", line);
            }
            if (key == KEY_UP)
                page--;
        }

        if (page > max_pages - 1)
            page--;

        mvprintw(linhas - 1, colunas - 20, "Page %d of %d", page + 1, max_pages);
        refresh();

        key = getch();

        switch (key)
        {
        case KEY_DOWN:
            if (page < max_pages)
            {
                page++;
            }
            break;
        case KEY_UP:
            if (page > 0)
            {
                rewind(file);
                check_page = page - 1;
            }
            break;
        case 10:
            fclose(file);
            return;
        }
    }

    clear();
    refresh();
}

void menu()
{
    int linhas, colunas;

    initscr();

    keypad(stdscr, true);
    noecho();
    curs_set(0);

    char current_path[200];
    if (getcwd(current_path, sizeof(current_path)) == NULL)
    {
        printw("Error getting current working directory\n");
        endwin();
    }

    getmaxyx(stdscr, linhas, colunas);

    int start_y = linhas / 2 - 30, start_x = colunas / 2 - 60;
    WINDOW *win = newwin(60, 120, start_y, start_x);
    box(win, 0, 0);
    refresh();
    wrefresh(win);

    keypad(win, true);

    const char option1[30] = "  DATASET FOLDER PATH!  ";
    const char option2[30] = "          EXIT          ";
    int selected;
    int highlight = 0;
    int loop = 1;

    while (loop == 1)
    {
        box(win, 0, 0);
        for (int i = 0; i < 2; i++)
        {
            if (i == highlight)
                wattron(win, A_REVERSE);

            switch (i)
            {
            case 0:
                mvwprintw(win, 26 + i, 48, option1);
                break;
            case 1:
                mvwprintw(win, 28 + i, 48, option2);
                break;
            }
            wattroff(win, A_REVERSE);
        }
        selected = wgetch(win);

        switch (selected)
        {
        case KEY_UP:
            highlight--;
            if (highlight == -1)
                highlight = 0;
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 2)
                highlight = 1;
            break;
        }

        if (selected == 10)
        {
            switch (highlight)
            {
            case 0:
                clear();
                refresh();

                int check = 0;

                char full_path[200];

                while (!check)
                {
                    char *new_path = choose_path_menu(current_path, linhas, colunas);

                    DIR *dir = opendir(new_path);

                    if (dir)
                    {
                        struct dirent *entry;
                        while ((entry = readdir(dir)) != NULL)
                        {
                            if (strcmp(entry->d_name, "data") == 0)
                            {
                                wclear(win);
                                box(win, 0, 0);
                                mvwprintw(win, 29, 44, "Directory 'data' found in %s", new_path);
                                wrefresh(win);
                                while (getch() != 10)
                                {
                                }
                                wclear(win);
                                wrefresh(win);
                                snprintf(full_path, sizeof(full_path), "%s/%s", new_path, "data");
                                check = 1;
                            }
                        }
                        if (check == 0)
                        {
                            wclear(win);
                            box(win, 0, 0);
                            mvwprintw(win, 29, 40, "Directory 'data' not found in %s", new_path);
                            wrefresh(win);
                            while (getch() != 10)
                            {
                            }
                            wclear(win);
                            wrefresh(win);
                        }

                        closedir(dir);
                    }
                    else
                    {
                        wclear(win);
                        box(win, 0, 0);
                        mvwprintw(win, 29, 42, "Invalid directory: %s", new_path);
                        wrefresh(win);
                        while (getch() != 10)
                        {
                        }
                        wclear(win);
                        wrefresh(win);
                    }

                    free(new_path);
                }

                int query = choose_query_menu(linhas, colunas);
                char *input = choose_input_menu(linhas, colunas);

                wclear(win);
                box(win, 0, 0);
                int len = 32 - (strlen(input) / 2);
                mvwprintw(win, 29, len, "Path to directory %s with query %d and input %s", full_path, query, input);
                wrefresh(win);
                while (getch() != 10)
                {
                }
                wclear(win);
                wrefresh(win);

                box(win, 0, 0);
                mvwprintw(win, 29, 50, "Query running...");
                clear();
                wrefresh(win);

                batch_for_interactive(full_path, query, input);

                result_menu(linhas, colunas);

                clear();
                refresh();

                break;

            case 1:
                loop = 0;
                break;
            }
        }
    }
    clear();
    refresh();
}