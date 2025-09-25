/*Nama File 	: kalkSS.c*/
/*Deskripsi 	: Kalkulator sederhana yang melakukan operasi aritmatika sesuai pilihan pengguna*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 28-02-2025/19:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
      /*Kamus*/
    float v0, t, a, S;

    /*Algoritma*/
    printf("Masukkan kecepatan awal (v0) dalam m/s: ");
    scanf("%f", &v0);

    printf("Masukkan waktu (t) dalam detik: ");
    scanf("%f", &t);

    printf("Masukkan percepatan (a) dalam m/s^2: ");
    scanf("%f", &a);

    S = v0 * t + 0.5 * a * t * t;

    printf("Jarak yang ditempuh benda adalah: %.2f meter\n", S);

    return 0;
}
