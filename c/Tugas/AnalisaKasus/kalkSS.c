/*Nama File 	: kalkSS.c*/
/*Deskripsi 	: Kalkulator sederhana yang melakukan operasi aritmatika sesuai pilihan pengguna*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 10-03-2025/21:00*/

#include <stdio.h> /*header file*/

/*Program Utama*/
int main()
{ 
  /*Kamus*/
  int iA, iB;
  char pilihan;

  /*Algoritma*/
  printf("Masukkan dua bilangan bulat: ");
  scanf("%d %d", &iA, &iB);

  printf("Pilih operasi (a-f): ");
  scanf(" %c", &pilihan);

  switch(pilihan) {
      case 'a':
          printf("Hasil %d + %d = %d\n", iA, iB, iA + iB);
          break;
      case 'b':
          printf("Hasil %d - %d = %d\n", iA, iB, iA - iB);
          break;
      case 'c':
          printf("Hasil %d * %d = %d\n", iA, iB, iA * iB);
          break;
      case 'd':
          if (iB != 0) {
              printf("Hasil %d / %d = %.2f\n", iA, iB, (float)iA / iB);
          } else {
              printf("Kesalahan: Pembagian dengan nol\n");
          }
          break;
      case 'e':
          if (iB != 0) {
              printf("Hasil %d div %d = %d\n", iA, iB, iA / iB);
          } else {
              printf("Kesalahan: Pembagian dengan nol\n");
          }
          break;
      case 'f':
          if (iB != 0) {
              printf("Hasil %d mod %d = %d\n", iA, iB, iA % iB);
          } else {
              printf("Kesalahan: Modulo dengan nol\n");
          }
          break;
      default:
          printf("Bukan pilihan menu yang benar\n");
  }

  return 0;
}
