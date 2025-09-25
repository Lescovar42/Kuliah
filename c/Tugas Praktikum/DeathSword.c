#include <stdio.h>

int main() {
    /* Kamus */
    int N, i;
    int H[101];         // Batas maksimum 100 ksatria
    long long sum = 0;  // Gunakan long long agar aman jika H_i besar
    double avg;
    int count = 0;

    /* Algoritma */
    printf("Masukkan jumlah ksatria (1 <= N <= 100): ");
    scanf("%d", &N);

    // Validasi sederhana jika diperlukan
    if (N < 1 || N > 100) {
        printf("Nilai N tidak valid!\n");
        return 0;
    }

    printf("Masukkan nilai kebijaksanaan setiap ksatria:\n");
    for (i = 0; i < N; i++) {
        scanf("%d", &H[i]);
        sum += H[i];
    }

    // Hitung rata-rata
    avg = (double) sum / N;

    // Hitung berapa banyak yang >= avg
    for (i = 0; i < N; i++) {
        if (H[i] >= avg) {
            count++;
        }
    }

    // Tampilkan hasil
    printf("Jumlah ksatria dengan kebijaksanaan >= rata-rata: %d\n", count);

    return 0;
}