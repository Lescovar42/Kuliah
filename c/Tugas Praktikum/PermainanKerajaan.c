/*Nama File 	: PermainanKerajaan.c*/
/*Deskripsi 	: setiap tahun keluarga kerajaan akan melakukan sebuah permainan di mana dua kelompok bersaing dalam sebuah permainan tradisional.
Setiap kelompok memiliki poin awal yang akan terus berubah mengikuti aturan khusus
Kelompok Kerajaan memiliki poin awal F
Kelompok Rakyat memiliki poin awal C
Setiap putaran, poin berubah sebagai berikut:
       Kelompok Kerajaan:
         Jika F lebih kecil dari C, maka F bertambah menjadi F 	+ C-     
         Jika F lebih besar dari C, maka F dikurangi setengahnya    
      Kelompok Rakyat:
        Jika C adalah bilangan genap, maka C dibagi 2-
        Jika C adalah bilangan ganjil, maka C dikalikan 3 lalu ditambah 14. 
4. Permainan berhenti ketika F dan C menjadi sama atau salah satu kelompok mendapatkan poin 1
Buat program yang membaca dua angka F dan C sebagai poin awal kedua kelompok, lalu mensimulasikan permainan hingga kondisi berhenti terpenuhi. Setiap langkah harus ditampilkan hingga permainan berakhir..*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 6-03-2025/10:35*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main() {
    /*Kamus*/
    int F, C;
    
    /*Algoritma*/
    printf("Masukkan poin awal untuk Kelompok Kerajaan: ");
    scanf("%d", &F);
    printf("Masukkan poin awal untuk Kelompok Rakyat: ");
    scanf("%d", &C);

    while (F != C && F != 1 && C != 1)
    {
        if (F < C)
        {
            F += C;   
        }
        else if (F > C)
        {
            F -= (F / 2);
        }

        if (C % 2 == 0)
        {
            C = C / 2;
        }
        else
        {
            C = C * 3 + 1;
        }

        printf("Kelompok Kerajaan: %d, Kelompok Rakyat: %d\n", F, C);
        
        if (F == 1)
        {
            printf("Kelompok Kerajaan menang!\n");
        }
        else if (C == 1)
        {
            printf("Kelompok Rakyat menang!\n");
        }
    }
    
    return 0;
}