/*Nama File 	: LuasKellLayang.c*/
/*Deskripsi 	: Menghitung total biaya pengiriman*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 2-03-2025/21:00*/
#include <stdio.h>/*header file*/
/*Program Utama*/
int main() {
    /*Kamus*/
    int berat, jarak;
    int biayaDasar = 10000;
    int biayaPerKg = 5000;
    int biayaPerKm = 2000;
    int totalBiaya;
    
    /*Algoritma*/
    printf("Masukkan berat barang (kg): ");
    scanf("%d", &berat);

    printf("Masukkan jarak pengiriman (km): ");
    scanf("%d", &jarak);

    totalBiaya = biayaDasar + (berat * biayaPerKg) + (jarak * biayaPerKm);

    printf("Total biaya pengiriman adalah: Rp%d\n", totalBiaya);

    return 0;
}
