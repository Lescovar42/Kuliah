/* Nama File    : KsatriaRaja.c */
/* Deskripsi    : Menentukan jumlah ksatria dengan nilai kebijaksanaan >= rata-rata */
/* Pembuat      : 24060124140166 - Muhammad Farhan Abdul Azis */

#include <stdio.h> /*header file*/

int main() {
    /* Kamus */
    int N, i, sum = 0, count = 0;
    double avg;

    /* Algoritma */
    scanf("%d", &N);
    int H[N];

    for (i = 0; i < N; i++) {
        scanf("%d", &H[i]);
        sum += H[i];
    }

    avg = (double)sum / N;

    for (i = 0; i < N; i++) {
        if (H[i] >= avg) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
