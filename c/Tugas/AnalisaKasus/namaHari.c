/*Nama File 	: namaBulan.c*/
/*Deskripsi 	: Menampilkan nama hari berdasarkan nomor hari yang diinput dari keyboard*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 8-03-2025/16:00*/

/*Header file*/
#include <stdio.h>

/*Program Utama*/
int main() {
    /*Kamus*/
    int n;

    /*Algoritma*/
    printf("Masukkan nomor hari (1-7): ");
    scanf("%d", &n);

    if (n < 1 || n > 7) {
        printf("Masukan nomor hari tidak tepat\n");
    } else {
        switch (n) {
            case 1: printf("Senin\n"); break;
            case 2: printf("Selasa\n"); break;
            case 3: printf("Rabu\n"); break;
            case 4: printf("Kamis\n"); break;
            case 5: printf("Jumat\n"); break;
            case 6: printf("Sabtu\n"); break;
            case 7: printf("Minggu\n"); break;
        }
    }

    return 0;
}
