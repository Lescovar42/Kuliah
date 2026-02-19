/* File : pohon3.c */
/* Deskripsi : ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 11 Desember 2025 */
#include "pohon3.h"
#include <stdio.h>
#include <stdlib.h>


/************************ PROTOTYPE ************************/
/********** PEMBUATAN POHON BARU ***********/
/* function Tree3 (A:bintree3, X:infotype, V:boolean, kiri:bintree3, kanan:bintree3)-> bintree3
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
bintree3 Tree3 (bintree3 A, infotype X, boolean V, bintree3 kiri, bintree3 kanan) {
    //kamus lokal
    bintree3 P;
    //algoritma
    P = (bintree3) malloc (sizeof (node3));
    if (P != NIL) {
        info(P) = X;
        visited(P) = V;
        left(P) = kiri;
        right(P) = kanan;
        parent(P) = A;
    }
    return P;
}

/* penelusuran */
/* procedure printDFS( input P:bintree3)
{mencetak node-node P dari elemen terkiri mendalam baru ke kanan} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void printDFS (bintree3 P) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        printf("%c", info(P));
        if (left(P) != NIL || right(P) != NIL) {
            printf("(");
            printDFS(left(P));
            printf(",");
            printDFS(right(P));
            printf(")");
        }
    }
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int Max2 (int a, int b) {
    //kamus lokal

    //algoritma
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:bintree3)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen = 0 }*/
int Tinggi (bintree3 P) {
    //kamus lokal

    //algoritma
    if (P == NIL) {
        return -1;
    } else {
        return 1 + Max2(Tinggi(left(P)), Tinggi(right(P)));
    }
}

/*procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N}*/
void PrintLevel (bintree3 P, int N) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        if (N == 0) {
            printf("%c ", info(P));
        } else {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/* procedure PrintBFS( input P:bintree3)
{mencetak node-node P dari generasi paling terkecil ke terbesar}*/
/*contoh: A B C D */
void PrintBFS (bintree3 P) {
    //kamus lokal

    //algoritma
    int h = Tinggi(P);
    int i;
    for (i = 0; i <= h; i++) {
        PrintLevel(P, i);
    }
}

/****** SELEKTOR *****/
/* menggunakan macro */

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree3) --> boolean 
   {mengembalikan true bila bintree3 L kosong} */
boolean IsEmptyTree (bintree3 P) {
    //kamus lokal

    //algoritma
    return (P == NIL);
}

/* function IsDaun (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun (bintree3 P) {
    //kamus lokal

    //algoritma
    return (P != NIL && left(P) == NIL && right(P) == NIL);
}

/* function IsBiner (P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner (bintree3 P) {
    //kamus lokal

    //algoritma
    return (P != NIL && left(P) != NIL && right(P) != NIL);
}

/* function IsUnerLeft(P:bintree3)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft (bintree3 P) {
    //kamus lokal

    //algoritma
    return (P != NIL && left(P) != NIL && right(P) == NIL);
}

/* function IsUnerRight(P:bintree3)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight (bintree3 P) {
    //kamus lokal

    //algoritma
    return (P != NIL && left(P) == NIL && right(P) != NIL);
}

/*PENELUSURAN*/
/*procedure resetVisited( input/output P : bintree3 )
{I.S: P terdefinisi; F.S: -}
{proses mengubah status visited semua node di P menjadi false}*/
void resetVisited (bintree3 P) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        visited(P) = false;
        resetVisited(left(P));
        resetVisited(right(P));
    }
}

/*procedure printPathX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga node bernilai X }*/
void printPathX (bintree3 P, infotype X) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        printf("%c", info(P));
        if (info(P) != X) {
            if (left(P) != NIL) {
                printf(" ");
                printPathX(left(P), X);
            }
            if (right(P) != NIL) {
                printf(" ");
                printPathX(right(P), X);
            }
        }
    }
}

/*procedure printPathDaunX( input P:bintree3, input X:infotype)
{menampilkan jalur dari akar P hingga daun bernilai X }*/
void printPathDaunX (bintree3 P, infotype X) {
    //kamus lokal

    //algoritma
    if (P != NIL) {
        printf("%c", info(P));
        if (!IsDaun(P) && info(P) != X) {
            if (left(P) != NIL) {
                printf(" ");
                printPathDaunX(left(P), X);
            }
            if (right(P) != NIL) {
                printf(" ");
                printPathDaunX(right(P), X);
            }
        }
    }
}

/*procedure printAllPaths( input P:bintree3)
{menampilkan semua jalur yang mungkin dari akar P hingga setiap daun}*/
void printAllPaths (bintree3 P) {
    //kamus lokal
    
    //algoritma
    if (P != NIL) {
        printf("%c", info(P));
        if (!IsDaun(P)) {
            if (left(P) != NIL) {
                printf(" ");
                printAllPaths(left(P));
            }
            if (right(P) != NIL) {
                printf(" ");
                printAllPaths(right(P));
            }
        }
    }
}

