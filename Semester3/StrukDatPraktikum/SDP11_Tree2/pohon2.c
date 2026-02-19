/* File : pohon2.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* pohon2 melengkapi operator ADT bintree yang ada dalam pohon1 */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 4 Desember 2025 */

#include "pohon2.h"

/*PENELUSURAN*/
/* procedure PrintTreeInden (input P : BinTree, input H : integer)
{ I.S. P terdefinisi, h adalah jarak indentasi subpohon }
{ F.S. Semua simpul P ditulis dengan indentasi berjenjang,mirip file explorer} */
void PrintTreeInden(bintree P, int H ) {
    if (P != NIL) {
        int i;
        for (i = 0; i < H; i++) {
            printf(" ");
        }
        printf("%c\n", info(P));
        PrintTreeInden(left(P), H + 1);
        PrintTreeInden(right(P), H + 1);
    }
}

/* procedure PrintLevel(input P:bintree, input N:integer)
{I.S. L terdefinisi; F.S. :-}
{ menampilkan info semua elemen bintree P pada generasi/level N} */
void PrintLevel(bintree P, int N) {
    if (P != NIL) {
        if (N == 1) {
            printf("%c ", info(P));
        } else if (N > 1) {
            PrintLevel(left(P), N - 1);
            PrintLevel(right(P), N - 1);
        }
    }
}

/*** MANIPULASI ELEMEN bintree ***/
/*Procedure UpdateAllX(input/output P:bintree, input X:infotype, input Y:infotype)
{ I.S. L, X, Y terdefinisi }
{ F.S. L tetap, atau elemen bernilai X berubah menjadi Y. Mengganti semua elemen bernilai X menjadi Y}*/
void UpdateAllX(bintree *P, infotype X, infotype Y) {
    if (*P != NIL) {
        if (info(*P) == X) {
            info(*P) = Y;
        }
        UpdateAllX(&left(*P), X, Y);
        UpdateAllX(&right(*P), X, Y);
    }
}

/******* PENAMBAHAN ELEMEN bintree ********/
/*procedure AddDaunTerkiri (input/output P : BinTree, input X : infotype)
{ I.S. P boleh kosong }
{ F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri }*/
void AddDaunTerkiri(bintree *P, infotype X) {
    if (*P == NIL) {
        *P = AlokasiTree(X);
    } else {
        AddDaunTerkiri(&left(*P), X);
    }
}

/*procedure AddDaun (input/Output P : BinTree, input X, Y : infotype, input Kiri : boolean)
{ I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P }
{ F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai anak Kanan X (jika not Kiri) }*/
void AddDaun(bintree *P, infotype X, infotype Y, boolean Kiri) {
    if (*P != NIL) {
        if (info(*P) == X && IsDaun(*P)) {
            if (Kiri) left(*P) = AlokasiTree(Y);
            else right(*P) = AlokasiTree(Y);
        } else {
            AddDaun( &left(*P), X, Y, Kiri);
            AddDaun( &right(*P), X, Y, Kiri);
        }
    }
}

/*procedure InsertX (input/output P : BinTree, input X : infotype)
{ Menghasilkan sebuah pohon P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
void InsertX(bintree *P, infotype X) {
    if (*P == NIL) {
        *P = AlokasiTree(X);
    } else {
        if (left(*P) == NIL) {
            left(*P) = AlokasiTree(X);
        } else if (right(*P) == NIL) {
            right(*P) = AlokasiTree(X);
        } else {
            InsertX(&left(*P), X);
        }
    }
}

/******* PENGHAPUSAN ELEMEN ********/
/*procedure DelDaunTerkiri (input/output P : BinTree, output X : infotype)
{ I.S. P tidak kosong }
{ F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang
semula disimpan pada daun terkiri yang dihapus }*/
void DelDaunTerkiri(bintree *P, infotype *X) {
    if (*P != NIL) {
        if (IsDaun(*P)) {
            *X = info(*P);
            DealokasiTree(P);
        } else {
            DelDaunTerkiri(&left(*P), X);
        }
    }
}

/*procedure DelDaun (input/output P : BinTree, input X : infotype)
{ I.S. P tidak kosong, X adalah salah satu daun }
{ F.S. X dihapus dari P }*/
void DelDaun(bintree *P, infotype X) {
    if (*P != NIL) {
        if (IsDaun(*P) && info(*P) == X) {
            DealokasiTree(P);
        } else {
            DelDaun(&left(*P), X);
            DelDaun(&right(*P), X);
        }
    }
}

