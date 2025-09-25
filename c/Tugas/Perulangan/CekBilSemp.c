/*Nama File 	: CekBilSemp.c*/
/*Deskripsi 	: Menentukan apakah bilangan N adalah bilangan sempurna atau bukan*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 19-03-2025/21:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int N, i, sum = 0;

  /*Algoritma*/
  printf("Masukkan bilangan N (N > 0): ");
  scanf("%d", &N);

  if (N <= 0) {
      printf("Harus bilangan positif\n");
  } 
  else {
      for (i = 1; i < N; i++) {
          if (N % i == 0) {
              sum += i;
          }
      }
      if (sum == N) {
          printf("%d adalah Bilangan Sempurna\n", N);
      } else {
          printf("%d Bukan Bilangan Sempurna\n", N);
      }
  }

  return 0;
}
