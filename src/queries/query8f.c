#include "queries/query8f.h"
#include "queries/query8.h"

void query8F(RESERVATIONS_CATALOG res_catalog, char *parametros, int linha)
{
       char caminho[70];
       char str[10];
       char *id, *dataInicial, *dataFinal;
       id = strsep(&parametros, " ");
       dataInicial = strsep(&parametros, " ");
       dataFinal = strsep(&parametros, " ");
       int receita = 0;

       sprintf(str, "%d", linha);
       strcpy(caminho, "Resultados/command");
       strcat(caminho, str);
       strcat(caminho, "_output.txt");

       FILE *file = fopen(caminho, "w");

       information_query8(res_catalog, parametros, id, dataInicial, dataFinal, &receita); // n tenho de passar como argumento??? id, dataInicial, dataFinal

       fprintf(file, "--- 1 ---\n");
       fprintf(file, "revenue: %d\n", receita);

       fclose(file);
}
