#include <stdio.h>
#include <math.h>
#include "./quadratic_solver.h"

// İkinci derece denklemi çöz
void solve_quadratic(float a, float b, float c, char *result) {
    if (a == 0) {
        sprintf(result, "Hata: a sıfır olamaz!");
        return;
    }

    float delta = b * b - 4 * a * c;
    if (delta > 0) {
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        sprintf(result, "x1: %.3f, x2: %.3f", x1, x2);
    } else if (delta == 0) {
        float x = -b / (2 * a);
        sprintf(result, "Çift kök: x1 = x2 = %.3f", x);
    } else {
        sprintf(result, "Gerçek kök yok.");
    }
}

