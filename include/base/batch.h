#ifndef BATCH_H
#define BATCH_H

#include <stdio.h>
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

int batch(char *argv1, char *argv2);

#endif