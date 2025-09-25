/***************************************************************/
/*                                                             */
/*    Nama File   : driverTabel.h                              */
/*    Deskripsi   : Driver Abstract Data Type Tabel            */
/*                                                             */
/***************************************************************/

#include "tabel.h"
#include <stdio.h>

int main()
{ /*Program Utama*/
    /*Kamus Lokal*/
    TabInt T;
    ElmtType ValMax(TabInt T);
    /* Mengirimkan nilai maksimum TabInt T. */
    /* Pre Condition : Tabel tidak kosong. */
    
    ElmtType ValMin(TabInt T);
    /* Mengirimkan nilai minimum TabInt T. */
    /* Pre Condition : Tabel tidak kosong. */
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
    return 0;
}