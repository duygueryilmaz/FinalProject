#include <stdio.h>
#include <stdlib.h>
#include "quadratic_solver.h"

// Girdi dosyasını oku
void read_coefficients(const char *input_file, float coefficients[][3], int *line_count) {
    FILE *file = fopen(input_file, "r");
    if (file == NULL) {
        printf("Girdi dosyası açılamadı: %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    *line_count = 0;
    while (fscanf(file, "%f %f %f", &coefficients[*line_count][0], 
                  &coefficients[*line_count][1], 
                  &coefficients[*line_count][2]) == 3) {
        (*line_count)++;
    }

    fclose(file);
}

// Sonuçları çıktı dosyasına yaz
void write_results(const char *output_file, char results[][MAX_RESULT_LENGTH], int line_count) {
    FILE *file = fopen(output_file, "w");
    if (file == NULL) {
        printf("Çıktı dosyası açılamadı: %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < line_count; i++) {
        fprintf(file, "%s\n", results[i]);
    }

    fclose(file);
}
