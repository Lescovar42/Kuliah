/*Nama File 	: namaBulan.c*/
/*Deskripsi 	: Menampilkan nama bulan berdasarkan nomor bulan yang diinput dari keyboard*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 8-03-2025/17:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int n;

  /*Algoritma*/
  printf("Masukkan nomor bulan (1-12): ");
  scanf("%d", &n);

  if (n >= 1 && n <= 12) {
      switch(n) {
          case 1: printf("Januari\n"); break;
          case 2: printf("Februari\n"); break;
          case 3: printf("Maret\n"); break;
          case 4: printf("April\n"); break;
          case 5: printf("Mei\n"); break;
          case 6: printf("Juni\n"); break;
          case 7: printf("Juli\n"); break;
          case 8: printf("Agustus\n"); break;
          case 9: printf("September\n"); break;
          case 10: printf("Oktober\n"); break;
          case 11: printf("November\n"); break;
          case 12: printf("Desember\n"); break;
      }
  } else {
    printf("Masukan nomor bulan tidak tepat\n");
  }

  return 0;
}
