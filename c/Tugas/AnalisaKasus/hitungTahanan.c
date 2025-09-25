/*Nama File 	: hitungTahanan.c*/
/*Deskripsi 	: Menghitung total tahanan jika dirangkai seri dengan validasi input*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 9-03-2025/10:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int R1, R2, R3, R_total;

  /*Algoritma*/
  printf("Masukkan tiga nilai tahanan (dalam ohm): ");
  scanf("%d %d %d", &R1, &R2, &R3);

  if (R1 < 0 || R2 < 0 || R3 < 0) {
      printf("Masukan tahanan tidak boleh negatif\n");
  } else {
      R_total = R1 + R2 + R3;
      printf("Total tahanan dalam rangkaian seri: %d ohm\n", R_total);
  }

  return 0;
}
