/*Nama File    : FrekNiltabel.c*/
/*Deskripsi    : Program untuk menampilkan elemen pada array yang frekuensinya lebih dari satu*/
/*Pembuat      : 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 19 April 2025-16:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
    /*Kamus*/
    int n, i, j, x, jumlah;
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    int data[n];

    /*Algoritma*/
    printf("Masukkan elemen-elemen array: ");
    i = 0;
    while (i < n)
    {
        scanf("%d", &x);
        if (x < 0)
        {
            printf("Angka tidak boleh negatif\n");
        }
        else
        {
            data[i] = x;
            i++;
        }
    }

    printf("Elemen yang frekuensinya lebih dari satu:\n");
    for (i = 0; i < n; i++)
    {
        jumlah = 1;
        for (j = i + 1; j < n; j++)
        {
            if (data[i] == data[j] && data[j] != -1)
            {
                jumlah++;
                data[j] = -1; // Sudah dihitung
            }
        }
        if (jumlah > 1 && data[i] != -1)
        {
            printf("%d muncul sebanyak %d kali\n", data[i], jumlah);
        }
    }

    return 0;
}