/*procedure DeleteX (input/output P : BinTree, input X : infotype)
{ Menghapus simpul bernilai X bila ada dari P, HATI-HATI! }*/
void DeleteX(bintree *P, infotype X) {
    if (*P != NIL) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                DealokasiTree(P);
            } else if (IsUnerLeft(*P)) {
                bintree temp = *P;
                *P = left(*P);
                DealokasiTree(&temp);
            } else if (IsUnerRight(*P)) {
                bintree temp = *P;
                *P = right(*P);
                DealokasiTree(&temp);
            } else {
                infotype minRight = GetDaunTerkiri(right(*P));
                info(*P) = minRight;
                DeleteX(&right(*P), minRight);
            }
        } else {
            DeleteX(&left(*P), X);
            DeleteX(&right(*P), X);
        }
    }
}
/*********** SOAL TAMBAHAN, DIKERJAKAN BILA LUANG *****************/
/*KONSTRUKTOR*/
/*function BuildBalanceTree (n : integer) -> BinTree
{ Menghasilkan balanced tree dengan n node, nilai setiap node dibaca dari keyboard }*/
bintree BuildBalanceTree(int n) {
    /* Kamus Lokal */
    bintree P;
    infotype X;
    int nLeft, nRight;

    /* Algoritma */
    if (n <= 0) {
        return NIL;
    } else {
        nLeft = n / 2;
        nRight = n - nLeft - 1;
        printf("Masukkan node (char): ");
        if (scanf(" %c", &X) != 1) return NIL;
        P = AlokasiTree(X);
        if (P != NIL) {
            left(P) = BuildBalanceTree(nLeft);
            right(P) = BuildBalanceTree(nRight);
        }
        return P;
    }
}

/*PREDIKAT*/
/*function IsBalanceTree (P : BinTree) -> boolean
{ Menghasilkan true jika P seimbang, banyak node kiri ~= kanan }*/
boolean IsBalanceTree(bintree P) {
    /* Kamus Lokal */
    int nL, nR;

    /* Algoritma */
    if (IsEmptyTree(P)) {
        return true;
    } else {
        nL = NbElm(left(P));
        nR = NbElm(right(P));
        return (abs(nL - nR) <= 1) && IsBalanceTree(left(P)) && IsBalanceTree(right(P));
    }
}

/* function maxTree(P:bintree)->character
{mengembalikan huruf "maksimal" dari elemen P, A<B<C<..<Z }*/
infotype maxTree(bintree P) {
    /* Kamus Lokal */
    infotype maxVal, tempVal;

    /* Algoritma */
    if (IsEmptyTree(P)) {
        /* Kembalikan karakter dengan nilai ASCII rendah jika pohon kosong */
        return 0; 
    }

    maxVal = info(P);

    /* Cek Subpohon Kiri */
    if (left(P) != NIL) {
        tempVal = maxTree(left(P));
        if (tempVal > maxVal) {
            maxVal = tempVal;
        }
    }

    /* Cek Subpohon Kanan */
    if (right(P) != NIL) {
        tempVal = maxTree(right(P));
        if (tempVal > maxVal) {
            maxVal = tempVal;
        }
    }

    return maxVal;
}

/* function minTree(P:bintree)->character
{mengembalikan huruf "minimal" dari elemen P, A<B<C<..<Z }*/
infotype minTree(bintree P) {
    /* Kamus Lokal */
    infotype minVal, tempVal;

    /* Algoritma */
    if (IsEmptyTree(P)) {
        return 0; 
    }

    minVal = info(P);

    if (left(P) != NIL) {
        tempVal = minTree(left(P));
        if (tempVal < minVal) {
            minVal = tempVal;
        }
    }

    if (right(P) != NIL) {
        tempVal = minTree(right(P));
        if (tempVal < minVal) {
            minVal = tempVal;
        }
    }

    return minVal;
}
/*{ Operator KHUSUS Binary Search Tree, node kiri selalu lebih kecil daripada node kanan }

/*function BSearch (P : BinTree, X : infotype) → boolean
{ Mengirimkan true jika ada node dari pohon binary search P yang bernilai X }*/
boolean BSearch(bintree P, infotype X) {
    /* Kamus Lokal */

    /* Algoritma */
    if (P == NIL) {
        return false;
    } else {
        if (info(P) == X) {
            return true;
        } else if (X < info(P)) {
            return BSearch(left(P), X);
        } else {
            return BSearch(right(P), X);
        }
    }
}

/*function InsSearch (P : BinTree, X : infotype) → BinTree
{ Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang bernilai X. }*/
bintree InsSearch(bintree P, infotype X) {
    /* Kamus Lokal */
    bintree NewNode;

    /* Algoritma */
    if (P == NIL) {
        NewNode = AlokasiTree(X);
        return NewNode;
    } else {
        if (X < info(P)) {
            left(P) = InsSearch(left(P), X);
        } else {
            right(P) = InsSearch(right(P), X);
        }
        return P;
    }
}

/*procedure DelBtree (input/output P : BinTree, input X : infotype)
{ I.S. Pohon binary search P tidak kosong }
{ F.S. Nilai X yang dihapus pasti ada }
{ Sebuah node dg nilai X dihapus }*/
void DelBtree(bintree *P, infotype X) {
    if (*P != NIL) {
        if (info(*P) == X) {
            if (IsDaun(*P)) {
                DealokasiTree(P);
            } else if (IsUnerLeft(*P)) {
                bintree temp = *P;
                *P = left(*P);
                DealokasiTree(&temp);
            } else if (IsUnerRight(*P)) {
                bintree temp = *P;
                *P = right(*P);
                DealokasiTree(&temp);
            } else {
                infotype minRight = GetDaunTerkiri(right(*P));
                info(*P) = minRight;
                DelBtree(&right(*P), minRight);
            }
        } else if (X < info(*P)) {
            DelBtree(&left(*P), X);
        } else {
            DelBtree(&right(*P), X);
        }
    }
}