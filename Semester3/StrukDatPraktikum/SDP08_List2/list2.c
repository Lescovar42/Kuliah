/* File : list2.c */
/* Deskripsi : realisasi body ADT list berkait representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 13 November 2025 */

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "list2.h" 

/* Function Alokasi(E:infotype)->address
{mengembalikan alamat elemen E} */
address Alokasi(infotype E) {
    //kamus lokal
    address P;
    //algoritma 
    P = (address) malloc(sizeof(Elm2)); //casting
    if (P != NULL ) {
        info(P) = E;
        next(P) = NIL;
    }
    return P;
}
/* procedure Dealokasi (input/output P:address) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian address P} */
void Dealokasi (address *P) {
    //kamus lokal
    
    //algoritma
    if ( P != NIL ) {
        next(*P) = NIL;
    }
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN LIST KOSONG ***********/
/* Procedure CreateList(output L:List2)
   {I.S.: - ; F.S.: L list kosong} 
   {proses: membuat list kosong}*/
void CreateList (List2 *L) {
    //kamus lokal
    
    //algoritma
    First(*L) = NIL;
}

/****************** TEST KONDISI LIST ******************/
/* function IsEmptyList(L:List2) --> boolean 
   {mengembalikan true bila list L kosong} */
boolean IsEmptyList (List2 L) {
    //kamus lokal
    
    //algoritma
    return ( First(L) == NIL );
}

/* function IsOneElm(L:List2) --> boolean 
   {mengembalikan true bila list L hanya punya satu elemen} */
boolean IsOneElm (List2 L) {
    //kamus lokal
    
    //algoritma
    return ( !IsEmptyList(L) && next(First(L)) == First(L) );
}

/*********** PENELUSURAN ***********/
/*procedure PrintList(input L:List2)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen list L} */
void PrintList(List2 L) {
	//kamus lokal
	address P;
	//algoritma
	P = First(L);
	if (P != NIL) {
		printf("\nElemen = ");
		do {
			printf("\t%c", info(P));
			P = next(P);
		} while( P != First(L) );
	}
}

/*function NbElm(L:List2) --> integer
{ menghitung banyaknya elemen list L} */
int NbElm(List2 L) {
    // Kamus Lokal
    address P;
    int count;
    // Algoritma
    count = 0;
    P = First(L);
    if (P != NIL) {
        do {
            count++;
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/******* PENAMBAHAN ELEMEN LIST ********/
/* Procedure InsertVFirst(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen pertama berinfo V }
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen pertama list linier L yg mungkin kosong } */
void InsertVFirst(List2 *L, infotype V ) {
    //Kamus Lokal
    address P;
    address Last;
    //Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = First(*L);
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(P) = First(*L);
            First(*L) = P;
            next(Last) = First(*L);
        }
    }
}

/*Procedure InsertVLast(input/output L:List2, input V:infotype )
{ I.S. List L mungkin kosong, V terdefinisi }
{ F.S. L tetap, atau bertambah elemen terakhir berinfo V, next(P)=First(L)}
{ Proses: Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen akhir list linier L yg mungkin kosong }*/
void InsertVLast(List2 *L, infotype V ) {
    // Kamus Lokal
    address P;
    address Last;
    // Algoritma
    P = Alokasi(V);
    if (P != NIL) {
        if (IsEmptyList(*L)) {
            First(*L) = P;
            next(P) = First(*L);
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            next(Last) = P;
            next(P) = First(*L);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*Procedure DeleteVFirst(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen pertama list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen pertama list yang baru adalah elemen sesudah elemen pertama yang lama. } */
void DeleteVFirst(List2 *L, infotype *V) {
    // Kamus Lokal
    address P;
    address Last;
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        *V = info(P);
        if (next(P) == First(*L)) { //hanya satu elemen
            First(*L) = NIL;
            Dealokasi(&P);
        } else {
            Last = First(*L);
            while (next(Last) != First(*L)) {
                Last = next(Last);
            }
            First(*L) = next(P);
            next(Last) = First(*L);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteVLast(input/output L:List2, output V:infotype )
{ I.S. List L terdefinisi }
{ F.S. Elemen terakhir list L dihapus dan didealokasi. Nilai penghapusan disimpan dalam V. Default V='#'.
List mungkin menjadi kosong. Jika tidak kosong, elemen terakhir list yang baru adalah elemen sebelum elemen terakhir yang lama. }*/
void DeleteVLast(List2 *L, infotype *V) {
    // Kamus Lokal
    address P;
    address Q;
    // Algoritma
    if (!IsEmptyList(*L)) {
        if (next(First(*L)) == First(*L)) { //hanya satu elemen
            P = First(*L);
            *V = info(P);
            First (*L) = NIL;
            Dealokasi(&P);
        } 
        else {
            Q = First(*L);
            while (next(next(Q)) != First(*L)) {
                Q = next(Q);
            }
            P = next(Q);
            *V = info(P);
            next(Q) = First(*L);
            Dealokasi(&P);
        }
    }
}

/*Procedure DeleteX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Elemen bernilai X dihapus, dan didealokasi. 
List mungkin menjadi kosong. }*/
void DeleteX(List2 *L, infotype X) {
    // Kamus Lokal
    address P;
    address Q;
    // Algoritma
    if (!IsEmptyList(*L)) {
        // Jika elemen pertama yang akan dihapus
        if (info(First(*L)) == X) {
            infotype dummy;
            DeleteVFirst(L, &dummy);
        } 
        else {
            Q = First(*L);
            P = next(Q);
            while (P != First(*L)) {
                if (info(P) == X) {
                    next(Q) = next(P);
                    Dealokasi(&P);
                    break;
                }
                Q = P;
                P = next(P);
            }
        }
    }
}

/*** PENCARIAN ***/
/*Procedure SearchX(input L:List2, input X:infotype, output A:address )
{ I.S. L, X terdefinisi }
{ F.S. A berisi alamat elemen yang nilainya X.
Mencari apakah ada elemen list dengan info(P)= X. Jika ada, mengisi A dengan address elemen tersebut. Jika tidak ada, A=Nil }*/
void SearchX(List2 L, infotype X, address *A) {
    // Kamus Lokal
    address P;
    //Algoritma
    P = First(L);
    *A = NIL;
    if (P != NIL) {
        do {
            if (info(P) == X) {
                *A = P;
                break;
            }
            P = next(P);
        } while (P != First(L));
    }
}

/*** MANIPULASI ELEMEN LIST ***/
/*Procedure UpdateX(input/output L:List2, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi bernilai Y}*/
void UpdateX(List2 *L, infotype X, infotype Y) {
    // Kamus Lokal
    address P;
    // Algoritma
    if (!IsEmptyList(*L)) {
        P = First(*L);
        do {
            if (info(P) == X) {
                info(P) = Y;
                break;
            }
            P = next(P);
        } while (P != First(*L));
    }
}

/*Procedure Invers(input/output L:List2)
{ I.S. L terdefinisi }
{ F.S. urutan posisi elemen terbalik,
misal {'A','B','C'} menjadi {'C','B','A'} }*/
void Invers(List2 *L) {
    // Kamus Lokal
    address P, Prev, Temp;
    // Algoritma
    if (!IsEmptyList(*L) && !IsOneElm(*L)) {
        Prev = First(*L);
        P = next(First(*L));

        do {
            Temp = next(P);
            next(P) = Prev;
            Prev = P;
            P = Temp;
        } while (P != First(*L));

        next(First(*L)) = Prev;
        First(*L) = Prev;
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(L:List2, X:infotype) -> integer */
/*{ mengembalikan banyaknya kemunculan X dalam list L}*/
int CountX(List2 L, infotype X) {
    // Kamus Lokal
    address P;
    int count;
    // Algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if (info(P) == X) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function FrekuensiX(L:List2, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran list L }*/
float FrekuensiX(List2 L, infotype X) {
    // Kamus Lokal
    int total;
    int countX;
    // Algoritma
    total = NbElm(L);
    if (total == 0) {
        return 0.0;
    }
    countX = CountX(L, X);
    return (float)countX / (float)total;
}

/*function CountVocal(L:List2) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam list L}*/
int CountVocal(List2 L) {
    // Kamus Lokal
    address P;
    int count;
    char c;
    // Algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            c = info(P);
            if (c == 'A' || c == 'a' || c == 'E' || c == 'e' ||
                c == 'I' || c == 'i' || c == 'O' || c == 'o' ||
                c == 'U' || c == 'u') {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*function CountNG(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf N yang langsung diikuti huruf G dalam list L}*/
int CountNG(List2 L) {
    // Kamus Lokal
    address P;
    int count;
    // Algoritma
    count = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            if ((info(P) == 'N' || info(P) == 'n') &&
                (info(next(P)) == 'G' || info(next(P)) == 'g')) {
                count++;
            }
            P = next(P);
        } while (P != First(L));
    }
    return count;
}

/*Procedure InsertVAfterX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi setelah elemen bernilai X }*/
void InsertVAfterX(List2 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P, Q;
    // Algoritma
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &Q);
        if (Q != NIL) {
            P = Alokasi(V);
            if (P != NIL) {
                next(P) = next(Q);
                next(Q) = P;
            }
        }
    }
}

/*Procedure InsertVBeforeX(input/output L:List2, input X:infotype, input V:infotype )
{ I.S. List L mungkin kosong }
{ F.S. P dialokasi, Info(P)=V }
{ Insert sebuah elemen beralamat P dengan Info(P)=V sebagai elemen dengan posisi sebelum elemen bernilai X }*/
void InsertVBeforeX(List2 *L, infotype X, infotype V) {
    // Kamus Lokal
    address P, Q, Prec;
    // Algoritma
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &Q);
        if (Q != NIL) {
            P = Alokasi(V);
            if (P != NIL) {
                if (Q == First(*L)) {
                    InsertVFirst(L, V);
                    Dealokasi(&P);
                } else {
                    Prec = First(*L);
                    while (next(Prec) != Q) {
                        Prec = next(Prec);
                    }
                    next(P) = Q;
                    next(Prec) = P;
                }
            }
        }
    }
}

/*Procedure DeleteVAfterX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen setelah X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVAfterX(List2 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address Q, P;
    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &Q);
        if (Q != NIL) {
            P = next(Q);
            *V = info(P);
            if (P == First(*L)) {
                DeleteVFirst(L, V);
            } else {
                next(Q) = next(P);
                Dealokasi(&P);
            }
        }
    }
}

/*Procedure DeleteVBeforeX(input/output L:List2, input X:infotype, output V:infotype )
{ I.S. List L tidak kosong }
{ F.S. Elemen sebelum X dihapus, dan didealokasi. Hasil penghapusan disimpan nilainya dalam V.
List mungkin menjadi kosong. }*/
void DeleteVBeforeX(List2 *L, infotype X, infotype *V) {
    // Kamus Lokal
    address Q, P, Prec;
    // Algoritma
    *V = '#';
    if (!IsEmptyList(*L)) {
        SearchX(*L, X, &Q);
        if (Q != NIL) {
            Prec = First(*L);
            while (next(Prec) != Q) {
                Prec = next(Prec);
            }
            P = Prec;
            *V = info(P);
            if (P == First(*L)) {
                DeleteVFirst(L, V);
            } else {
                Prec = First(*L);
                while (next(Prec) != P) {
                    Prec = next(Prec);
                }
                next(Prec) = Q;
                Dealokasi(&P);
            }
        }
    }
}

/*Procedure DeleteAllX(input/output L:List2, input X:infotype)
{ I.S. List L tidak kosong }
{ F.S. Semua elemen bernilai X dihapus, dan didealokasi.
List mungkin menjadi kosong. }*/
void DeleteAllX(List2 *L, infotype X) {
    // Kamus Lokal
    address P;
    infotype dummy;
    // Algoritma
    if (!IsEmptyList(*L)) {
        do {
            P = First(*L);
            if (info(P) == X) {
                DeleteVFirst(L, &dummy);
            } else {
                P = next(P);
                while (P != First(*L)) {
                    if (info(P) == X) {
                        DeleteX(L, X);
                        break;
                    }
                    P = next(P);
                }
            }
        } while (!IsEmptyList(*L) && CountX(*L, X) > 0);
    }
}

/*Procedure SearchAllX(input L:List2, input X:infotype)
{ I.S. L, X terdefinisi }
{ F.S. -
Proses: menampilkan posisi-posisi kemunculan elemen X dalam list L }*/
/*misal L=['M','A','N','D','A'], SearchAllX(L,'A') menampilkan angka 2,5 */
/*misal L=['M','A','N','D','A'], SearchAllX(L,'J') menampilkan angka 0 */
void SearchAllX(List2 L, infotype X) {
    // Kamus Lokal
    address P;
    int pos, found;
    // Algoritma
    found = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        pos = 1;
        do {
            if (info(P) == X) {
                if (found == 0) {
                    printf("%d", pos);
                } else {
                    printf(",%d", pos);
                }
                found = 1;
            }
            P = next(P);
            pos++;
        } while (P != First(L));
    }
    if (found == 0) {
        printf("0");
    }
}

/*function MaxMember(L:List2) -> integer */
/*{ mengembalikan banyaknya huruf yang paling banyak muncul di list L}*/
int MaxMember(List2 L) {
    // Kamus Lokal
    address P;
    int max, count;
    // Algoritma
    max = 0;
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            count = CountX(L, info(P));
            if (count > max) {
                max = count;
            }
            P = next(P);
        } while (P != First(L));
    }
    return max;
}

/*function Modus(L:List2) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam list L}*/
char Modus(List2 L) {
    // Kamus Lokal
    address P;
    int max, count;
    char modus;
    // Algoritma
    max = 0;
    modus = '\0';
    if (!IsEmptyList(L)) {
        P = First(L);
        do {
            count = CountX(L, info(P));
            if (count > max) {
                max = count;
                modus = info(P);
            }
            P = next(P);
        } while (P != First(L));
    }
    return modus;
}

/*OPERASI BANYAK LIST*/
/*Procedure ConcatList(input L1:List2, input L2:List2, output L:List2)
{I.S.: L1,L2 terdefinisi ;
 F.S.: L gabungan L1 dan L2}*/
void ConcatList(List2 L1, List2 L2, List2 *L) {
    // Kamus Lokal
    address P;
    // Algoritma
    CreateList(L);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L1));
    }
    if (!IsEmptyList(L2)) {
        P = First(L2);
        do {
            InsertVLast(L, info(P));
            P = next(P);
        } while (P != First(L2));
    }
}

/*Procedure SplitList(input L:List2, output L1:List2, output L2:List2)
{I.S.: L terdefinisi ;
 F.S.: L1, L2 hasil pemecahan L}*/
void SplitList(List2 L, List2 *L1, List2 *L2) {
    // Kamus Lokal
    address P;
    int count, i;
    int mid;
    // Algoritma
    CreateList(L1);
    CreateList(L2);
    if (!IsEmptyList(L)) {
        count = NbElm(L);
        mid = (count + 1) / 2;
        P = First(L);
        i = 1;
        do {
            if (i <= mid) {
                InsertVLast(L1, info(P));
            } else {
                InsertVLast(L2, info(P));
            }
            P = next(P);
            i++;
        } while (P != First(L));
    }
}

/*Procedure CopyList(input L1:List2, output L2:List2)
{I.S.: L1 terdefinisi;
 F.S.: L2 menjadi salinan L1}*/
void CopyList(List2 L1, List2 *L2) {
    // Kamus Lokal
    address P;
    // Algoritma
    CreateList(L2);
    if (!IsEmptyList(L1)) {
        P = First(L1);
        do {
            InsertVLast(L2, info(P));
            P = next(P);
        } while (P != First(L1));
    }
}