/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 27 November 2025 */
#include "pohon1.h"

/************************ PROTOTYPE ************************/
/*OPERATOR ALOKASI*/
/****************** Manajemen Memori ******************/
/* function AlokasiTree( E: infotype)-> bintree */
/* {menghasilkan alokasi memori pohon dengan info=E, left=NIL, right=NIL  } */
bintree AlokasiTree(infotype E) {
    //kamus lokal
    bintree P;
    //algoritma
    P = (bintree)malloc(sizeof(node));
    if (P != NIL) {
        info(P) = E;
        left(P) = NIL;
        right(P) = NIL;
    }
    return P;
}
 
/* procedure DealokasiTree (input/output P:bintree) */ 
/* {I.S. P terdefinisi 
    F.S. P dikembalikan ke sistem  
	Proses: Melakukan pengembalian bintree P} */
/* procedure DealokasiTree (input/output P:bintree) */ 
void DealokasiTree (bintree *P) {
    //kamus lokal
    
    //algoritma
    free(*P);
    *P = NIL;
}

/********** PEMBUATAN bintree KOSONG ***********/
/* function Tree(Akar:infotype, Left:BinTree, Right:BinTree)-> BinTree
{ Menghasilkan sebuah pohon biner dari Akar, Left, dan Right, jika alokasi berhasil, atau pohon kosong (Nil) jika alokasi gagal }*/
/*representasi logik fungsi*/
bintree Tree (infotype akar, bintree left, bintree right) {
    //kamus lokal
    bintree P;
    //algoritma
    P = AlokasiTree(akar);
    if (P != NIL) {
        left(P) = left;
        right(P) = right;
    }
    return P;
}

/****** SELEKTOR *****/
/*function GetLeft (P : BinTree) -> BinTree
{ Mengirimkan Anak Kiri pohon biner P }*/
bintree GetLeft(bintree P) {
    return left(P);
}

/*function GetRight (P : BinTree) -> BinTree
{ Mengirimkan Anak Kanan pohon biner P }*/
bintree GetRight(bintree P) {
    return right(P);
}

/****************** PREDIKAT ******************/
/* function IsEmptyTree(P:bintree) --> boolean 
   {mengembalikan true bila bintree L kosong} */
boolean IsEmptyTree (bintree P) {
    //kamus lokal
    
    //algoritma
    return ( P == NIL );
}

/* function IsDaun (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong, namun anak kiri dan anak kanan kosong} */
boolean IsDaun(bintree P) {
    //kamus lokal
    
    //algoritma
    return ( !IsEmptyTree(P) && left(P) == NIL && right(P) == NIL );
}

/* function IsBiner (P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan}*/
boolean IsBiner(bintree P) {
    //kamus lokal
    
    //algoritma
    return ( !IsEmptyTree(P) && left(P) != NIL && right(P) != NIL );
}

/* function IsUnerLeft(P:BinTree)-> boolean
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri } */
boolean IsUnerLeft(bintree P) {
    //kamus lokal
    
    //algoritma
    return ( !IsEmptyTree(P) && left(P) != NIL && right(P) == NIL );
}

/* function IsUnerRight(P:BinTree)-> boolean 
{ Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan}*/
boolean IsUnerRight(bintree P) {
    //kamus lokal
    
    //algoritma
    return ( !IsEmptyTree(P) && left(P) == NIL && right(P) != NIL );
}

/*PENELUSURAN*/
/* procedure PrintPrefix(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier lengkap} */
/*contoh: A(B(( ),D(( ),( ))),C(( ),( )))*/
void PrintPrefix(bintree P) {
    //kamus lokal
    
    //algoritma 
    if (P == NIL) {
        printf("()");
    } else {
        printf("%c(",info(P));
        PrintPrefix(left(P));
        printf(",");
        PrintPrefix(right(P));
        printf(")");
    }
}

/* function NbElm(P:bintree) --> integer
{ menghitung banyaknya elemen bintree P} */
int NbElm(bintree P) {
    // Kamus Lokal
    int count;
    // Algoritma
    if (IsEmptyTree(P)) {
        count = 0;
    } else {
        count = 1 + NbElm(left(P)) + NbElm(right(P));
    }
    return count;
}

