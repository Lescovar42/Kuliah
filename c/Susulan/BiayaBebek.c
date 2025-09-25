/* Nama File    : BiayaBebek.c */
/* Deskripsi    : Menghitung dan mencetak biaya pemeliharaan bebek jantan dan betina */
/* Pembuat      : 24060124140166 - Muhammad Farhan Abdul Azis */

#include <stdio.h> /* header file */
int jantan[4] = {0, 10, 50, 60};
int betina[4] = {7, 80, 9, 40};

/* Subprogram */
void priceCounter(int tot_bebek, int* hasil) {
    int harga_bebek;

    if (tot_bebek < 10) {
        harga_bebek = 100000;
    } else if (tot_bebek <= 50) {
        harga_bebek = 75000;
    } else {
        harga_bebek = 50000;
    }

    *hasil = harga_bebek * tot_bebek;
}
/* Subprogram */
void dailyPrice() {
    int tot_jantan, tot_betina, total;

    for (int hari = 0; hari < 4; hari++) {
        priceCounter(jantan[hari], &tot_jantan);
        priceCounter(betina[hari], &tot_betina);
        total = tot_jantan + tot_betina;

        printf("%d\n", total);
    }
}

/* Program utama */
int main() {
    dailyPrice();
    return 0;
}
