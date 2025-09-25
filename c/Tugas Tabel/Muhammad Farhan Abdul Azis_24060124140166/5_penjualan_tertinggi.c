/*Nama File    : 5_penjualan_tertinggi.c*/
/*Deskripsi    : Menampilkan penjualan tertinggi beserta kota dan bulannya*/
/*Pembuat      : 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 19 Mei 2025*/

#include <stdio.h> /*header file*/
#include <string.h>

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

    int max_penjualan = penjualan[0][0];
    int kota_max = 0;
    int bulan_max = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (penjualan[i][j] > max_penjualan) {
                max_penjualan = penjualan[i][j];
                kota_max = i;
                bulan_max = j;
            }
        }
    }

    printf("Penjualan tertinggi:\n");
    printf("Kota : %s\n", kota[kota_max]);
    printf("Bulan: %s\n", bulan[bulan_max]);
    printf("Nilai: %d\n", max_penjualan);

    return 0;
}