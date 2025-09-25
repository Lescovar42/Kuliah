/*Nama File 	: JumFrekNilTabel.c*/
/*Deskripsi 	: Menjumlahkan nilai-nilai dalam array T yang memiliki frekuensi kemunculan lebih dari satu*/
/*Pembuat   	: 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 19 April 2025-19:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
    int T[100];     // Array untuk menyimpan data
    int n;          // Jumlah elemen
    int i, j;       // Indeks untuk perulangan
    int nilai;      // Input nilai
    int frek;       // Menyimpan frekuensi kemunculan
    int jumlah = 0; // Total nilai dengan frekuensi lebih dari satu

  /*Algoritma*/
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    i = 0;
    printf("Masukkan elemen-elemen (positif):\n");
    while (i < n)
    {
        scanf("%d", &nilai);
        if (nilai < 0)
        {
            printf("Masukan tidak valid, harus positif.\n");
        }
        else
        {
            T[i] = nilai;
            i++;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (T[i] != -1)
        {
            frek = 1;
            for (j = i + 1; j < n; j++)
            {
                if (T[i] == T[j])
                {
                    frek++;
                    T[j] = -1; // Tandai elemen yang sudah diproses
                }
            }
            if (frek > 1)
            {
                jumlah += T[i] * frek;
            }
        }
    }

    printf("Jumlah nilai yang muncul lebih dari satu kali: %d\n", jumlah);

    return 0;
}
