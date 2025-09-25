/* Nama File    : JamuanMakan.c */
/* Deskripsi    : Menghitung total cokelat yang diterima oleh setiap bangsawan bebek */
/* Pembuat      : 24060124140166 - Muhammad Farhan Abdul Azis */

#include <stdio.h>

int main() {
    int N, i, j;

    scanf("%d", &N);
    int D[N][N], G[N][N], total[N][N];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &D[i][j]);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            total[i][j] = D[i][j] + G[i][j];
            printf("%d ", total[i][j]);
        }
        printf("\n");
    }

    return 0;
}
