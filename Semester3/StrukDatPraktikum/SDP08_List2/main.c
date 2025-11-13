/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait sirkular, representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 13 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list2.h"

int main() {
    // Kamus
    List2 L;
    infotype val;
    int jumlah;
    address found;
    address A;
    address B;
    address P;
    List2 Senarai;

    // Algoritma
    printf("=== TEST MANUAL ALOKASI ===\n");
    A = (address) malloc ( sizeof (Elm2) ); // Alokasi('G')
    A->info = 'G';   A->next = NIL;
    printf("info(A)=%c\t", A->info );
    B = (address) malloc ( sizeof (Elm2) ); // Alokasi('N')
    B->info = 'N';   B->next = A;
    printf("info(B)=%c\n", B->info );
    
    Senarai.First = B;
    printf("Isi Senarai :");
    P = First(Senarai);
    while (P != NIL) {
      printf("\t%c",info(P));
      P = next(P);
    }
    printf("\n");
    free(B);
    free(A);

    // 1. Test CreateList
    
    printf("\n1. TEST CREATE LIST\n");
    CreateList(&L);
    printf("List L telah dibuat.\n");
    printf("Apakah list kosong? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");

    // 2. Test InsertVFirst
    
    printf("\n2. TEST INSERT V FIRST\n");
    printf("Menambahkan elemen 'A', 'B', 'C' di awal list...\n");
    InsertVFirst(&L, 'A');
    InsertVFirst(&L, 'B');
    InsertVFirst(&L, 'C');
    printf("Isi list setelah InsertVFirst: ");
    PrintList(L);
    printf("Jumlah elemen: %d\n", NbElm(L));

    // 3. Test InsertVLast
    
    printf("\n3. TEST INSERT V LAST\n");
    printf("Menambahkan elemen 'D', 'E' di akhir list...\n");
    InsertVLast(&L, 'D');
    InsertVLast(&L, 'E');
    printf("Isi list setelah InsertVLast: ");
    PrintList(L);
    printf("Jumlah elemen: %d\n", NbElm(L));

    // 4. Test IsOneElm
    
    printf("\n4. TEST IS ONE ELEMENT\n");
    printf("Apakah list hanya punya 1 elemen? %s\n", IsOneElm(L) ? "Ya" : "Tidak");

    // 5. Test NbElm
    
    printf("\n5. TEST NUMBER OF ELEMENTS\n");
    jumlah = NbElm(L);
    printf("Jumlah elemen dalam list: %d\n", jumlah);

    // 6. Test DeleteVFirst
    
    printf("\n6. TEST DELETE V FIRST\n");
    printf("Isi list sebelum penghapusan: ");
    PrintList(L);
    DeleteVFirst(&L, &val);
    printf("Elemen yang dihapus: %c\n", val);
    printf("Isi list setelah DeleteVFirst: ");
    PrintList(L);
    printf("Jumlah elemen: %d\n", NbElm(L));

    // 7. Test DeleteVLast
    
    printf("\n7. TEST DELETE V LAST\n");
    printf("Isi list sebelum penghapusan: ");
    PrintList(L);
    DeleteVLast(&L, &val);
    printf("Elemen yang dihapus: %c\n", val);
    printf("Isi list setelah DeleteVLast: ");
    PrintList(L);
    printf("Jumlah elemen: %d\n", NbElm(L));

    // 8. Test dengan list baru (List kosong -> 1 elemen -> kosong)
    
    printf("\n8. TEST LIST DENGAN 1 ELEMEN\n");
    List2 L2;
    CreateList(&L2);
    printf("Membuat list baru L2...\n");
    InsertVFirst(&L2, 'K');
    printf("Menambah 1 elemen 'K': ");
    PrintList(L2);
    printf("Apakah list hanya punya 1 elemen? %s\n", IsOneElm(L2) ? "Ya" : "Tidak");
    DeleteVFirst(&L2, &val);
    printf("Menghapus elemen: %c\n", val);
    printf("Apakah list kosong? %s\n", IsEmptyList(L2) ? "Ya" : "Tidak");

    // 9. Test alokasi dan dealokasi manual
    
    printf("\n9. TEST ALOKASI DAN DEALOKASI\n");
    P = Alokasi('M');
    if (P != NIL) {
        printf("Alokasi berhasil! Info = %c\n", info(P));
        Dealokasi(&P);
        printf("Dealokasi berhasil! P = %s\n", P == NIL ? "NIL" : "Tidak NIL");
    }

    // 10. Test InsertVFirst dan DeleteVFirst hingga kosong
    
    printf("\n10. TEST MENGHAPUS SEMUA ELEMEN\n");
    printf("Isi list L saat ini: ");
    PrintList(L);
    printf("Menghapus semua elemen...\n");
    while (!IsEmptyList(L)) {
        DeleteVFirst(&L, &val);
        printf("Dihapus: %c, Sisa elemen: %d\n", val, NbElm(L));
    }
    printf("Apakah list kosong? %s\n", IsEmptyList(L) ? "Ya" : "Tidak");

    // 11. Test InsertVLast pada list kosong
    
    printf("\n11. TEST INSERT LAST PADA LIST KOSONG\n");
    printf("Menambah elemen 'P', 'Q', 'R' dengan InsertVLast...\n");
    InsertVLast(&L, 'P');
    InsertVLast(&L, 'Q');
    InsertVLast(&L, 'R');
    printf("Isi list: ");
    PrintList(L);
    printf("Jumlah elemen: %d\n", NbElm(L));

    // 12. Test SearchX
    
    printf("\n12. TEST SEARCH X\n");
    printf("Isi list saat ini: ");
    PrintList(L);

    printf("Mencari elemen 'Q'...\n");
    SearchX(L, 'Q', &found);
    if (found != NIL) {
        printf("Elemen 'Q' DITEMUKAN! Info: %c\n", info(found));
    } else {
        printf("Elemen 'Q' tidak ditemukan.\n");
    }

    printf("Mencari elemen 'P'...\n");
    SearchX(L, 'P', &found);
    if (found != NIL) {
        printf("Elemen 'P' DITEMUKAN! Info: %c\n", info(found));
    } else {
        printf("Elemen 'P' tidak ditemukan.\n");
    }

    printf("Mencari elemen 'R'...\n");
    SearchX(L, 'R', &found);
    if (found != NIL) {
        printf("Elemen 'R' DITEMUKAN! Info: %c\n", info(found));
    } else {
        printf("Elemen 'R' tidak ditemukan.\n");
    }

    printf("Mencari elemen 'Z' (tidak ada di list)...\n");
    SearchX(L, 'Z', &found);
    if (found != NIL) {
        printf("Elemen 'Z' DITEMUKAN! Info: %c\n", info(found));
    } else {
        printf("Elemen 'Z' TIDAK DITEMUKAN.\n");
    }

    // 13. Test SearchX pada list kosong
    
    printf("\n13. TEST SEARCH X PADA LIST KOSONG\n");
    List2 L3;
    CreateList(&L3);
    printf("Mencari elemen 'A' pada list kosong...\n");
    SearchX(L3, 'A', &found);
    if (found != NIL) {
        printf("Elemen 'A' ditemukan!\n");
    } else {
        printf("Elemen 'A' TIDAK DITEMUKAN (list kosong).\n");
    }

    // 14. Test SearchX dengan multiple insertions
    
    printf("\n14. TEST SEARCH X DENGAN BANYAK ELEMEN\n");
    printf("Menambahkan elemen 'X', 'Y', 'X', 'Z'...\n");
    InsertVLast(&L, 'X');
    InsertVLast(&L, 'Y');
    InsertVLast(&L, 'X');
    InsertVLast(&L, 'Z');
    printf("Isi list: ");
    PrintList(L);
    printf("Mencari elemen 'X' (muncul 2 kali, akan menemukan yang pertama)...\n");
    SearchX(L, 'X', &found);
    if (found != NIL) {
        printf("Elemen 'X' DITEMUKAN! Info: %c\n", info(found));
    } else {
        printf("Elemen 'X' tidak ditemukan.\n");
    }
    return 0;
}
