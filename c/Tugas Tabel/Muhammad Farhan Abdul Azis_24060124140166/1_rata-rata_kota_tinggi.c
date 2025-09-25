/*Nama File    : 1_rata-rata_kota_tinggi.c*/
/*Deskripsi    : Menampilkan rata-rata penjualan tiap kota dan kota dengan rata-rata penjualan tertinggi*/
/*Pembuat      : 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 18 Mei 2025*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
    /*Kamus*/
    int penjualan[3][4] = {
        {10, 15, 10, 5},  // Semarang
        {20, 25, 20, 15}, // Jakarta
        {10, 5, 14, 3}    // Yogyakarta
    };

    char kota[3][20] = {"Semarang", "Jakarta", "Yogyakarta"};
    char bulan[4][10] = {"Jan", "Feb", "Mar", "Apr"};

    float rata_rata_tertinggi = 0.0;
    int kota_rata_rata_tertinggi_idx = 0;

    /*Algoritma*/
    for (int i = 0; i < 3; i++) {
        int total_penjualan_kota = 0;
        for (int j = 0; j < 4; j++) {
            total_penjualan_kota += penjualan[i][j];
        }

        float rata_rata_kota = (float)total_penjualan_kota / 4.0;

        printf("Rata-rata penjualan %s: %.2f\n", kota[i], rata_rata_kota);

        if (i == 0) {
            rata_rata_tertinggi = rata_rata_kota;
            kota_rata_rata_tertinggi_idx = i;
        } else {
            if (rata_rata_kota > rata_rata_tertinggi) {
                rata_rata_tertinggi = rata_rata_kota;
                kota_rata_rata_tertinggi_idx = i;
            }
        }
    }

    printf("\nKota dengan rata-rata penjualan tertinggi:\n");
    printf("Kota : %s\n", kota[kota_rata_rata_tertinggi_idx]);
    printf("Rata-rata Penjualan: %.2f\n", rata_rata_tertinggi);

    return 0;
}