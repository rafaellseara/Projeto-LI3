#ifndef VERIFY_FILES_H
#define VERIFY_FILES_H

#include <stdio.h>
#include <string.h>

/**
 * @brief Compare the contents of two files line by line.
 *
 * This function reads and compares the contents of two files line by line.
 *
 * @param file1 The path to the first file.
 * @param file2 The path to the second file.
 * @return int - If the files are identical, returns 0. If files differ, returns the line number where the first difference occurred. If an error occurs, returns -1.
 */
int compareFiles(char *file1, char *file2);

#endif