/*
Nama : Muhammad Farhan Abdul Azis
NIM  : 24060124140166
Deskripsi : Program ini menghitung total kekuatan maksimum yang dapat diperoleh salah satu pemain dalam permainan pion, dengan mempertimbangkan pion yang loyal kepada masing-masing pemain serta pion netral yang dapat dialokasikan secara optimal.*/


/*======================= SELAMAT DATANG DI SOAL SUITLESS ===========================*/
/* Pada soal suitless, kalian diminta untuk meemperbaiki kode di bawah ini, setelah
Kode kalian selesai lengkapi, cobalah untuk men-tracing semua sample input yang diberikan,
berikan pula penjelasan mengapa algoritma ini dipakai ? apakah ada alternatif lain?
Perhatikan penulisan algoritma, algoritma bukanlah sebah blok kode bahasa pemrograman
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    /* Kamus */
    int N;
    scanf("%d", &N);
    
    int A[N], T[N];
    int KingMax = 0, QueenMax = 0;
    int NeutralPawns[100], neutralCount = 0;
    
    /* Algoritma */
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A[i], &T[i]);
        
        if (T[i] == 1) {
            KingMax += A[i]; // Pion loyal ke King
        } else if (T[i] == 2) {
            QueenMax += A[i]; // Pion loyal ke Queen
        } else if (T[i] == 3) {
            NeutralPawns[neutralCount++] = A[i]; // Save pion netral
        }
    }
    
    // Mengurutkan pion netral dari yang terbesar ke terkecil
    for (int i = 0; i < neutralCount - 1; i++) {
        for (int j = i + 1; j < neutralCount; j++) {
            if (NeutralPawns[i] < NeutralPawns[j]) {
                int temp = NeutralPawns[i];
                NeutralPawns[i] = NeutralPawns[j];
                NeutralPawns[j] = temp;
            }
        }
    }
    
    // Menambahkan pion netral secara bergantian untuk mendapatkan hasil terbaik
    for (int i = 0; i < neutralCount; i++) {
        if (KingMax <= QueenMax) {
            KingMax += NeutralPawns[i];
        } else {
            QueenMax += NeutralPawns[i];
        }
    }
    
    printf("%d\n", (KingMax > QueenMax) ? KingMax : QueenMax);
    
    return 0;
    
    /* Tulis Hasil Tracing Kalian di sini , Menggunakan Komentar */
    /*
    Sample Input:
    3
    7 1
    5 2
    4 3
    
    Proses:
    - Pion 7 (tipe 1) -> KingMax = 7
    - Pion 5 (tipe 2) -> QueenMax = 5
    - Pion 4 (tipe 3) -> Disimpan di daftar netral
    
    Urutkan pion netral: [4]
    - KingMax (7) > QueenMax (5), maka pion netral 4 ditambahkan ke QueenMax
    - QueenMax = 5 + 4 = 9
    
    Output: 11
    */
    
    /* Tulis Alasan Kalian di sini , Menggunakan Komentar */
    /*
    Algoritma ini digunakan karena:
    - Menggunakan sorting untuk memastikan pion netral terbesar dialokasikan terlebih dahulu.
    - Menggunakan strategi greedy untuk menyeimbangkan kekuatan antara King dan Queen secara optimal.
    - Kompleksitas O(N^2) dari sorting cukup optimal untuk N <= 100.
    Alternatif lain adalah menggunakan dynamic programming
    */
}
