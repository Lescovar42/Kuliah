/*Nama File 	: CekBilPrima.c*/
/*Deskripsi 	: Menentukan apakah bilangan N adalah bilangan prima atau bukan*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 19-02-2025/22:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int N, i, count = 0;

  /*Algoritma*/
  printf("Masukkan bilangan N (N > 0): ");
  scanf("%d", &N);

  if (N <= 0) {
      printf("Harus bilangan positif\n");
  } 
  else if (N == 1) {
      printf("Bukan Bilangan Prima\n");
  } 
  else {
      for (i = 1; i <= N; i++) {
          if (N % i == 0) {
              count++;
          }
      }
      if (count == 2) {
          printf("Bilangan Prima\n");
      } else {
          printf("Bukan Bilangan Prima\n");
      }
  }

  return 0;
}
