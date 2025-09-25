/* Nama File    : Pegunungan.c */
/* Deskripsi    : Menggambar pola pegunungan dengan bintang menggunakan rekursi */
/* Pembuat      : 24060124140166 - Muhammad Farhan Abdul Azis */

#include <stdio.h> /* header file */

/* Subprogram */
void paintPegunungan(int N) {
    if (N == 1) {
        printf("*\n");
        return;
    }

    paintPegunungan(N - 1);
    for (int i = 0; i < N; i++) {
        printf("*");
    }
    printf("\n");
    paintPegunungan(N - 1);
}

/* Program utama */
int main() {
    int N;
    scanf("%d", &N); 
    paintPegunungan(N);

    return 0;
}