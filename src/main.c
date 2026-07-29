// Include header files
#include <stdio.h>
#include "../include/parser.h"
#include "../include/stats.h"

// Main function
int main(void){
    // Declare an array of students
    Student students[MAX_STUDENTS];

    // Fill the array
    int count = parser_csv("data/students.csv", students, MAX_STUDENTS);

    // Validate count
    if (count < 0){
        printf("Error. Data not parsed.");
        
        // Return 
        return 1;
    }

    // Print results
    printf("\n=== Summary Statistics ===\n");
    printf("Total Students: %d\n", count);
    printf("Mean score: %f\n", compute_mean(students, count));
    printf("Maximum score: %f\n", compute_max(students, count));
    printf("Minimum score: %f\n", compute_min(students, count));
    printf("Standand deviation: %f\n", compute_stddev(students, count));

    // Return
    return 0;
}