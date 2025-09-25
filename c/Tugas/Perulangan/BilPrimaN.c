/*Nama File 	: BilPrimaN.c*/
/*Deskripsi 	: Mencetak bilangan prima sampai dengan N*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 20-03-2025/19:30*/

#include <stdio.h>
#include <math.h> /*Header File*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int N, i, j, isPrime;

  /*Algoritma*/
  printf("Masukkan bilangan N (N > 0): ");
  scanf("%d", &N);

  if (N <= 0) {
      printf("Harus bilangan positif\n");
  } 
  else {
      printf("Bilangan Prima hingga %d adalah: ", N);
      for (i = 2; i <= N; i++) { // Looping dari 2 sampai N
          isPrime = 1; // Asumsi awal i adalah bilangan prima

          // Cek apakah i memiliki faktor selain 1 dan dirinya sendiri
          for (j = 2; j <= sqrt(i); j++) {
              if (i % j == 0) {
                  isPrime = 0;
                  break;
              }
          }

          if (isPrime) {
              printf("%d ", i);
          }
      }
      printf("\n");
  }

  return 0;
}
