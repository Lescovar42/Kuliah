/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal : 6 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.h"
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
  PrintList(L1);
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

  //9. DeleteVLast
  printf("\n\n9. DeleteVLast");
  infotype hapusAkhir;
  DeleteVLast(&L1, &hapusAkhir);
  printf("\n   Hapus elemen terakhir: '%c'", hapusAkhir);
  PrintList(L1);
  printf("\n   Jumlah elemen sekarang = %d", NbElm(L1));

  //10. SearchX
  printf("\n\n10. SearchX");
  address found;
  SearchX(L1, 'A', &found);
  if (found != NIL) {
      printf("\n   Elemen 'A' ditemukan dengan info = '%c'", info(found));
  } else {
      printf("\n   Elemen 'A' tidak ditemukan");
  }
  SearchX(L1, 'Z', &found);
  if (found != NIL) {
      printf("\n   Elemen 'Z' ditemukan dengan info = '%c'", info(found));
  } else {
      printf("\n   Elemen 'Z' tidak ditemukan");
  }

  //11. UpdateX
  printf("\n\n11. UpdateX");
  printf("\n   List sebelum update:");
  PrintList(L1);
  UpdateX(&L1, 'A', 'Z');
  printf("\n   Update elemen 'A' menjadi 'Z'");
  printf("\n   List setelah update:");
  PrintList(L1);

  //12. Invers
  printf("\n\n12. Invers");
  printf("\n   List sebelum dibalik:");
  PrintList(L1);
  Invers(&L1);
  printf("\n   List setelah dibalik:");
  PrintList(L1);

  //13. CountX dan CountVocal
  printf("\n\n13. CountX dan CountVocal");
  // Buat list baru untuk test
  List1 L2;
  CreateList(&L2);
  InsertVLast(&L2, 'A');
  InsertVLast(&L2, 'B');
  InsertVLast(&L2, 'A');
  InsertVLast(&L2, 'C');
  InsertVLast(&L2, 'A');
  InsertVLast(&L2, 'I');
  InsertVLast(&L2, 'U');
  printf("\n   List L2:");
  PrintList(L2);
  printf("\n   Jumlah huruf 'A' = %d", CountX(L2, 'A'));
  printf("\n   Jumlah huruf vokal = %d", CountVocal(L2, 'A'));

  //14. FrekuensiX
  printf("\n\n14. FrekuensiX");
  printf("\n   Frekuensi huruf 'A' di L2 = %.2f", FrekuensiX(L2, 'A'));
  printf("\n   Frekuensi huruf 'B' di L2 = %.2f", FrekuensiX(L2, 'B'));

  //15. SearchAllX
  printf("\n\n15. SearchAllX");
  SearchAllX(L2, 'A');

  //16. UpdateAllX
  printf("\n\n16. UpdateAllX");
  printf("\n   List L2 sebelum update semua:");
  PrintList(L2);
  UpdateAllX(&L2, 'A', 'Z');
  printf("\n   Update semua 'A' menjadi 'Z'");
  printf("\n   List L2 setelah update semua:");
  PrintList(L2);

  //17. InsertVAfter
  printf("\n\n17. InsertVAfter");
  printf("\n   List L2 sebelum insert after:");
  PrintList(L2);
  InsertVAfter(&L2, 'B', 'X');
  printf("\n   Insert 'X' setelah 'B'");
  printf("\n   List L2 setelah insert after:");
  PrintList(L2);

  //18. Modus dan NbModus
  printf("\n\n18. Modus dan NbModus");
  printf("\n   List L2:");
  PrintList(L2);
  infotype modusChar = Modus(L2);
  int nbModus = NbModus(L2);
  printf("\n   Huruf yang paling sering muncul (Modus) = '%c'", modusChar);
  printf("\n   Jumlah kemunculan modus (NbModus) = %d", nbModus);

  //19. ConcatList
  printf("\n\n19. ConcatList");
  List1 L3, L4, LConcat;
  CreateList(&L3);
  InsertVLast(&L3, '1');
  InsertVLast(&L3, '2');
  InsertVLast(&L3, '3');
  CreateList(&L4);
  InsertVLast(&L4, '4');
  InsertVLast(&L4, '5');
  InsertVLast(&L4, '6');
  printf("\n   List L3:");
  PrintList(L3);
  printf("\n   List L4:");
  PrintList(L4);
  ConcatList(L3, L4, &LConcat);
  printf("\n   List hasil concat L3+L4:");
  PrintList(LConcat);

  //20. SplitList
  printf("\n\n20. SplitList");
  List1 LSplit1, LSplit2;
  printf("\n   List LConcat sebelum split:");
  PrintList(LConcat);
  SplitList(LConcat, &LSplit1, &LSplit2);
  printf("\n   List hasil split pertama (LSplit1):");
  PrintList(LSplit1);
  printf("\n   List hasil split kedua (LSplit2):");
  PrintList(LSplit2);

  //21. CopyList
  printf("\n\n21. CopyList");
  List1 LCopy;
  printf("\n   List L3 (original):");
  PrintList(L3);
  CopyList(L3, &LCopy);
  printf("\n   List LCopy (hasil copy dari L3):");
  PrintList(LCopy);
  printf("\n   Jumlah elemen L3 = %d", NbElm(L3));
  printf("\n   Jumlah elemen LCopy = %d", NbElm(LCopy));
  return 0;
}
