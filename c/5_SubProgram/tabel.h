/***************************************************************/
/*                                                             */
/*    Nama File   : tabel.h                                    */
/*    Deskripsi   : Header Abstract Data Type Tabel            */
/*    Pembuat     : Muhammad Fikri - 24060124130069	       */
/*                                                             */
/***************************************************************/

#ifndef TABEL_H
#define TABEL_H

#include "boolean.h"

#define IdxMax 100
#define IdxMin 1

typedef int ElmtType;
typedef int IdxType;
typedef struct
{
    ElmtType TI[IdxMax - IdxMin + 1]; /*Tabel*/
    int NEff;                         /*Indek efektif Tabel*/
} TabInt;

/*Prototype*/

/***************************************************************/
/*                                                             */
/*                        KONSTRUCTOR                          */
/*                                                             */
/***************************************************************/

void CreateEmpty(TabInt *T);
/* Proses : Mengeset nilai T.Neff dengan nilai 0.              */
/* I.S : Sembarang.                                            */
/* F.S : Terbentuk tabel T kosong dengan kapasitas Nmax-Nmin+1.*/

/***************************************************************/
/*                                                             */
/*               OPERASI TERHADAP INDEKS TABEL                 */
/*                                                             */
/***************************************************************/

boolean IsIdxValid(TabInt T, IdxType i);
/* Mengirimkan true apabila i merupakan index yang valid bagi  */
/* TabInt T, yaitu IdxMin <= i <= IdxMax.                      */

boolean IsIdxEff(TabInt T, IdxType i);
/* Mengirimkan true apabila i merupakan indeks yang efektif    */
/* berisi suatu nilai, yaitu idxmin <= i <= NEff.              */

/***************************************************************/
/*                                                             */
/*                      PREDIKAT TABEL                         */
/*                                                             */
/***************************************************************/

boolean IsEmpty(TabInt T);
/* Mengirimkan true apabila T merupakan TabInt yang kosong,    */
/* yaitu apabila T.NEff == 0.                                  */

boolean IsFull(TabInt T);
/* Mengirimkan true apabila T merupakan TabInt yang penuh,     */
/* yaitu apabila T.NEff == IdxMax.                             */

/***************************************************************/
/*                                                             */
/*            ISI TULIS, HUBUNGAN DENGAN I/O DEVICE            */
/*                                                             */
/***************************************************************/

void PrintTabel(TabInt T);
/* Proses : Melakukan traversal sebanyak banyaknya elemen      */
/*          efektif, dan menuliskan nilainya ke layar.         */
/* I.S : T boleh kosong.                                       */
/* F.S : Elemen tabel ditulis ke layar, jika tidak kosong.     */
/*       jika tabel kosong menampilkan "Tabel Kosong."         */

void IsiTabel(TabInt *T, ElmtType N);
/* Proses : Melakukan traversal sebanyak N untuk mengisi nilai */
/*          elemen-elemen Tabel T dengan 2 kali indexnya       */
/* I.S : Sembarang.                                            */
/* F.S : Tabel T terdefinisi.                                  */

/***************************************************************/
/*                                                             */
/*                        NILAI EKSTRIM                        */
/*                                                             */
/***************************************************************/

ElmtType ValMax(TabInt T);
/* Mengirimkan nilai maksimum TabInt T.                        */
/* Pre Condition : Tabel tidak kosong.                         */

ElmtType ValMin(TabInt T);
/* Mengirimkan nilai minimum TabInt T.                         */
/* Pre Condition : Tabel tidak kosong.                         */

/***************************************************************/
/*                                                             */
/*                        INDEX NILAI EKSTRIM                  */
/*                                                             */
/***************************************************************/

ElmtType IdxValMax(TabInt T);
/* Mengirimkan index nilai maksimum TabInt T.                  */
/* Pre Condition : Tabel tidak kosong.                         */

ElmtType IdxValMin(TabInt T);
/* Mengirimkan index nilai minimum TabInt T.                   */
/* Pre Condition : Tabel tidak kosong.                         */

/***************************************************************/
/*                                                             */
/*                      TUGAS TABELSUBPROGRAM                  */
/*                                                             */
/***************************************************************/

ElmtType NBElmt(TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel T, jika T kosong */
/* maka NBELmt=0                                               */

ElmtType IdxLast(TabInt T);
/* Mengirimkan index elemen terakhir tabel T.                  */

boolean IsEqual(TabInt T1, TabInt T2);
/* Mengirimkan true apabila T1=T2, yaitu apabila semua elemen  */
/* T1 sama dengan T2, dan ukuran tabel T1=T2.                  */

IdxType SearchIdx(TabInt T, ElmtType X);
/* Mengirimkan index terkecil di mana ditemukan X dalam T      */
/* jika tidak ditemuka menghasilkan index tak terdefinisi      */

boolean SearchBool(TabInt T, ElmtType X);
/* Mengirimkan true apabila X ditemukan dalam T, jika tidak    */
/* ditemukan menghasilkan false.                               */
/* Memakai skema serach dengan boolean                         */

void CopyTab(TabInt Tin, TabInt *Tout);
/* Proses : Menyalin isi Tin ke dalam Tout dengan traversal    */
/* I.S : Tout sembarang, Tin terdefinisi.                      */

boolean IsSimetris(TabInt T);
/* Fungsi ini menghasilkan true apabila tabel T merupakan      */
/* tabel T merupakan tabel yang simetris, yaitu :              */
/* Elemen pertama sama dengan elemen terakhir,                 */
/* Elemen kedua sama dengan elemen sebelum terakhir dan        */
/* seterusnya. Jumlah elemen tabel T selalu genap              */

#endif
