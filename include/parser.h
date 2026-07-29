// Defining the data structure
#ifndef PARSER_H
#define PARSER_H

// Maximum number of students
#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define FIELDS_PER_ROW 3

// Data structure; representing one row
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    double score;
} Student;

// Function declaration
int parser_csv(const char *filename, Student students [], int max);

#endif