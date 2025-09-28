/* Program   : mbrowser.c*/
/* Deskripsi : main program simulasi tombol backward/forward browser menggunakan ADT Stack*/
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 28 September 2025*/

#include <stdio.h>
#include <stdlib.h>
#include "tstack.h"
#include "boolean.h"

void showState(Tstack history, Tstack forward)
{
    //Algoritma
    printf("Current page: ");
    if (isEmptyStack(history)) {
        printf("<empty>\n");
    } else {
        printf("%c\n", infotop(history));
    }

    printf("History (viewStack): ");
    viewStack(history);
    printf("\n");

    printf("History (full container): ");
    printStack(history);

    printf("Forward (viewStack): ");
    viewStack(forward);
    printf("\n");

    printf("Forward (full container): ");
    printStack(forward);
    printf("---\n");
}

int main()
{
    //Kamus Lokal
    Tstack history, forward;
    createStack(&history);
    createStack(&forward);
    int kode;
    char ch, tmp;

    //Algoritma
    printf("Simulasi Browser\n");
    printf("Kode:\n 1 = buka alamat (push)\n 2 = backward\n 3 = forward\n 4 = exit\n");
    while (1) {
        printf("Masukkan kode (1-4): ");
        if (scanf(" %d", &kode) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        if (kode == 1) {
            if (isFullStack(history)) {
                printf("History penuh.\n");
            } else {
                printf("Input alamat (char): ");
                scanf(" %c", &ch);
                push(&history, ch);
                while (!isEmptyStack(forward)) {
                    pop(&forward, &tmp);
                }
            }
            showState(history, forward);
        } else if (kode == 2) {
            if (isEmptyStack(history)) {
                printf("Tidak ada halaman di history.\n");
            } else if (top(history) == 1) {
                printf("Tidak ada halaman sebelumnya.\n");
            } else {
                pop(&history, &tmp);
                push(&forward, tmp);
            }
            showState(history, forward);
        } else if (kode == 3) {
            if (isEmptyStack(forward)) {
                printf("Tidak ada halaman di forward.\n");
            } else {
                pop(&forward, &tmp);
                push(&history, tmp);
            }
            showState(history, forward);
        } else if (kode == 4) {
            printf("Keluar.\n");
            break;
        } else {
            printf("Kode tidak dikenali.\n");
        }
    }
    return 0;
}
