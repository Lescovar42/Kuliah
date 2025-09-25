/*Nama File 	: LuasKellLayang.c*/
/*Deskripsi 	: Menghitung luas layang-layang*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 1-03-2025/23:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    float s1, s2, d1, d2, Luas, Kell;

    /*Algoritma*/
    printf("Masukkan sisi satu (s1) dalam meter: ");
    scanf("%f", &s1);

    printf("Masukkan sisi dua (s2) dalam meter: ");
    scanf("%f", &s2);

    printf("Masukkan diagonal satu (d1) dalam meter: ");
    scanf("%f", &d1);

    printf("Masukkan diagonal dua (d2) dalam meter: ");
    scanf("%f", &d2);

    Luas = 0.5 * d1 * d2;
    
    Kell = 2 * (s1 + s2);

    printf("Luas layang-layang adalah: %.2f meter persegi\n", Luas);
    printf("Keliling layang-layang adalah: %.2f meter\n", Kell);

    return 0;
}
