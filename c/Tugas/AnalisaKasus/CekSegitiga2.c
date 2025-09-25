/*Nama File 	: CekSegitiga.c*/
/*Deskripsi 	: Menentukan jenis segitiga berdasarkan panjang sisi-sisinya dengan aturan segitiga*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 9-03-2025/12:00*/

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
  } 
  else if ((a + b > c) && (a + c > b) && (b + c > a)) {
      if (a == b && b == c) {
          printf("Segitiga Sama Sisi\n");
      } else if (a == b || b == c || a == c) {
          printf("Segitiga Sama Kaki\n");
      } else {
          printf("Segitiga Sembarang\n");
      }
  } 
  else {
      printf("Bilangan tersebut tidak membentuk segitiga\n");
  }

  return 0;
}
