/*
Nama : Muhammad Farhan Abdul Azis
NIM  : 24060124140166
Deskripsi : Atma akan merapikan arsip dengan aturan berikut:

    Setiap kolom diurutkan secara vertikal, di mana semua angka 1 harus turun sejauh mungkin ke bagian bawah kolom tersebut

    Urutan asli antar angka 1 dalam kolom tetap dipertahankan, artinya jika ada 1 yang muncul lebih dulu sebelum 1 lainnya di kolom yang sama, urutannya tidak boleh berubah

    Angka 0 akan naik ke bagian atas kolom sebagai akibat dari turunnya angka 1
*/

#include <stdio.h> //Header File


void Tukar(int *a, int *b) {
    // Kamus
    int temp = *a;
    // Algoritma
    *a = *b;
    *b = temp;
}

// Program Utama
int main() {
    // Kamus
    int N, M;
    scanf("%d %d", &N, &M);
    
    int matrix[N][M];
    
    // Algoritma
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int j = 0; j < M; j++) {
        for (int i = N - 1; i > 0; i--) { // Bubble sort
            for (int k = 0; k < i; k++) {
                if (matrix[k][j] == 0 && matrix[k+1][j] == 1) {
                    Tukar(&matrix[k][j], &matrix[k+1][j]);
                }
            }
        }
    }
    
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            printf("%d", matrix[i][j]);
            if (j < M - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}