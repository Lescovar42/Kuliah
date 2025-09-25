/*Nama File 	: FaktorBil.c*/
/*Deskripsi 	: Menentukan faktor bilangan dari N*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 19-02-2025/19:10*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int N, i;

  /*Algoritma*/
  printf("Masukkan bilangan N (N > 0): ");
  scanf("%d", &N);

  if (N <= 0) {
      printf("Harus bilangan positif\n");
  } else {
      printf("Faktor bilangan dari %d adalah: ", N);
      for (i = 1; i <= N; i++) {
          if (N % i == 0) {
              printf("%d ", i);
          }
      }
      printf("\n");
  }

  return 0;
}
