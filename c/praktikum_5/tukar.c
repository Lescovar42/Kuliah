/*Nama File 	: tukar.c*/
/*Deskripsi 	: menukar nilai variabel dengan prosedur*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 06.20*/

#include <stdio.h>

void tukar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    tukar(&a, &b);

    printf("%d %d\n", a, b);
    return 0;
}
