/* Nama File    : DeathSword.c */
/* Deskripsi    : Menentukan ksatria terakhir yang bertahan hidup */
/* Pembuat      : 24060124140166 - Muhammad Farhan Abdul Azis */
/* Tgl Pembuatan: 05-03-2025/10:00 */

#include <stdio.h>

/* Fungsi untuk mencari ksatria berikutnya yang masih hidup */
int nextAlive(int arr[], int N, int start) {
    int i = (start + 1) % N;
    while (arr[i] <= 0) {
        i = (i + 1) % N;
    }
    return i;
}

/* Program Utama */
int main() {
    /* Kamus */
    int N, i, attacker, target, aliveCount;

    /* Input jumlah ksatria */
    printf("Masukkan jumlah ksatria: ");
    scanf("%d", &N);

    int HP[N];  // Array HP untuk setiap ksatria

    /* Input HP setiap ksatria */
    printf("Masukkan HP tiap ksatria: ");
    for (i = 0; i < N; i++) {
        scanf("%d", &HP[i]);
    }

    /* Simulasi pertempuran */
    aliveCount = N;
    attacker = 0;  // Mulai dari ksatria pertama

    while (aliveCount > 1) {
        /* Cari target berikutnya */
        target = nextAlive(HP, N, attacker);

        /* Serang target */
        HP[target]--;

        /* Jika target mati */
        if (HP[target] == 0) {
            aliveCount--;
        }

        /* Pindah ke ksatria berikutnya yang masih hidup */
        attacker = nextAlive(HP, N, attacker);
    }

    /* Cetak ksatria terakhir yang bertahan */
    printf("Ksatria yang bertahan: %d\n", attacker + 1); // Konversi indeks ke posisi 1-based

    return 0;
}
