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

        // 15. Test DeleteX
    printf("\n15. TEST DELETE X\n");
    printf("Isi list sebelum DeleteX('X'): ");
    PrintList(L);
    printf("Menghapus satu elemen 'X'...\n");
    DeleteX(&L, 'X');
    printf("Isi list setelah DeleteX: ");
    PrintList(L);
    printf("Jumlah elemen: %d\n", NbElm(L));
 
    // 16. Test UpdateX
    printf("\n16. TEST UPDATE X\n");
    printf("Isi list saat ini: ");
    PrintList(L);
    printf("Mengubah elemen 'Y' menjadi 'W'...\n");
    UpdateX(&L, 'Y', 'W');
    printf("Isi list setelah UpdateX: ");
    PrintList(L);
 
    // 17. Test Invers
    printf("\n17. TEST INVERS\n");
    printf("Isi list sebelum Invers: ");
    PrintList(L);
    Invers(&L);
    printf("Isi list setelah Invers: ");
    PrintList(L);
 
    // 18. Test CountX dan FrekuensiX
    printf("\n18. TEST COUNT X DAN FREKUENSI X\n");
    printf("Isi list: ");
    PrintList(L);
    int countP = CountX(L, 'P');
    int countX = CountX(L, 'X');
    printf("Jumlah kemunculan 'P': %d\n", countP);
    printf("Jumlah kemunculan 'X': %d\n", countX);
    printf("Frekuensi 'P': %.2f\n", FrekuensiX(L, 'P'));
    printf("Frekuensi 'X': %.2f\n", FrekuensiX(L, 'X'));
 
    // 19. Test CountVocal dan CountNG
    printf("\n19. TEST COUNT VOCAL DAN COUNT NG\n");
    List2 L4;
    CreateList(&L4);
    InsertVLast(&L4, 'B');
    InsertVLast(&L4, 'A');
    InsertVLast(&L4, 'N');
    InsertVLast(&L4, 'G');
    InsertVLast(&L4, 'U');
    InsertVLast(&L4, 'N');
    printf("Isi list: ");
    PrintList(L4);
    printf("Jumlah huruf vokal: %d\n", CountVocal(L4));
    printf("Jumlah 'NG': %d\n", CountNG(L4));
 
    // 20. Test InsertVAfterX dan InsertVBeforeX
    printf("\n20. TEST INSERT V AFTER X DAN INSERT V BEFORE X\n");
    printf("Isi list sebelum insert: ");
    PrintList(L4);
    printf("Insert 'M' setelah 'N'...\n");
    InsertVAfterX(&L4, 'N', 'M');
    printf("Isi list: ");
    PrintList(L4);
    printf("Insert 'K' sebelum 'G'...\n");
    InsertVBeforeX(&L4, 'G', 'K');
    printf("Isi list: ");
    PrintList(L4);
    printf("Jumlah elemen: %d\n", NbElm(L4));
 
    // 21. Test DeleteVAfterX dan DeleteVBeforeX
    printf("\n21. TEST DELETE V AFTER X DAN DELETE V BEFORE X\n");
    printf("Isi list sebelum delete: ");
    PrintList(L4);
    DeleteVAfterX(&L4, 'N', &val);
    printf("Delete elemen setelah 'N', elemen yang dihapus: %c\n", val);
    printf("Isi list: ");
    PrintList(L4);
    DeleteVBeforeX(&L4, 'G', &val);
    printf("Delete elemen sebelum 'G', elemen yang dihapus: %c\n", val);
    printf("Isi list: ");
    PrintList(L4);
    printf("Jumlah elemen: %d\n", NbElm(L4));
 
    // 22. Test DeleteAllX
    printf("\n22. TEST DELETE ALL X\n");
    List2 L5;
    CreateList(&L5);
    InsertVLast(&L5, 'A');
    InsertVLast(&L5, 'B');
    InsertVLast(&L5, 'A');
    InsertVLast(&L5, 'C');
    InsertVLast(&L5, 'A');
    printf("Isi list sebelum DeleteAllX('A'): ");
    PrintList(L5);
    printf("Menghapus semua elemen 'A'...\n");
    DeleteAllX(&L5, 'A');
    printf("Isi list setelah DeleteAllX: ");
    PrintList(L5);
    printf("Jumlah elemen: %d\n", NbElm(L5));
 
    // 23. Test SearchAllX
    printf("\n23. TEST SEARCH ALL X\n");
    List2 L6;
    CreateList(&L6);
    InsertVLast(&L6, 'M');
    InsertVLast(&L6, 'A');
    InsertVLast(&L6, 'N');
    InsertVLast(&L6, 'D');
    InsertVLast(&L6, 'A');
    printf("Isi list: ");
    PrintList(L6);
    printf("Posisi kemunculan 'A': ");
    SearchAllX(L6, 'A');
    printf("\nPosisi kemunculan 'M': ");
    SearchAllX(L6, 'M');
    printf("\nPosisi kemunculan 'J': ");
    SearchAllX(L6, 'J');
    printf("\n");
 
    // 24. Test MaxMember dan Modus
    printf("\n24. TEST MAX MEMBER DAN MODUS\n");
    printf("Isi list: ");
    PrintList(L6);
    printf("Jumlah huruf yang paling banyak muncul: %d\n", MaxMember(L6));
    printf("Huruf yang paling banyak muncul (modus): %c\n", Modus(L6));
 
    // 25. Test ConcatList
    printf("\n25. TEST CONCAT LIST\n");
    List2 L7, L8, L9;
    CreateList(&L7);
    CreateList(&L8);
    InsertVLast(&L7, 'A');
    InsertVLast(&L7, 'B');
    InsertVLast(&L7, 'C');
    InsertVLast(&L8, 'X');
    InsertVLast(&L8, 'Y');
    InsertVLast(&L8, 'Z');
    printf("List L7: ");
    PrintList(L7);
    printf("List L8: ");
    PrintList(L8);
    ConcatList(L7, L8, &L9);
    printf("List L9 (hasil concat L7 dan L8): ");
    PrintList(L9);
    printf("Jumlah elemen L9: %d\n", NbElm(L9));
 
    // 26. Test SplitList
    printf("\n26. TEST SPLIT LIST\n");
    List2 L10, L11, L12;
    CreateList(&L10);
    InsertVLast(&L10, 'A');
    InsertVLast(&L10, 'B');
    InsertVLast(&L10, 'C');
    InsertVLast(&L10, 'D');
    InsertVLast(&L10, 'E');
    printf("List L10 sebelum split: ");
    PrintList(L10);
    SplitList(L10, &L11, &L12);
    printf("List L11 (hasil split pertama): ");
    PrintList(L11);
    printf("Jumlah elemen L11: %d\n", NbElm(L11));
    printf("List L12 (hasil split kedua): ");
    PrintList(L12);
    printf("Jumlah elemen L12: %d\n", NbElm(L12));
 
    // 27. Test CopyList
    printf("\n27. TEST COPY LIST\n");
    List2 L13, L14;
    CreateList(&L13);
    InsertVLast(&L13, 'P');
    InsertVLast(&L13, 'Q');
    InsertVLast(&L13, 'R');
    printf("List L13 (original): ");
    PrintList(L13);
    CopyList(L13, &L14);
    printf("List L14 (copy dari L13): ");
    PrintList(L14);
    printf("Apakah L13 dan L14 sama? ");
    if (NbElm(L13) == NbElm(L14)) {
        printf("Ya (jumlah elemen sama: %d)\n", NbElm(L13));
    } else {
        printf("Tidak\n");
    }
    return 0;
}
