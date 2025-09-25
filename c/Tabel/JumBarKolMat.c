/*Nama File    : JumBarKolMat.c*/
/*Deskripsi    : Mengisi matriks dengan nilai berdasarkan posisi terhadap diagonal utama*/
/*Pembuat   	: 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 20 April 2025 12.00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{
    /*Kamus*/
    int n, i, j; // Ukuran matriks dan indeks

    /*Algoritma*/
    printf("Masukkan ukuran matriks (n x n): ");
    scanf("%d", &n);
    int M[n][n];

    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                {
                    M[i][j] = 1; // Diagonal utama
                }
                else if (j > i)
                {
                    M[i][j] = 0; // Atas diagonal
                }
                else
                {
                    M[i][j] = 2; // Bawah diagonal
                }
            }
        }

        // Cetak hasil
        printf("Matriks hasil pengisian:\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", M[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Ukuran matriks harus lebih dari 0 dan berbentuk persegi.\n");
    }

    return 0;
}
