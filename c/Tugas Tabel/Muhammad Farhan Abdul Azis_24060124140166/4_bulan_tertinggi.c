/*Nama File    : 4_bulan_tertinggi.c*/
/*Deskripsi    : Menampilkan bulan dengan penjualan tertinggi pada kota tertentu*/
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
    char nama_bulan[4][10] = {"Jan", "Feb", "Mar", "Apr"};
    int kota_x;
    int penjualan_tertinggi_kota_x = -1;
    char bulan_penjualan_tertinggi[10];
    int j;

    printf("Masukkan kota (0=Semarang, 1=Jakarta, 2=Yogyakarta): ");
    scanf("%d", &kota_x);

    if (kota_x < 0 || kota_x > 2) {
        printf("Input kota tidak valid.\n");
        return 1;
    }

    for (j = 0; j < 4; j++) {
        if (penjualan[kota_x][j] > penjualan_tertinggi_kota_x) {
            penjualan_tertinggi_kota_x = penjualan[kota_x][j];
            int k = 0;
            while(nama_bulan[j][k] != '\0'){
                bulan_penjualan_tertinggi[k] = nama_bulan[j][k];
                k++;
            }
            bulan_penjualan_tertinggi[k] = '\0';
        }
    }

    printf("Penjualan tertinggi di kota %s adalah pada bulan %s (%d)\n",
           kota[kota_x], bulan_penjualan_tertinggi, penjualan_tertinggi_kota_x);

    return 0;
}