/* function NbDaun(P:BinTree)-> integer
{ Mengirimkan banyaknya daun (node) pohon biner P }*/
int NbDaun(bintree P) {
    // Kamus Lokal
    int count;
    // Algoritma
    if (IsEmptyTree(P)) {
        count = 0;
    } else if (IsDaun(P)) {
        count = 1;
    } else {
        count = NbDaun(left(P)) + NbDaun(right(P));
    }
    return count;
}

/* function max2(int a, int b)->integer
{mengembalikan nilai maksimal dari a atau b}*/
int max2(int a, int b) {
    if (a >= b) {
        return a;
    } else {
        return b;
    }
}

/* function Tinggi(P:BinTree)-> integer
{menghitung tinggi pohon P, tinggi pohon 1 elemen yaitu 0 }*/
int Tinggi(bintree P) {
    // Kamus Lokal
    int hLeft, hRight;
    // Algoritma
    if (IsEmptyTree(P)) {
        return -1;
    } else {
        hLeft = Tinggi(left(P));
        hRight = Tinggi(right(P));
        return 1 + max2(hLeft, hRight);
    }
}

/*** PENCARIAN ***/
/*function SearchX(P:BinTree, X:infotype) -> boolean 
{ Mengirimkan true jika ada node dari P yang bernilai X }*/
boolean SearchX(bintree P, infotype X) {
    // Kamus Lokal
    
    // Algoritma
    if (IsEmptyTree(P)) {
        return false;
    } else {
        if (info(P) == X) {
            return true;
        } else {
            return ( SearchX(left(P), X) || SearchX(right(P), X) );
        }
    }
}
/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y.
Mengganti elemen bernilai X menjadi Y}*/
void UpdateX(bintree *P, infotype X, infotype Y) {
    if (*P != NIL) {
        if (info(*P) == X) {
            info(*P) = Y;
        } else {
            UpdateX(&left(*P), X, Y);
            UpdateX(&right(*P), X, Y);
        }
    }
}

/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/

/*function CountX(P:BinTree, X:infotype) -> integer 
{ Mengirimkan banyaknya node dari P yang bernilai X }*/
int CountX(bintree P, infotype X) {
    if (IsEmptyTree(P)) return 0;
    return (info(P) == X ? 1 : 0) + CountX(left(P), X) + CountX(right(P), X);
}

/*function IsSkewLeft (P : BinTree)-> boolean 
{ Mengirim true jika P adalah pohon condong kiri } */
boolean IsSkewLeft (bintree P) {
    if (IsEmptyTree(P)) return true;
    if (right(P) != NIL) return false;
    return IsSkewLeft(left(P));
}

/*function IsSkewRight (P : BinTree) -> boolean
{ Mengirim true jika P adalah pohon condong kanan }*/
boolean IsSkewRight (bintree P) {
    if (IsEmptyTree(P)) return true;
    if (left(P) != NIL) return false;
    return IsSkewRight(right(P));
}

/* procedure PrintPrefixRingkas(input P:bintree)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P secara prefix linier ringkas} */
/*contoh: A(B(( ),D),C)*/
void PrintPrefixRingkas(bintree P) {
    if (P == NIL) {
        printf("()");
        return;
    }
    if (IsDaun(P)) {
        printf("%c", info(P));
        return;
    }
    printf("%c(", info(P));
    if (left(P) == NIL) printf("()");
    else PrintPrefixRingkas(left(P));
    printf(",");
    if (right(P) == NIL) printf("()");
    else PrintPrefixRingkas(right(P));
    printf(")");
}

/*function LevelX(P:BinTree, X:infotype)-> integer
{ Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. }*/
int LevelX(bintree P, infotype X) {
    if (IsEmptyTree(P)) return 0; /* not found */
    if (info(P) == X) return 1;
    int lvl = LevelX(left(P), X);
    if (lvl > 0) return 1 + lvl;
    lvl = LevelX(right(P), X);
    if (lvl > 0) return 1 + lvl;
    return 0;
}

