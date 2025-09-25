/*Nama File 	: JumBarKolMat.c*/
/*Deskripsi 	: Menjumlahkan tiap baris dan kolom sebuah tabel*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 07.20*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{
    /*Kamus*/
    int i, j;           // Counter
    int baris, kolom;   // Ukuran tabel
    int elmt;           // Elemen yang akan dimasukkan
    int sumRow, sumCol; // Jumlah per baris dan per kolom
    scanf("%d %d", &baris, &kolom);
    int T[baris][kolom]; // Tabel 2 dimensi

    // Algoritma
    // Input elemen tabel
    printf("Masukkan elemen tabel:\n");
    i = 0;
    while (i < baris)
    {
        j = 0;
        while (j < kolom)
        {
            scanf("%d", &elmt);
            if (elmt < 0)
            {
                printf("Nilai tidak boleh negatif\n");
            }
            else
            {
                T[i][j] = elmt; // Simpan elemen ke dalam tabel
                j++;
            }
        }
        i++;
    }

    // Menjumlahkan per baris
    for (i = 0; i < baris; i++)
    {
        sumRow = 0;
        for (j = 0; j < kolom; j++)
        {
            sumRow += T[i][j];
        }
        printf("Baris ke-%d: %d\n", i + 1, sumRow);
    }

    // Menjumlahkan per kolom
    for (j = 0; j < kolom; j++)
    {
        sumCol = 0;
        for (i = 0; i < baris; i++)
        {
            sumCol += T[i][j];
        }
        printf("Kolom ke-%d: %d\n", j + 1, sumCol);
    }

    return 0;
}
