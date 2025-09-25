/*Nama File    : IsiMatriks.c*/
/*Deskripsi    : Mengisi elemen matriks berdasarkan posisi relatif terhadap diagonal utama*/
/*Pembuat      : 24060124130069-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan: 21 April 2025 11:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{
    /*Kamus*/
    int baris, kolom;   // Ukuran matriks
    int i, j;           // Indeks iterasi
    printf("Masukkan jumlah baris dan kolom (harus sama): ");
    scanf("%d %d", &baris, &kolom);
    int matriks[baris][kolom];

    /*Algoritma*/
    if (baris > 0 && kolom > 0 && baris == kolom)
    {
        for (i = 0; i < baris; i++)
        {
            for (j = 0; j < kolom; j++)
            {
                if (i == j)
                {
                    matriks[i][j] = 1; // Diagonal utama
                }
                else if (i < j)
                {
                    matriks[i][j] = 0; // Di atas diagonal
                }
                else
                {
                    matriks[i][j] = 2; // Di bawah diagonal
                }
            }
        }

        // Output hasil matriks
        printf("Isi matriks:\n");
        for (i = 0; i < baris; i++)
        {
            for (j = 0; j < kolom; j++)
            {
                printf("%d ", matriks[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Baris dan kolom harus lebih dari 0 dan nilainya sama.\n");
    }

    return 0;
}