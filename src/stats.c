// Statistical analysis
// Include
#include <stdio.h>
#include <math.h>
#include "../include/stats.h"

// Compute mean
double compute_mean(Student students[], int count){
    // Total score instantiation
    double total_score = 0.0;

    // Loop
    for (int i = 0; i < count; i++){
        total_score += students[i].score;
    }

    // Return computed mean
    return total_score/(double) count;
}

// Compute maximum score
double compute_max(Student students[], int count){
    // Score at index 0
    double max_score = students[0].score;

    // Loop
    for (int i = 1; i < count; i++){
        if(students[i].score > max_score){
            // Update
            max_score = students[i].score;
        }
    }

    // Return maximum
    return max_score;
}

// Compute minimum score
double compute_min(Student students[], int count){
    // Minimum score instantiation
    double min_score = students[0].score;

    // Loop 
    for (int i = 1; i < count; i++){
        if(students[i].score < min_score){
            // Update
            min_score = students[i].score;
        }
    }

    // Return minimum score
    return min_score;
}

// Compute standard deviation
double compute_stddev(Student students[], int count){
    // Step 1: Get the mean
    double mean = compute_mean(students, count);

    // Step 2: Compute difference of squares
    double diff_sqrs = 0.0;

    // Loop
    for (int i = 0; i < count; i++){
        // One individual score
        double single_score = students[i].score;

        // Single difference of square 
        double diff_sqr = (single_score - mean) * (single_score - mean); 

        // Update
        diff_sqrs += diff_sqr;
    }
    
    // Step 3: Compute variance
    double var = diff_sqrs / (double) count;

    // Step 4: Return the standard deviation
    return sqrt(var);

}