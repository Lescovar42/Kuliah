/*Nama File 	: JarakPBola.c*/
/*Deskripsi 	: Menghitung jarak benda parabola*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 28-02-2025/19:30*/

#include <stdio.h>

int main() {
    float v0, t, g, y;

    // Input nilai v0, t, dan g
    printf("Masukkan kecepatan awal (v0) dalam m/s: ");
    scanf("%f", &v0);

    printf("Masukkan waktu (t) dalam detik: ");
    scanf("%f", &t);

    printf("Masukkan gravitasi (g) dalam m/s^2: ");
    scanf("%f", &g);

    // Menghitung jarak y menggunakan rumus y = v0 * t - 0.5 * g * t^2
    y = v0 * t - 0.5 * g * t * t;

    // Menampilkan hasil
    printf("Jarak yang ditempuh benda adalah: %.2f meter\n", y);

    return 0;
}