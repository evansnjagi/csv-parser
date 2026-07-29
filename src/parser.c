// Include
#include <stdio.h>
#include <stdlib.h>
#include "../include/parser.h"

// Function
int parser_csv(const char *filename, Student students[], int max){
    // Step 1: Open csv file
    FILE *fp = fopen(filename, "r"); 

    // Step 2: Check if opened
    if (fp == NULL){
        printf("Error. could not open file %s\n", filename);
        return -1;
    }

    // Step 3: Read
    // Step 3.1: Skip the header line
    char header[100];
    fgets(header, sizeof(header), fp);

    // Step 3.2: Read each row
    int count = 0;
    while(count < max && 
        fscanf(fp, 
            "%49[^,], %d, %lf\n",
            students[count].name,
            &students[count].age,
            &students[count].score) == FIELDS_PER_ROW){
        // Increament count
        count ++;
    }

    // Step 4: close file
    fclose(fp);

    // Return 
    return count;
} 