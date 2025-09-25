/* Nama File    : DeathSword2.c */
/* Deskripsi    : Menentukan ksatria yang selamat setelah M serangan, menggunakan subprogram */
/* Pembuat      : 24060124140166 - Muhammad Farhan Abdul Azis */

#include <stdio.h> /* header file */
#define MAX 100 /* Maksimum jumlah ksatria */

/* Subprogram */
void Inisialisasi(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = 1; // 1 = alive
    }
}
/* Subprogram */
int Search(int arr[], int N, int pos) {
    int i = (pos + 1) % N;
    while (arr[i] == 0) {
        i = (i + 1) % N;
    }
    return i;
}
/* Subprogram */
void doSerangan(int arr[], int N, int M) {
    int posPenyerang = 0;
    for (int i = 0; i < M; i++) {
        int posTarget = Search(arr, N, posPenyerang);
        arr[posTarget] = 0;  // 0 = dead
        posPenyerang = Search(arr, N, posPenyerang);
    }
}
/* Subprogram */
void printYangHidup(int arr[], int N) {
    int adaYangHidup = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) { 
            printf("%d ", i + 1);
            adaYangHidup = 1; 
        }
    }
    if (!adaYangHidup) {
        printf("Semua Ksatria telah mati, Ksatria terakhir bunuh diri\n");
    } else {
        printf("\n");
    }
}

/* Program Utama */
int main() {
    /* kamus */
    int N, M;
    int ksatria[MAX]; 

    /* Algoritma */
    printf("Masukkan jumlah ksatria: ");
    scanf("%d", &N);

    printf("Masukkan jumlah serangan: ");
    scanf("%d", &M);

    if (M >= N) {
        printf("Semua Ksatria telah mati, Ksatria terakhir bunuh diri\n");
        return 0;
    }

    Inisialisasi(ksatria, N);
    doSerangan(ksatria, N, M);
    printf("Ksatria yang selamat: ");
    printYangHidup(ksatria, N);

    return 0;
}
