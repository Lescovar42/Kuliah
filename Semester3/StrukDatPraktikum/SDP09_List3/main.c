/* File : main.c */
/* Deskripsi : aplikasi driver ADT list berkait doubly linear, representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 20 November 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list3.h"

int main() {
    // Kamus
    List3 L;
    infotype val;
    int jumlah;
    address found;
    address A;
    address B;
    address P;
    List3 Senarai;

    // Algoritma
    A = (address) malloc ( sizeof (Elm) ); // Alokasi('G')
    A->info = 'G';   A->next = NIL; A->prev = NIL;
    printf("info(A)=%c\t", info(A) );
    B = (address) malloc ( sizeof (Elm) ); // Alokasi('N')
    B->info = 'N';   B->next = A; B->prev = NIL;
    prev(A) = B;
    printf("info(B)=%c\n", info(B) );
    
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
    printf("\n TEST CreateList \n");
    CreateList(&L);
    printf("List L berhasil dibuat.\n");

    // 2. Test IsEmptyList
    printf("\n TEST IsEmptyList \n");
    if (IsEmptyList(L)) {
        printf("List L kosong.\n");
    } else {
        printf("List L tidak kosong.\n");
    }

    // 3. Test InsertVFirst
    printf("\n TEST InsertVFirst \n");
    InsertVFirst(&L, 'A');
    printf("Insert 'A' di awal.");
    PrintList(L);
    InsertVFirst(&L, 'B');
    printf("\nInsert 'B' di awal.");
    PrintList(L);
    InsertVFirst(&L, 'C');
    printf("\nInsert 'C' di awal.");
    PrintList(L);

    // 4. Test InsertVLast
    printf("\n\n TEST InsertVLast \n");
    InsertVLast(&L, 'X');
    printf("Insert 'X' di akhir.");
    PrintList(L);
    InsertVLast(&L, 'Y');
    printf("\nInsert 'Y' di akhir.");
    PrintList(L);
    InsertVLast(&L, 'Z');
    printf("\nInsert 'Z' di akhir.");
    PrintList(L);

    // 5. Test PrintList dan NbElm
    printf("\n\n TEST PrintList & NbElm \n");
    printf("Isi list L:");
    PrintList(L);
    jumlah = NbElm(L);
    printf("\nJumlah elemen: %d\n", jumlah);

    // 6. Test IsEmptyList (setelah diisi)
    printf("\n TEST IsEmptyList (setelah diisi) \n");
    if (IsEmptyList(L)) {
        printf("List L kosong.\n");
    } else {
        printf("List L tidak kosong.\n");
    }

    // 7. Test SearchX
    printf("\n TEST SearchX \n");
    SearchX(L, 'A', &found);
    if (found != NIL) {
        printf("Elemen 'A' ditemukan, info=%c\n", info(found));
    } else {
        printf("Elemen 'A' tidak ditemukan.\n");
    }
    SearchX(L, 'Q', &found);
    if (found != NIL) {
        printf("Elemen 'Q' ditemukan, info=%c\n", info(found));
    } else {
        printf("Elemen 'Q' tidak ditemukan.\n");
    }

    // 8. Test UpdateX
    printf("\n TEST UpdateX \n");
    printf("Sebelum UpdateX('A' -> 'M'):");
    PrintList(L);
    UpdateX(&L, 'A', 'M');
    printf("\nSetelah UpdateX('A' -> 'M'):");
    PrintList(L);

    // 9. Test DeleteVFirst
    printf("\n\n TEST DeleteVFirst \n");
    printf("Sebelum DeleteVFirst:");
    PrintList(L);
    DeleteVFirst(&L, &val);
    printf("\nElemen yang dihapus: %c", val);
    printf("\nSetelah DeleteVFirst:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // 10. Test DeleteVLast
    printf("\n TEST DeleteVLast \n");
    printf("Sebelum DeleteVLast:");
    PrintList(L);
    DeleteVLast(&L, &val);
    printf("\nElemen yang dihapus: %c", val);
    printf("\nSetelah DeleteVLast:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // 11. Test DeleteX
    printf("\n TEST DeleteX \n");
    printf("Sebelum DeleteX('M'):");
    PrintList(L);
    DeleteX(&L, 'M');
    printf("\nSetelah DeleteX('M'):");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // 12. Test Invers
    printf("\n TEST Invers \n");
    // Tambah elemen untuk test invers
    InsertVLast(&L, 'P');
    InsertVLast(&L, 'Q');
    InsertVLast(&L, 'R');
    printf("Sebelum Invers:");
    PrintList(L);
    Invers(&L);
    printf("\nSetelah Invers:");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // 13. Test InsertVAfterX
    printf("\n TEST InsertVAfterX \n");
    printf("Sebelum InsertVAfterX('X', 'K'):");
    PrintList(L);
    InsertVAfterX(&L, 'X', 'K');
    printf("\nSetelah InsertVAfterX('X', 'K'):");
    PrintList(L);

    // 14. Test InsertVBeforeX
    printf("\n\n TEST InsertVBeforeX \n");
    printf("Sebelum InsertVBeforeX('Y', 'J'):");
    PrintList(L);
    InsertVBeforeX(&L, 'Y', 'J');
    printf("\nSetelah InsertVBeforeX('Y', 'J'):");
    PrintList(L);

    // 15. Test DeleteVAfterX
    printf("\n\n TEST DeleteVAfterX \n");
    printf("Sebelum DeleteVAfterX('X'):");
    PrintList(L);
    DeleteVAfterX(&L, 'X', &val);
    printf("\nElemen yang dihapus setelah 'X': %c", val);
    printf("\nSetelah DeleteVAfterX('X'):");
    PrintList(L);

    // 16. Test DeleteVBeforeX
    printf("\n\n TEST DeleteVBeforeX \n");
    printf("Sebelum DeleteVBeforeX('Y'):");
    PrintList(L);
    DeleteVBeforeX(&L, 'Y', &val);
    printf("\nElemen yang dihapus sebelum 'Y': %c", val);
    printf("\nSetelah DeleteVBeforeX('Y'):");
    PrintList(L);

    // 17. Test CountX
    printf("\n\n TEST CountX \n");
    // Tambah beberapa elemen duplikat
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'B');
    InsertVLast(&L, 'A');
    InsertVLast(&L, 'C');
    InsertVLast(&L, 'A');
    printf("List saat ini:");
    PrintList(L);
    printf("\nJumlah kemunculan 'A': %d\n", CountX(L, 'A'));
    printf("Jumlah kemunculan 'B': %d\n", CountX(L, 'B'));
    printf("Jumlah kemunculan 'Z': %d\n", CountX(L, 'Z'));

    // 18. Test FrekuensiX
    printf("\n TEST FrekuensiX \n");
    printf("Frekuensi 'A': %.2f\n", FrekuensiX(L, 'A'));
    printf("Frekuensi 'B': %.2f\n", FrekuensiX(L, 'B'));
    printf("Frekuensi 'Z': %.2f\n", FrekuensiX(L, 'Z'));

    // 19. Test MaxMember
    printf("\n TEST MaxMember \n");
    printf("List saat ini:");
    PrintList(L);
    printf("\nJumlah kemunculan huruf yang paling banyak: %d\n", MaxMember(L));

    // 20. Test Modus
    printf("\n TEST Modus \n");
    printf("Huruf yang paling banyak muncul (modus): %c\n", Modus(L));

    // 21. Test CountVocal
    printf("\n TEST CountVocal \n");
    printf("List saat ini:");
    PrintList(L);
    printf("\nJumlah huruf vokal: %d\n", CountVocal(L));

    // 22. Test CountNG
    printf("\n TEST CountNG \n");
    // Buat list baru untuk test NG
    List3 L2;
    CreateList(&L2);
    InsertVLast(&L2, 'M');
    InsertVLast(&L2, 'A');
    InsertVLast(&L2, 'N');
    InsertVLast(&L2, 'G');
    InsertVLast(&L2, 'G');
    InsertVLast(&L2, 'A');
    InsertVLast(&L2, 'N');
    InsertVLast(&L2, 'G');
    printf("List L2:");
    PrintList(L2);
    printf("\nJumlah 'NG': %d\n", CountNG(L2));

    // 23. Test SearchAllX
    printf("\n TEST SearchAllX \n");
    printf("List L saat ini:");
    PrintList(L);
    printf("\nPosisi kemunculan 'A': ");
    SearchAllX(L, 'A');
    printf("\nPosisi kemunculan 'Y': ");
    SearchAllX(L, 'Y');
    printf("\nPosisi kemunculan 'Z': ");
    SearchAllX(L, 'Z');
    printf("\n");

    // 24. Test DeleteAllX
    printf("\n TEST DeleteAllX \n");
    printf("Sebelum DeleteAllX('A'):");
    PrintList(L);
    printf("\nJumlah elemen: %d", NbElm(L));
    DeleteAllX(&L, 'A');
    printf("\nSetelah DeleteAllX('A'):");
    PrintList(L);
    printf("\nJumlah elemen: %d\n", NbElm(L));

    // 25. Test ConcatList
    printf("\n TEST ConcatList \n");
    List3 L3, L4, L5;
    CreateList(&L3);
    CreateList(&L4);
    InsertVLast(&L3, '1');
    InsertVLast(&L3, '2');
    InsertVLast(&L3, '3');
    InsertVLast(&L4, '4');
    InsertVLast(&L4, '5');
    InsertVLast(&L4, '6');
    printf("List L3:");
    PrintList(L3);
    printf("\nList L4:");
    PrintList(L4);
    ConcatList(L3, L4, &L5);
    printf("\nList L5 (hasil concat L3 dan L4):");
    PrintList(L5);
    printf("\nJumlah elemen L5: %d\n", NbElm(L5));

    // 26. Test SplitList
    printf("\n TEST SplitList \n");
    List3 L6, L7;
    printf("List L5 sebelum split:");
    PrintList(L5);
    printf("\nJumlah elemen L5: %d", NbElm(L5));
    SplitList(L5, &L6, &L7);
    printf("\nList L6 (setengah pertama):");
    PrintList(L6);
    printf("\nJumlah elemen L6: %d", NbElm(L6));
    printf("\nList L7 (setengah kedua):");
    PrintList(L7);
    printf("\nJumlah elemen L7: %d\n", NbElm(L7));

    // 27. Test CopyList
    printf("\n TEST CopyList \n");
    List3 L8;
    printf("List L2:");
    PrintList(L2);
    CopyList(L2, &L8);
    printf("\nList L8 (copy dari L2):");
    PrintList(L8);
    printf("\nApakah L2 dan L8 sama? ");
    if (NbElm(L2) == NbElm(L8)) {
        address P1 = First(L2);
        address P2 = First(L8);
        boolean sama = true;
        while (P1 != NIL && P2 != NIL) {
            if (info(P1) != info(P2)) {
                sama = false;
                break;
            }
            P1 = next(P1);
            P2 = next(P2);
        }
        if (sama) {
            printf("Ya, isi sama.\n");
        } else {
            printf("Tidak, isi berbeda.\n");
        }
    } else {
        printf("Tidak, jumlah elemen berbeda.\n");
    }

    return 0;
}