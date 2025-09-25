/*Nama File    : 3_kota_tertinggi.c*/
/*Deskripsi    : Menampilkan kota dengan penjualan tertinggi pada bulan tertentu*/
/*Pembuat      : 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 18 Mei 2025*/

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
    char nama_bulan[4][10] = {"Jan", "Feb", "Mar", "Apr"};
    int bulan_x;
    int penjualan_tertinggi_bulan_x = -1;
    char kota_penjualan_tertinggi[20];
    int i;

    printf("Masukkan bulan (0=Januari, 1=Februari, 2=Maret, 3=April): ");
    scanf("%d", &bulan_x);

    if (bulan_x < 0 || bulan_x > 3) {
        printf("Input bulan tidak valid.\n");
        return 1;
    }

    for (i = 0; i < 3; i++) {
        if (penjualan[i][bulan_x] > penjualan_tertinggi_bulan_x) {
            penjualan_tertinggi_bulan_x = penjualan[i][bulan_x];
            int k = 0;
            while(kota[i][k] != '\0'){
                kota_penjualan_tertinggi[k] = kota[i][k];
                k++;
            }
            kota_penjualan_tertinggi[k] = '\0';
        }
    }

    printf("Penjualan tertinggi pada bulan %s adalah di kota %s (%d)\n",
           nama_bulan[bulan_x], kota_penjualan_tertinggi, penjualan_tertinggi_bulan_x);

    return 0;
}