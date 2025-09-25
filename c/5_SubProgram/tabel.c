/***************************************************************/
/*                                                             */
/*    Nama File   : tabel.c                                    */
/*    Deskripsi   : Body Abstract Data Type Tabel              */
/*    Pembuat     : Muhammad Fikri - 24060124130069            */
/*							       */
/***************************************************************/

#ifndef TABEL_C
#define TABEL_C

#include "tabel.h"
#include <stdio.h>

/*Body Prototype*/

/***************************************************************/
/*                                                             */
/*                        KONSTRUCTOR                          */
/*                                                             */
/***************************************************************/

void CreateEmpty(TabInt *T)
{
    /* Proses : Mengeset nilai T.Neff dengan nilai 0.              */
    /* I.S : Sembarang.                                            */
    /* F.S : Terbentuk tabel T kosong dengan kapasitas Nmax-Nmin+1.*/

    /*Kamus Lokal*/
    /*Algoritma*/
    (*T).NEff = 0; /*dapat dengan cara T->Neff=0 karena pointer*/
}

/***************************************************************/
/*                                                             */
/*               OPERASI TERHADAP INDEKS TABEL                 */
/*                                                             */
/***************************************************************/

boolean IsIdxValid(TabInt T, IdxType i)
{
    /* Mengirimkan true apabila i merupakan index yang valid bagi  */
    /* TabInt T, yaitu IdxMin <= i <= IdxMax.                      */

    /*Kamus Lokal*/

    /*Algoritma*/
    return (i >= IdxMin && i <= IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i)
{
    /* Mengirimkan true apabila i merupakan indeks yang efektif    */
    /* berisi suatu nilai, yaitu idxmin <= i <= NEff.              */
    /*Kamus Lokal*/

    /*Algoritma*/
    return (i >= IdxMin && i <= T.NEff);
}

/***************************************************************/
/*                                                             */
/*                      PREDIKAT TABEL                         */
/*                                                             */
/***************************************************************/

boolean IsEmpty(TabInt T)
{
    /* Mengirimkan true apabila T merupakan TabInt yang kosong,    */
    /* yaitu apabila T.NEff == 0.                                  */
    /*Kamus Lokal*/

    /*Algoritma*/
    return (T.NEff == 0);
}

boolean IsFull(TabInt T)
{
    /* Mengirimkan true apabila T merupakan TabInt yang penuh,     */
    /* yaitu apabila T.NEff == IdxMax.                             */

    /*Kamus Lokal*/

    /*Algoritma*/
    return (T.NEff == IdxMax);
}

/***************************************************************/
/*                                                             */
/*            BACA TULIS, HUBUNGAN DENGAN I/O DEVICE           */
/*                                                             */
/***************************************************************/

void PrintTabel(TabInt T)
{
    /* Proses : Melakukan traversal sebanyak banyaknya elemen      */
    /*          efektif, dan menuliskan nilainya ke layar.         */
    /* I.S : T boleh kosong.                                       */
    /* F.S : Elemen tabel ditulis ke layar, jika tidak kosong.     */
    /*       jika tabel kosong menampilkan "Tabel Kosong."         */

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    if (T.NEff != 0)
    {
        for (i = IdxMin; i <= T.NEff; i++)
        {
            printf("Data ke-%d : %d\n", i, T.TI[i]);
        }
        /* i > T.NEff */
    }
    else
    {
        printf("Tabel Kosong\n");
    }
}

void IsiTabel(TabInt *T, ElmtType N)
{
    /* Proses : Melakukan traversal sebanyak N untuk mengisi nilai */
    /*          elemen-elemen Tabel T dengan 2 kali indexnya       */
    /* I.S : Sembarang.                                            */
    /* F.S : Tabel T terdefinisi.

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    CreateEmpty(T); /*karena pointer*/
    if (N >= IdxMin && N <= IdxMax)
    {
        for (i = 1; i <= N; i++)
        {
            (*T).TI[i] = 2 * i;
            (*T).NEff = i;
        }
    }
    else
    {
        printf("Harus N>=IdxMin && N<=IdxMax\n");
    }
}

/***************************************************************/
/*                                                             */
/*                        NILAI EKSTRIM                        */
/*                                                             */
/***************************************************************/

ElmtType ValMax(TabInt T)
{
    /* Mengirimkan nilai maksimum TabInt T.                        */
    /* Pre Condition : Tabel tidak kosong.                         */

    /*Kamus Lokasl*/
    ElmtType max; /*nilai maksimum*/
    int i;        /*counter*/

    /*Algoritma*/
    max = T.TI[1];
    for (i = IdxMin + 1; i <= T.NEff; i++)
    {
        if (T.TI[i] > max)
        {
            max = T.TI[i];
        }
    }
    return max;
}

ElmtType ValMin(TabInt T)
{
    /* Mengirimkan nilai minimum TabInt T.                         */
    /* Pre Condition : Tabel tidak kosong.                         */

    /*Kamus Lokal*/
    ElmtType min; /*nilai minimum*/
    int i;        /*counter*/

    /*Algoritma*/
    min = T.TI[1];
    for (i = IdxMin + 1; i <= T.NEff; i++)
    {
        if (T.TI[i] < min)
        {
            min = T.TI[i];
        }
    }
    return min;
}

/***************************************************************/
/*                                                             */
/*                        INDEX NILAI EKSTRIM                  */
/*                                                             */
/***************************************************************/

ElmtType IdxValMax(TabInt T)
{
    /* Mengirimkan index nilai maksimum TabInt T.                  */
    /* Pre Condition : Tabel tidak kosong.                         */

    /*Kamus Lokasl*/
    ElmtType indexMax; /*index nilai maksimum*/
    ElmtType max;      /*nilai maksimum*/
    int i;             /*counter*/

    /*Algoritma*/
    max = T.TI[1];
    indexMax = IdxMin;
    for (i = IdxMin + 1; i <= T.NEff; i++)
    {
        if (T.TI[i] > max)
        {
            max = T.TI[i];
            indexMax = i;
        }
    }
    return indexMax;
}

ElmtType IdxValMin(TabInt T)
{
    /* Mengirimkan index nilai minimum TabInt T.                   */
    /* Pre Condition : Tabel tidak kosong.                         */

    /*Kamus Lokasl*/
    ElmtType indexMin; /*index nilai minimum*/
    ElmtType min;      /*nilai minimum*/
    int i;             /*counter*/

    /*Algoritma*/
    min = T.TI[1];
    indexMin = IdxMin;
    for (i = IdxMin + 1; i <= T.NEff; i++)
    {
        if (T.TI[i] < min)
        {
            min = T.TI[i];
            indexMin = i;
        }
    }
    return indexMin;
}

/***************************************************************/
/*                                                             */
/*                      TUGAS TABELSUBPROGRAM                  */
/*                                                             */
/***************************************************************/

ElmtType NBElmt(TabInt T)
{
    /*Tgl Pembuatan	: 4 April 2025 13.00*/
    /* Mengirimkan banyaknya elemen efektif tabel T, jika T kosong */
    /* maka NBELmt=0                                               */

    /*Kamus Lokal*/

    /*Algoritma*/
    return T.NEff;
}

ElmtType IdxLast(TabInt T)
{
    /*Tgl Pembuatan	: 4 April 2025 13.20*/
    /* Mengirimkan nilai index efektif (NEff) tabel T sebagai   */
    /* elemen terakhir                                          */

    /*Kamus Lokal*/

    /*Algoritma*/
    return T.NEff;
}

boolean IsEqual(TabInt T1, TabInt T2)
{
    /*Tgl Pembuatan	: 4 April 2025 13.40*/
    /* Mengirimkan true apabila ukuran T1 dan T2 sama dan setiap */
    /* elemen T1 dan T2 dengan indeks yang sama bernilai sama    */

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    if (T1.NEff != T2.NEff)
    {
        return false;
    }
    else
    {
        for (i = IdxMin; i <= T1.NEff; i++)
        {
            if (T1.TI[i] != T2.TI[i])
            {
                return false;
            }
        }
        return true;
    }
}

IdxType SearchIdx(TabInt T, ElmtType X)
{
    /*Tgl Pembuatan	: 4 April 2025 14.00*/
    /* Mengirimkan index terkecil di mana ditemukan X dalam T   */
    /* jika tidak ditemuka menghasilkan index tak terdefinisi   */
    /* (-999). Memakai skema search tanpa Boolean               */

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    for (i = IdxMin; i <= T.NEff; i++)
    {
        if (T.TI[i] == X)
        {
            return i;
        }
    }
    return -999;
}

boolean SearchBool(TabInt T, ElmtType X)
{
    /*Tgl Pembuatan	: 4 April 2025 14.20*/
    /* Mengirimkan true apabila X ditemukan dalam T, jika tidak */
    /* ditemukan menghasilkan false.                            */
    /* Memakai skema serach dengan boolean                      */

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    for (i = IdxMin; i <= T.NEff; i++)
    {
        if (T.TI[i] == X)
        {
            return true;
        }
    }
    return false;
}

void CopyTab(TabInt Tin, TabInt *Tout)
{
    /*Tgl Pembuatan	: 4 April 2025 14.40*/
    /* Proses : Menyalin isi Tin ke dalam Tout dengan traversal   */
    /* I.S : Tout sembarang, Tin terdefinisi.                     */
    /* F.S : Tout terdefinisi, sama dengan Tin.                   */

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    CreateEmpty(Tout);
    for (i = IdxMin; i <= Tin.NEff; i++)
    {
        (*Tout).TI[i] = Tin.TI[i];
        (*Tout).NEff = Tin.NEff;
    }
}

boolean IsSimetris(TabInt T)
{
    /*Tgl Pembuatan	: 4 April 2025 15.00*/
    /* Fungsi ini menghasilkan true apabila tabel T merupakan     */
    /* tabel T merupakan tabel yang simetris, yaitu :             */
    /* Elemen pertama sama dengan elemen terakhir,                */
    /* Elemen kedua sama dengan elemen sebelum terakhir dan       */
    /* seterusnya. Jumlah elemen tabel T selalu genap             */

    /*Kamus Lokal*/
    int i; /*counter*/

    /*Algoritma*/
    if (T.NEff % 2 != 0)
    {
        return false;
    }
    else
    {
        for (i = IdxMin; i <= T.NEff; i++)
        {
            if (T.TI[i] != T.TI[T.NEff - i])
            {
                return false;
            }
        }
        return true;
    }
}

// soal uts

void ShiftRight(TabInt *T)
{
    /* Proses : Menggeser elemen-elemen tabel T ke kanan          */
    /*          Elemen pada posisi NEff dipindahkan ke posisi N,  */
    /*          NEff-1 ke N-1, dst. Elemen sisa diisi dengan 0.   */
    /* I.S : T terdefinisi.                                       */
    /* F.S : Elemen tabel T bergeser ke kanan sesuai deskripsi.   */

    /* Kamus Lokal */
    int i;

    /* Algoritma */
    for (i = IdxMax; i > IdxMax - (*T).NEff; i--)
    {
        (*T).TI[i] = (*T).TI[i - (IdxMax - (*T).NEff + 1)];
    }
    for (i = IdxMin; i <= IdxMax - (*T).NEff; i++)
    {
        (*T).TI[i] = 0;
    }
}

void ShiftRightNoPointer(TabInt T, TabInt *TOut)
{
    /* Proses : Menggeser elemen-elemen tabel T ke kanan          */
    /*          Elemen pada posisi NEff dipindahkan ke posisi N,  */
    /*          NEff-1 ke N-1, dst. Elemen sisa diisi dengan 0.   */
    /* I.S : T terdefinisi.                                       */
    /* F.S : Elemen tabel T bergeser ke kanan sesuai deskripsi.   */

    /* Kamus Lokal */
    int i;

    /* Algoritma */
    CreateEmpty(TOut);
    for (i = T.NEff; i >= IdxMin; i--)
    {
        (*TOut).TI[i + 1] = T.TI[i];
    }
    (*TOut).TI[IdxMin] = 0;
    (*TOut).NEff = T.NEff;
}

void ShiftLeft(TabInt *T)
{
    /* Proses : Menggeser elemen-elemen tabel T ke kiri           */
    /*          Elemen pada posisi 1 dipindahkan ke posisi 0,     */
    /*          2 ke 1, dst. Elemen sisa diisi dengan 0.          */
    /* I.S : T terdefinisi.                                       */
    /* F.S : Elemen tabel T bergeser ke kiri sesuai deskripsi.    */

    /* Kamus Lokal */
    int i;

    /* Algoritma */
    for (i = IdxMin; i < (*T).NEff; i++)
    {
        (*T).TI[i] = (*T).TI[i + 1];
    }
    (*T).TI[(*T).NEff] = 0;
}

#endif
