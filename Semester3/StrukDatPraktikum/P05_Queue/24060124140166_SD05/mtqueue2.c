/* Program   : mtqueue2.c */
/* Deskripsi : file DRIVER modul queue karakter, model II: head bergeser/jelajah*/
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal   : 5 Oktober 2025 */
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

int main(void) {
    // Kamus Lokal
    tqueue2 Q;
    char out;

    // Algoritma
    printf("=== Test createQueue2 ===\n");
    createQueue2(&Q);
    viewQueue2(Q);

    printf("\n=== Test isEmptyQueue2 & isFullQueue2 ===\n");
    printf("isEmptyQueue2: %d\n", isEmptyQueue2(Q));
    printf("isFullQueue2: %d\n", isFullQueue2(Q));

    printf("\n=== Test enqueue2 ===\n");
    enqueue2(&Q, 'x');
    enqueue2(&Q, 'y');
    enqueue2(&Q, 'z');
    enqueue2(&Q, 'w');
    enqueue2(&Q, 'v');
    printf("After enqueue2 5x:\n");
    printQueue2(Q);
    viewQueue2(Q);

    printf("\n=== Test isFullQueue2 after enqueue ===\n");
    printf("isFullQueue2: %d\n", isFullQueue2(Q));

    printf("\n=== Test dequeue2 ===\n");
    dequeue2(&Q, &out);
    printf("dequeue2 -> %c\n", out);
    viewQueue2(Q);

    printf("\n=== Test enqueue2 after dequeue ===\n");
    enqueue2(&Q, 'a');
    printQueue2(Q);
    viewQueue2(Q);

    printf("\n=== Test dequeue2 until empty ===\n");
    while (!isEmptyQueue2(Q)) {
        dequeue2(&Q, &out);
        printf("dequeue2 -> %c\n", out);
        viewQueue2(Q);
    }

    printf("\n=== Test dequeue2 pada kosong ===\n");
    dequeue2(&Q, &out);
    printf("dequeue2 pada kosong -> %c\n", out);

    printf("\n=== Test printQueue2 pada kosong ===\n");
    printQueue2(Q);

    printf("\n=== Test isEmptyQueue2 pada kosong ===\n");
    printf("isEmptyQueue2: %d\n", isEmptyQueue2(Q));

    return 0;
}