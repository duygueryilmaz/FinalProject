#ifndef QUADRATIC_SOLVER_H
#define QUADRATIC_SOLVER_H

// Maksimum satır ve sonuç uzunluğu
#define MAX_LINES 100
#define MAX_RESULT_LENGTH 100

// Fonksiyon Prototipleri
void read_coefficients(const char *input_file, float coefficients[][3], int *line_count);
void solve_quadratic(float a, float b, float c, char *result);
void write_results(const char *output_file, char results[][MAX_RESULT_LENGTH], int line_count);

#endif // QUADRATIC_SOLVER_H
