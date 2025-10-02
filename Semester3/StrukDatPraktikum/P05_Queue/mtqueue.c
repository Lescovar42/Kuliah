/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 2 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue.h"
#include "boolean.h"

int main(void) {
	// Kamus Lokal
    tqueue A, B;
    char out;

	// Algoritma
    createQueue(&A);
    createQueue(&B);

    printf("=== Uji enqueue ke A ===\n");
    enqueue(&A, 'a');
    enqueue(&A, 'b');
    enqueue(&A, 'c');
    enqueue(&A, 'd');
    enqueue(&A, 'e');
    enqueue(&A, 'f');

    printf("printQueue(A): ");
    printQueue(A);
    viewQueue(A);

    printf("\n=== Uji dequeue dari A ===\n");
    while (!isEmptyQueue(A)) {
        dequeue(&A, &out);
        printf("dequeue -> %c\n", out);
        printf("viewQueue(A): ");
        viewQueue(A);
    }

    dequeue(&A, &out);
    printf("dequeue pada kosong -> %c\n\n", out);

    printf("=== Uji enqueue2 ===\n");
    enqueue2(&A, &B, '1');
    enqueue2(&A, &B, '2');
    enqueue2(&A, &B, '3');
    enqueue2(&A, &B, '4');
    enqueue2(&A, &B, '5');
    enqueue2(&A, &B, '6');

    printf("A: ");
    viewQueue(A);
    printf("B: ");
    viewQueue(B);

    printf("\n=== Uji dequeue2===\n");
    dequeue2(&A, &B, &out);
    printf("dequeue2 -> %c\n", out);
    printf("A: ");
    viewQueue(A);
    printf("B: ");
    viewQueue(B);

    while (!isEmptyQueue(A)) { dequeue(&A, &out); }
    while (!isEmptyQueue(B)) { dequeue(&B, &out); }
    return 0;
}
