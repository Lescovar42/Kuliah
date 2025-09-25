/*Nama File 	: CekSegitiga.c*/
/*Deskripsi 	: Menentukan jenis segitiga berdasarkan panjang sisi-sisinya*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 28-02-2025/19:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int a, b, c;

  /*Algoritma*/
  printf("Masukkan tiga sisi segitiga (bilangan positif): ");
  scanf("%d %d %d", &a, &b, &c);

  if (a <= 0 || b <= 0 || c <= 0) {
      printf("Terdapat nilai yang bukan sisi segitiga\n");
  } else if (a == b && b == c) {
      printf("Segitiga Sama Sisi\n");
  } else if (a == b || b == c || a == c) {
      printf("Segitiga Sama Kaki\n");
  } else {
      printf("Segitiga Sembarang\n");
  }

  return 0;
}
