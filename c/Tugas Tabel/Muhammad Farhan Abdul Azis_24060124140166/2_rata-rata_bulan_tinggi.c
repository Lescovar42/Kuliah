/*Nama File    : 2_rata-rata_bulan_tinggi.c*/
/*Deskripsi    : Menampilkan rata-rata penjualan tiap bulan dan bulan dengan rata-rata penjualan tertinggi*/
/*Pembuat      : 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 18 Mei 2025*/

#include <stdio.h>/*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int penjualan[3][4] = {
        {10, 15, 10, 5},  // Semarang
        {20, 25, 20, 15}, // Jakarta
        {10, 5, 14, 3}    // Yogyakarta
    };

    char kota[3][20] = {"Semarang", "Jakarta", "Yogyakarta"};
    char bulan[4][10] = {"Jan", "Feb", "Mar", "Apr"};

    float rata_rata_tertinggi = 0.0;
    int bulan_rata_rata_tertinggi_idx = 0;

    /*Algoritma*/
    for (int j = 0; j < 4; j++) {
        int total_penjualan_bulan = 0;
        for (int i = 0; i < 3; i++) {
            total_penjualan_bulan += penjualan[i][j];
        }

        float rata_rata_bulan = (float)total_penjualan_bulan / 3.0;

        printf("Rata-rata penjualan bulan %s: %.2f\n", bulan[j], rata_rata_bulan);

        if (j == 0) {
            rata_rata_tertinggi = rata_rata_bulan;
            bulan_rata_rata_tertinggi_idx = j;
        } else {
            if (rata_rata_bulan > rata_rata_tertinggi) {
                rata_rata_tertinggi = rata_rata_bulan;
                bulan_rata_rata_tertinggi_idx = j;
            }
        }
    }

    printf("\nBulan dengan rata-rata penjualan tertinggi:\n");
    printf("Bulan : %s\n", bulan[bulan_rata_rata_tertinggi_idx]);
    printf("Rata-rata Penjualan: %.2f\n", rata_rata_tertinggi);

    return 0;
}