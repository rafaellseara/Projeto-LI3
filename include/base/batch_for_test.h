#ifndef BATCH_FOR_TEST_H
#define BATCH_FOR_TEST_H

#include "catalogs/catalog_flights.h"
#include "catalogs/catalog_reservations.h"
#include "catalogs/catalog_users.h"
#include "catalogs/catalog_hotels.h"
#include "parser/parser.h"
#include "queries/query1.h"
#include "queries/query1f.h"
#include "queries/query8.h"
#include "queries/query8f.h"
#include "queries/query4.h"
#include "queries/query4f.h"
#include "queries/query3.h"
#include "queries/query3f.h"
#include "queries/query9.h"
#include "queries/query9f.h"
#include "queries/query2.h"
#include "queries/query2f.h"
#include "queries/query5.h"
#include "queries/query5f.h"
#include "queries/query6.h"
#include "queries/query6f.h"
#include "utils/verify_files.h"

#include <stdio.h>
#include <time.h>
#include <sys/resource.h>
#include <glib.h>

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/**
 * @brief Execute a batch of queries for testing and compare the results with expected outputs.
 *
 * This function performs a batch of queries based on input from a file and compares the output with expected results.
 *
 * @param argv1 The path to the directory containing input data files.
 * @param argv2 The path to the file containing query inputs.
 * @param argv3 The path to the directory containing expected output files for testing.
 * @return int - Returns 0 on success, 1 on file opening error, and other values for specific errors during execution.
 */
int batch_for_test(char *argv1, char *argv2, char *argv3);

#endif