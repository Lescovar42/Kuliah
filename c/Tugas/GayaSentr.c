/*Nama File 	: GayaSentr.c*/
/*Deskripsi 	: Menghitung gaya sentripetal benda*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 1-03-2025/21:00*/

#include <stdio.h> /*header file*/
/*Program Utama*/
int main() {
    /*Kamus*/
    float m, v, r, F;

    /*Algoritma*/
    printf("Masukkan massa (m) dalam kg: ");
    scanf("%f", &m);

    printf("Masukkan kecepatan (v) dalam m/s: ");
    scanf("%f", &v);

    printf("Masukkan jari-jari (r) dalam meter: ");
    scanf("%f", &r);

    F = m * (v * v / r);

    printf("Gaya sentripetal yang terjadi adalah: %.2f Newton\n", F);

    return 0;
}