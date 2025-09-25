/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 25 September 2025*/
/***********************************/

#include <stdio.h>
#include "tstack.h"
#include "boolean.h"

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	
	/* algoritma */
	createStack(&A);
	viewStack(A);
	printStack(A);
	push(&A,'A');
	push(&A,'B');
	push(&A,'C');
	printStack(A);
	char x;
	pop(&A,&x);
	printStack(A);
	printf("Elemen yang di-pop: %c\n", x);
	isPalindrom("katak") ? printf("Palindrom\n") : printf("Bukan Palindrom\n");
	pushN(&A,3);
	printStack(A);
	viewStack(A);
	return 0;
}
