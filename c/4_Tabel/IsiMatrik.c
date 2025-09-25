/*Nama File 	: IsiMatrik.c*/
/*Deskripsi 	: Mengisi nilai matriks yang direpresentasikan oleh tabel*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 07.40*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{
    /*Kamus*/
    int i, j; // Counter
    int m, n; // Ukuran tabel
    printf("Masukkan ukuran tabel (baris kolom): ");
    scanf("%d %d", &m, &n); // Input ukuran tabel
    int T[m][n];            // Tabel 2 dimensi

    // Algoritma
    if (m > 0 && n > 0 && m == n)
    {
        // Input elemen tabel
        i = 0;
        for (i = 0; i < m; i++)
        {
            j = 0;
            for (j = 0; j < n; j++)
            {
                // Elemen diagonal = 1
                if (i == j)
                {
                    T[i][j] = 1;
                }
                // Elemen di atas diagonal = 0
                else if (i < j)
                {
                    T[i][j] = 0;
                }
                // Elemen di bawah diagonal = 2
                else
                {
                    T[i][j] = 2;
                }
            }
        }

        // Menampilkan tabel
        printf("Tabel yang dihasilkan:\n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%d ", T[i][j]); // Menampilkan elemen tabel
            }
            printf("\n");
        }
    }
    else
    {
        printf("Nilai m dan n harus sama");
    }

    return 0;
}