/* function NbElmTree(P:bintree3) --> integer
{ menghitung banyaknya elemen bintree3 P} */
int NbElmTree (bintree3 P) {
    // Kamus lokal

    // Algoritma
    if (P == NIL) {
        return 0;
    } else {
        return 1 + NbElmTree(left(P)) + NbElmTree(right(P));
    }
}

/* function NbDaun(P:bintree3)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun (bintree3 P) {
    // Kamus lokal

    // Algoritma
    if (P == NIL) {
        return 0;
    } else if (IsDaun(P)) {
        return 1;
    } else {
        return NbDaun(left(P)) + NbDaun(right(P));
    }
}

/* function Level(P:bintree3)-> integer
{menghitung tingkat/generasi node pohon P, level akar=1 }*/
int Level (bintree3 P) {
    // Kamus lokal

    // Algoritma
    if (P == NIL) {
        return 0;
    } 
    if (parent(P) == NIL) {
        return 1; 
    } 
    return 1 + Level(parent(P));
}

/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
/*function CountLevelT(P:bintree3, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevelT (bintree3 P, int T) {
    // Kamus lokal

    // Algoritma
    if (P == NIL) {
        return 0;
    }
    if (T < 1) {
        return 0;
    }
    if (T == 1) {
        return 1;
    } else {
        return CountLevelT(left(P), T - 1) + CountLevelT(right(P), T - 1);
    }
}
/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*** operator khusus LIST1 ***/
//printList sudah ADA di List1.h

/*procedure Pconcat( input/output Asli:List1, input Tambahan:List1) */
/*{I.S:- ; F.S: list Asli berubah karena disambung list Tambahan}*/
/*{menyambung list Tambahan ke belakang list Asli}*/
void Pconcat (List1 *Asli, List1 Tambahan) {
    // Kamus Lokal
    address P;
    // Algoritma
    P = First(Tambahan);
    while (P != NIL) {
        InsertVLast(Asli, info(P));
        P = next(P);
    }
}

/*function fconcat( Asli:List1, Tambahan:List1) -> List1 */
/*{membentuk list Baru hasil penyambungan list Tambahan ke belakang list Asli}*/
/*{periksa dampaknya, list Asli tidak boleh berubah }*/
List1 Fconcat (List1 Asli, List1 Tambahan) {
    // Kamus Lokal
    List1 LBaru;
    address P;
    // Algoritma
    CreateList(&LBaru);
    P = First(Asli);
    while (P != NIL) {
        InsertVLast(&LBaru, info(P));
        P = next(P);
    }
    P = First(Tambahan);
    while (P != NIL) {
        InsertVLast(&LBaru, info(P));
        P = next(P);
    }
    
    return LBaru;
}

/*** LINEARISASI POHON ***/
/*function linearPrefix(P:bintree3) -> List1
{menghasilkan list node dari P terurut prefix akar,kiri,kanan}*/
List1 LinearPrefix (bintree3 P) {
    // Kamus Lokal
    List1 L, L_Kiri, L_Kanan;
    
    // Algoritma
    CreateList(&L);
    if (P != NIL) {
        InsertVLast(&L, info(P));
        L_Kiri = LinearPrefix(left(P));
        Pconcat(&L, L_Kiri);
        L_Kanan = LinearPrefix(right(P));
        Pconcat(&L, L_Kanan);
    }
    return L;
}

/*function linearPosfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut posfix kiri,kanan,akar}*/
List1 LinearPosfix (bintree3 P) {
    // Kamus Lokal
    List1 L, L_Kiri, L_Kanan;
    
    // Algoritma
    CreateList(&L);
    if (P != NIL) {
        L_Kiri = LinearPosfix(left(P));
        Pconcat(&L, L_Kiri);
        L_Kanan = LinearPosfix(right(P));
        Pconcat(&L, L_Kanan);
        InsertVLast(&L, info(P));
    }
    return L;
}

/*function linearInfix(P:bintree3) -> List1
{menghasilkan list node dari P terurut infix kiri,akar,kanan}*/
List1 LinearInfix (bintree3 P) {
    // Kamus Lokal
    List1 L, L_Kiri, L_Kanan;
    
    // Algoritma
    CreateList(&L);
    if (P != NIL) {
        L_Kiri = LinearInfix(left(P));
        Pconcat(&L, L_Kiri);
        InsertVLast(&L, info(P));
        L_Kanan = LinearInfix(right(P));
        Pconcat(&L, L_Kanan);
    }
    return L;
}
/*function linearBreadthFS(P:bintree3) -> List1
{menghasilkan list node dari P terurut level/tingkat}*/
List1 LinearBreadthFS (bintree3 P);