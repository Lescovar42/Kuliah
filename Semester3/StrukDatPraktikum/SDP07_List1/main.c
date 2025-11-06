/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal : 6 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
#include "list1.c"
int main()
{ //kamus
  address A; 
  address B;
  address P;
  List1 Senarai;
  //algoritma
  
  //aplikasi tipe address
  
  A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
  A->info = 'G';   A->next = NIL;
  printf("info(A)=%c\t", A->info );
  B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
  B->info = 'N';   B->next = A;
  printf("info(B)=%c\n", B->info );
  
  //aplikasi tipe List1
  Senarai.First = B; //First(Senarai) = B;
  printf("Isi Senarai :");
  P = First(Senarai);
  while (P != NIL) {
	  printf("\t%c",info(P));
	  P = next(P);
  }
  PrintList( Senarai );

  //1. CreateList
  List1 L1;
  printf("\n1. CreateList");
  CreateList(&L1);
  printf("\n   List L1 telah dibuat (kosong)");

  //2. IsEmptyList
  printf("\n\n2. IsEmptyList");
  if (IsEmptyList(L1)) {
      printf("\n   L1 adalah list kosong: TRUE");
  } else {
      printf("\n   L1 adalah list kosong: FALSE");
  }

  //3. InsertVFirst
  printf("\n\n3. InsertVFirst");
  InsertVFirst(&L1, 'A');
  printf("\n   Insert 'A' di awal");
  InsertVFirst(&L1, 'B');
  printf("\n   Insert 'B' di awal");
  InsertVFirst(&L1, 'C');
  printf("\n   Insert 'C' di awal");
  PrintList(L1);

  //4. InsertVLast
  printf("\n\n4. InsertVLast");
  InsertVLast(&L1, 'X');
  printf("\n   Insert 'X' di akhir");
  InsertVLast(&L1, 'Y');
  printf("\n   Insert 'Y' di akhir");
  PrintList(L1);

  //5. NbElm
  printf("\n\n5. NbElm");
  printf("\n   Jumlah elemen L1 = %d", NbElm(L1));

  //6. DeleteVFirst
  printf("\n\n6. DeleteVFirst");
  infotype hapus;
  DeleteVFirst(&L1, &hapus);
  printf("\n   Hapus elemen pertama: '%c'", hapus);
  PrintList(L1);
  printf("\n   Jumlah elemen sekarang = %d", NbElm(L1));

  //7. IsEmptyList
  printf("\n\n7. IsEmptyList (setelah ada isi)");
  if (IsEmptyList(L1)) {
      printf("\n   L1 adalah list kosong: TRUE");
  } else {
      printf("\n   L1 adalah list kosong: FALSE");
  }

  //8. PrintList
  printf("\n\n8. PrintList (isi akhir L1)");
  PrintList(L1);

  return 0;
}
