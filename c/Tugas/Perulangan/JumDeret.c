/*Nama File 	: JumDeret.c*/
/*Deskripsi 	: Menghitung jumlah total deret bilangan dari 1 sampai N*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 19-03-2025/19:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int N, i, jumlah = 0;

  /*Algoritma*/
  printf("Masukkan bilangan N (N > 0): ");
  scanf("%d", &N);

  if (N <= 0) {
      printf("Harus bilangan positif\n");
  } else {
      for (i = 1; i <= N; i++) {
          jumlah += i;
      }
      printf("Jumlah total deret 1 + 2 + ... + %d = %d\n", N, jumlah);
  }

  return 0;
}
