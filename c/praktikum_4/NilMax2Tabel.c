/*Nama File 	: NilMax2Tabel.c*/
/*Deskripsi 	: Menampilkan bilangan terbesar kedua dalam sebuah tabel*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 06.00*/

#include <stdio.h> /*header file*/

// Program utama
int main()
{
    // Kamus
    int i;          // Indeks untuk iterasi
    int elmt;       // Elemen yang akan dimasukkan
    int max1, max2; // Nilai maksimum pertama dan kedua
    int n;          // Ukuran tabel
    printf("Masukkan banyaknya elemen: ");
    scanf("%d", &n);
    int T[n]; // Tabel untuk menyimpan elemen

    // Algoritma
    printf("Masukkan elemen-elemen tabel: ");
    i = 0;
    while (i < n)
    {
        scanf("%d", &elmt);
        if (elmt < 0)
        {
            printf("Nilai tidak boleh negatif\n");
        }
        else
        {
            T[i] = elmt;
            i++;
        }
    }

    max1 = 0;
    max2 = 0;

    for (i = 0; i < n; i++)
    {
        if (T[i] > max1)
        {
            max2 = max1;
            max1 = T[i];
        }
        else
        {
            if (T[i] > max2 && T[i] != max1)
            {
                max2 = T[i];
            }
        }
    }

    printf("Nilai maksimum ke-2 adalah %d", max2);

    return 0;
}