/*Nama File 	: volBolaKerct.c*/
/*Deskripsi 	: Menghitung volume bola dan kerucut Vb dan Vk*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 1-03-2025/22:00*/
#include <stdio.h> /*header file*/

int main() {
    /*Kamus*/
    float r, Vb, Vk;
    const float PHI = 3.1415;

    /*Algoritma*/
    printf("Masukkan jari-jari lingkaran (r) dalam meter: ");
    scanf("%f", &r);

    Vb = (PHI * r * r * r) * (4.0 / 3.0);
    Vk = 0.5 * Vb;

    printf("Volume bola adalah: %.2f meter kubik\n", Vb);
    printf("Volume kerucut adalah: %.2f meter kubik\n", Vk);

    return 0;
}
