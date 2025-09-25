/*Nama File 	: BilSempN.c*/
/*Deskripsi 	: Mencetak bilangan sempurna hingga bilangan N*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 20-03-2025/19:40*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int N, i, j, sum;

  /*Algoritma*/
  printf("Masukkan bilangan N (N > 0): ");
  scanf("%d", &N);

  if (N <= 0) {
      printf("Harus bilangan positif\n");
  } else {
      printf("Bilangan Sempurna hingga %d adalah: ", N);
      for (i = 1; i <= N; i++) {
          sum = 0;
          for (j = 1; j < i; j++) {
              if (i % j == 0) {
                  sum += j;
              }
          }
          if (sum == i) {
              printf("%d ", i);
          }
      }
      printf("\n");
  }

  return 0;
}
