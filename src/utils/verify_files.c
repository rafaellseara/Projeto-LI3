#include "utils/verify_files.h"

#define MAX_LINE_LENGTH 2048

int compareFiles(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
    int lineNum = 1;

    if ((fp1 = fopen(file1, "r")) == NULL || (fp2 = fopen(file2, "r")) == NULL) {
        perror("Error opening files");
        return -1;
    }

    while (fgets(line1, MAX_LINE_LENGTH, fp1) != NULL && fgets(line2, MAX_LINE_LENGTH, fp2) != NULL) {
        if (strcmp(line1, line2) != 0) {
            fclose(fp1);
            fclose(fp2);
            return lineNum;
        }
        lineNum++;
    }

    fclose(fp1);
    fclose(fp2);

    if (fgets(line1, MAX_LINE_LENGTH, fp1) != NULL || fgets(line2, MAX_LINE_LENGTH, fp2) != NULL) {
        return lineNum;
    }

    return 0;
}