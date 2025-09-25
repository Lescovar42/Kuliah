/*Nama File 	: SimetriTabel.c*/
/*Deskripsi 	: Mengecek apakah dua array memiliki ukuran dan isi yang sama (simetri)*/
/*Pembuat   	: 24060124140166-Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 20 April 2025 10.00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ /*Kamus*/
    int T1[100], T2[100]; // Array pertama dan kedua
    int n1, n2;            // Ukuran dari masing-masing array
    int i;                 // Indeks
    int nilai;            // Input sementara
    int isSimetri = 1;     // Status simetri, diasumsikan awalnya simetris

  /*Algoritma*/
    printf("Masukkan jumlah elemen untuk T1 dan T2: ");
    scanf("%d %d", &n1, &n2);

    printf("Masukkan elemen untuk T1:\n");
    i = 0;
    while (i < n1)
    {
        scanf("%d", &nilai);
        if (nilai < 0)
        {
            printf("Input tidak boleh negatif.\n");
        }
        else
        {
            T1[i] = nilai;
            i++;
        }
    }

    printf("Masukkan elemen untuk T2:\n");
    i = 0;
    while (i < n2)
    {
        scanf("%d", &nilai);
        if (nilai < 0)
        {
            printf("Input tidak boleh negatif.\n");
        }
        else
        {
            T2[i] = nilai;
            i++;
        }
    }

    if (n1 != n2)
    {
        printf("T1 dan T2 Tidak Simetri\n");
    }
    else
    {
        for (i = 0; i < n1; i++)
        {
            if (T1[i] != T2[i])
            {
                isSimetri = 0;
                break;
            }
        }

        if (isSimetri)
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