/*function CountLevel(P:BinTree, T:integer)-> integer
{ menghitung banyaknya node pada tingkat T. }*/
int CountLevel(bintree P, int T) {
    if (IsEmptyTree(P) || T <= 0) return 0;
    if (T == 1) return 1;
    return CountLevel(left(P), T-1) + CountLevel(right(P), T-1);
}

// /*procedure PrintLevel( input P:bintree, input N: integer )
// {I.S. L terdefinisi; F.S. :-}
// { menampilkan info semua elemen bintree P pada generasi/level N}*/
// void PrintLevel(bintree P, int N) {
//     if (P == NIL || N <= 0) return;
//     if (N == 1) {
//         printf("%c", info(P));
//     } else {
//         PrintLevel(left(P), N-1);
//         PrintLevel(right(P), N-1);
//     }
// }

/*function GetDaunTerkiri(bintree P)-> infotype 
{mengembalikan nilai info daun terkiri, bila tidak ada, hasilnya '#' }*/
infotype GetDaunTerkiri(bintree P) {
    if (IsEmptyTree(P)) return '#';
    bintree cur = P;
    while (!IsDaun(cur)) {
        if (left(cur) != NIL) cur = left(cur);
        else if (right(cur) != NIL) cur = right(cur);
        else break; /* safety */
    }
    return info(cur);
}

/*function FrekuensiX(P:bintree, X:infotype) -> real */
/*{ mengembalikan rasio kemunculan X dibandingkan ukuran bintree P }*/
float FrekuensiX(bintree P, infotype X) {
    int total = NbElm(P);
    if (total == 0) return 0.0f;
    int countX = CountX(P, X);
    return (float)countX / (float)total;
}

/*function CountVocal(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf vokal dalam bintree P}*/
int CountVocal(bintree P) {
    if (IsEmptyTree(P)) return 0;
    char c = info(P);
    int isV = (c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u');
    return (isV?1:0) + CountVocal(left(P)) + CountVocal(right(P));
}

/*procedure PrintVocal( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf vokal dalam bintree P}*/
void PrintVocal(bintree P) {
    if (P == NIL) return;
    char c = info(P);
    if (c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u') {
        printf("%c", c);
    }
    PrintVocal(left(P));
    PrintVocal(right(P));
}

/*function CountConsonant(P:bintree) -> integer */
/*{ mengembalikan banyaknya kemunculan huruf konsonan dalam bintree L}*/
int CountConsonant(bintree P) {
    if (IsEmptyTree(P)) return 0;
    char c = info(P);
    int isLetter = ((c>='A' && c<='Z') || (c>='a' && c<='z'));
    int isV = (c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u');
    int isCons = (isLetter && !isV);
    return (isCons?1:0) + CountConsonant(left(P)) + CountConsonant(right(P));
}

/*procedure PrintConsonant( input P:bintree) */
/*{ I.S.: P terdefinisi; F.S.: -
Proses: menampilkan semua huruf konsonan dalam bintree P}*/
void PrintConsonant(bintree P) {
    if (P == NIL) return;
    char c = info(P);
    int isLetter = ((c>='A' && c<='Z') || (c>='a' && c<='z'));
    int isV = (c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u');
    if (isLetter && !isV) printf("%c", c);
    PrintConsonant(left(P));
    PrintConsonant(right(P));
}

/*function Modus(P:bintree) -> character */
/*{ mengembalikan huruf yang paling banyak muncul dalam bintree L}*/
char Modus(bintree P) {
    if (IsEmptyTree(P)) return '#';
    char modus = info(P);
    int max = CountX(P, modus);

    /* traverse tree and check counts of each node value */
    if (left(P) != NIL) {
        char mleft = Modus(left(P));
        if (mleft != '#') {
            int c = CountX(P, mleft);
            if (c > max) { max = c; modus = mleft; }
        }
    }
    if (right(P) != NIL) {
        char mright = Modus(right(P));
        if (mright != '#') {
            int c = CountX(P, mright);
            if (c > max) { max = c; modus = mright; }
        }
    }
    return modus;
}