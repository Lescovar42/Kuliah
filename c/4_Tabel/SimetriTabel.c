/*Nama File 	: SimetriTabel.c*/
/*Deskripsi 	: Memeriksa simetri antara ukuran dan nilai antara tabel*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 07.00*/

#include <stdio.h> /*header file*/

// Program utama
int main()
{
    // Kamus
    int i;       // Variabel untuk iterasi dan menghitung frekuensi
    int elmt;    // Elemen yang akan dimasukkan
    int simetri; // Variabel untuk menyimpan hasil simetri
    int n1, n2;  // Ukuran  tabel
    // Input ukuran tabel
    printf("Masukkan ukuran tabel T1 dan T2: ");
    scanf("%d %d", &n1, &n2);
    int T1[n1], T2[n2]; // Tabel untuk menyimpan elemen

    // Algoritma
    printf("Masukkan elemen array untuk T1:\n");
    i = 0;
    while (i < n1)
    {
        // Input elemen tabel
        scanf("%d", &elmt);
        if (elmt < 0)
        {
            printf("Nilai tidak boleh negatif\n");
        }
        else
        {
            T1[i] = elmt; // Simpan elemen ke dalam tabel
            i++;
        }
    }

    printf("Masukkan elemen array untuk T2:\n");
    i = 0;
    while (i < n2)
    {
        // Input elemen tabel
        scanf("%d", &elmt);
        if (elmt < 0)
        {
            printf("Nilai tidak boleh negatif\n");
        }
        else
        {
            T2[i] = elmt; // Simpan elemen ke dalam tabel
            i++;
        }
    }

    // Memeriksa simetri antara ukuran dan nilai antara tabel
    if (n1 != n2)
    {
        printf("T1 dan T2 Tidak Simetri\n");
    }
    else
    {
        i = 0;
        simetri = 1; // Asumsi awal simetri
        while (i < n1 && simetri == 1)
        {
            if (T1[i] != T2[i])
            {
                simetri = 0; // Tidak simetri
            }
            i++;
        }

        if (simetri == 1) // Jika simetri tetap 1
        {
            printf("T1 dan T2 Simetri\n");
        }
        else
        {
            printf("T1 dan T2 Tidak Simetri\n");
        }
    }

    return 0;
}
