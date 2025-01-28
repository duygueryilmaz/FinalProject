#include <stdio.h>
#include <stdlib.h>
#include "quadratic_solver.h"

int main() {
    const char *input_file = "input.txt";   // Girdi dosyası
    const char *output_file = "output.txt"; // Çıktı dosyası
    float coefficients[MAX_LINES][3];      // Katsayılar (a, b, c) için matris
    char results[MAX_LINES][MAX_RESULT_LENGTH]; // Çözümler için metin dizisi
    int line_count = 0;                    // Satır sayısı
    char choice;                           // Kullanıcı seçimi

    do {
        // Girdi dosyasını oku
        read_coefficients(input_file, coefficients, &line_count);

        // Denklemleri çöz
        for (int i = 0; i < line_count; i++) {
            char result[MAX_RESULT_LENGTH];
            float a = coefficients[i][0];
            float b = coefficients[i][1];
            float c = coefficients[i][2];
            solve_quadratic(a, b, c, result);
            snprintf(results[i], sizeof(results[i]), "%.1f %.1f %.1f -> %s", a, b, c, result);
        }

        // Sonuçları çıktı dosyasına yaz
        write_results(output_file, results, line_count);

        printf("Sonuçlar %s dosyasına yazıldı.\n", output_file);

        // Kullanıcıya tekrar çalıştırmak isteyip istemediğini sor
        printf("Başka bir dosya işlemek istiyor musunuz? (E/e: Evet, H/h: Hayır): ");
        scanf(" %c", &choice);

    } while (choice == 'E' || choice == 'e');

    printf("Program sonlandırıldı.\n");
    return 0;
}
