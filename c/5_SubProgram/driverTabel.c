/***************************************************************/
/*                                                             */
/*    Nama File   : driverTabel.c                              */
/*    Deskripsi   : Driver Abstract Data Type Tabel            */
/*    Pembuat     : Muhammad Fikri - 24060124130069 	       */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include "tabel.h"

int main() /*Program Utama*/
{
    /*Kamus Lokal*/
    TabInt T;

    /*Algoritma*/
    CreateEmpty(&T);
    printf("Indek Efektif CreateEmpty(TabInt* T)=%d\n", T.NEff);
    printf("IsIdxValid(TabInt T, IdxType i)=%d\n", IsIdxValid(T, 2000));
    printf("IsIdxEff(TabInt T, IdxType i)=%d\n", IsIdxEff(T, 2));
    printf("IsEmpty(TabInt T)=%d\n", IsEmpty(T));
    printf("IsFull(TabInt T)=%d\n", IsFull(T));
    PrintTabel(T);
    IsiTabel(&T, 10);
    PrintTabel(T);
    printf("ValMax(TabInt T)=%d\n", ValMax(T));
    printf("ValMin(TabInt T)=%d\n", ValMin(T));
    printf("IdxValMax(TabInt T)=%d\n", IdxValMax(T));
    printf("IdxValMin(TabInt T)=%d\n", IdxValMin(T));

    // Tugas TabelSubProgram
    printf("NBElmt(TabInt T)=%d\n", NBElmt(T));
    printf("IdxLast(TabInt T)=%d\n", IdxLast(T));
    printf("IsEqual(TabInt T1, TabInt T2)=%d\n", IsEqual(T, T));
    printf("SearchIdx(TabInt T, ElmtType X)=%d\n", SearchIdx(T, 1));
    printf("SearchBool(TabInt T, ElmtType X)=%d\n", SearchBool(T, 2));
    TabInt T2;
    CopyTab(T, &T2);
    printf("CopyTab(TabInt Tin, TabInt* Tout)=%d\n", T2.NEff);
    printf("IsEqual(TabInt T1, TabInt T2)=%d\n", IsEqual(T, T2));
    printf("SearchIdx(TabInt T, ElmtType X)=%d\n", SearchIdx(T, 1));
    printf("SearchBool(TabInt T, ElmtType X)=%d\n", SearchBool(T, 1));
    printf("IsSimetris(TabInt T)=%d\n", IsSimetris(T));

    return 0;
}
