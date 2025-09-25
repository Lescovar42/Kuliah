/*Nama File 	: JumFrekNilTabel.c*/
/*Deskripsi 	: Menjumlahkan nilai element tabel T yang frekuensi kemunculan nya lebih dari satu*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 06.40*/

#include <stdio.h> /*header file*/

// Program utama
int main()
{
    // Kamus
    int i, j;  // Variabel untuk iterasi
    int elmt;  // Elemen yang akan dimasukkan
    int count; // Untuk menghitung frekuensi
    int n;     // Ukuran tabel
    int total; // Untuk menyimpan total jumlah elemen
    printf("Masukkan banyaknya elemen: ");
    scanf("%d", &n);
    int T[n]; // Tabel untuk menyimpan elemen

    // Algoritma
    printf("Masukkan elemen-elemen tabel: ");
    i = 0;
    while (i < n)
    {
        // Input elemen tabel
        scanf("%d", &elmt);
        if (elmt < 0)
        {
            printf("Nilai tidak boleh negatif\n");
        }
        else
        {
            T[i] = elmt; // Simpan elemen ke dalam tabel
            i++;
        }
    }

    // Jumlahkan elemen dengan frekuensi lebih dari satu
    total = 0;
    for (i = 0; i < n; i++)
    {
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (T[i] == T[j] && T[j] != -1)
            {
                count++;
                T[j] = -1; // Tandai elemen yang sudah dihitung
            }
        }
        if (count > 1 && T[i] != -1)
        {
            total += T[i] * count; // Tambahkan elemen ke total
        }
    }
    printf("Total elemen yang muncul lebih dari satu kali adalah %d\n", total);

    return 0;
}
