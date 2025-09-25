/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 25 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"
#include <string.h>

/* type Tstack = < wadah : array[1..10] of character,
                   top   : integer > */
// typedef	struct { char wadah[11];
//                  int  top; 
// 			   } Tstack;
/*karakter kosong dilambangkan dengan '#'  */
				 
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T)
{   
    // kamus lokal
    int i;
    // algoritma
    for (i=1;i<=10;i++)
    {
        (*T).wadah[i]='#';
    }
    (*T).top=0;
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
//int top (Tstack T);
//dalam praktikum ini, fungsi dapat direalisasikan
//menjadi macro dalam bahasa C.
#define top(T) (T).top

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
//char infotop (Tstack T);
#define infotop(T) (T).wadah[(T).top]

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T)
{
    // kamus lokal
    return (T.top==0);
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T)
{
    //  kamus lokal
    return (T.top==10);
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E)
{
    // Algoritma
    if (!isFullStack(*T))
    {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X)
{
    // Algoritma
    if (!isEmptyStack(*T))
    {
        *X = (*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top--;
    }
}


/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T)
{
    // Kamus Lokal
    int i;
    // Algoritma
    for (int i = 1; i <= 10; i++)
    {
        printf("%c ", T.wadah[i]);
    }
    printf("\n");
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T)
{
    // Kamus Lokal
    int i;
    // Algoritma
    for (i=1; i<=T.top; i++)
    {
        printf("%c ", T.wadah[i]);
    }
}

/* boolean isPalindrom(kata:String) 
   {mengembalikan true jika kata merupakan palindrom, false jika tidak},
   {asumsi panjang kata maksimum adalah 30 karakter} */
boolean isPalindrom(char kata[30])
{
    // kamus lokal
    int i;
    int n = strlen(kata);
    // algoritma
    for (i = 0; i < n / 2; i++)
    {
        if (kata[i] != kata[n - i - 1])
        {
            return false;
        }
    }
    return true;
}
/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali dari keyboard, bila belum penuh }*/
void pushN (Tstack *T, int N)
{
    // Kamus lokal
    char E;
    int i;
    // Algoritma
    for (i=0; i < N; i++)
    {
        printf("Input char:");
        scanf(" %c", &E);
        push (T,E);
    }
}

/* kerjakan latihan aplikasi stack di file mbrowser.c */
