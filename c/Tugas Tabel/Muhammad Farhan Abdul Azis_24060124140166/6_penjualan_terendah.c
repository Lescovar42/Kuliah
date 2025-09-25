/*Nama File    : 6_penjualan_terendah.c*/
/*Deskripsi    : Menampilkan penjualan terendah beserta kota dan bulannya*/
/*Pembuat      : 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 19 Mei 2025*/

#include <stdio.h> /*header file*/

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

    int min_penjualan = penjualan[0][0];
    int kota_min = 0;
    int bulan_min = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (penjualan[i][j] < min_penjualan) {
                min_penjualan = penjualan[i][j];
                kota_min = i;
                bulan_min = j;
            }
        }
    }

    printf("Penjualan terendah:\n");
    printf("Kota : %s\n", kota[kota_min]);
    printf("Bulan: %s\n", bulan[bulan_min]);
    printf("Nilai: %d\n", min_penjualan);

    return 0;
}