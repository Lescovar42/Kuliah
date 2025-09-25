/*Nama File 	: bilInteger.c*/
/*Deskripsi 	: Menentukan apakah bilangan yang dimasukkan adalah bilangan bulat positif, nol, atau bilangan bulat negatif */
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 8-03-2025/12:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int i;

  /*Algoritma*/
  printf("Masukkan sebuah bilangan integer: ");
  scanf("%d", &i);

  if (i > 0) {
      printf("Bilangan bulat positif\n");
  } else if (i == 0) {
      printf("Bilangan nol\n");
  } else {
      printf("Bilangan bulat negatif\n");
  }

  return 0;
}
