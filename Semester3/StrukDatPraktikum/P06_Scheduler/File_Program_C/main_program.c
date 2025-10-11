/* File : main_program.c */
/* Deskripsi: Program utama simulasi penjadwalan proses CPU dengan algoritma Round Robin */
/* NIM/Nama : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal : 11 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tprocess.h"
#include "tqueue2.h"
#define QUANTUM 5

/*program round_robin
{I.S.: -}
{F.S.: simulasi penjadwalan Round Robin selesai dan ditampilkan ke layar}
{Proses:
  1. Membuat 5 proses berdasarkan 5 digit terakhir NIM (30069)
  2. Memasukkan semua proses ke queue
  3. Melakukan simulasi Round Robin dengan quantum time = 5
  4. Menampilkan urutan eksekusi, waktu mulai, dan waktu selesai}
{Algoritma Round Robin:
  - Ambil proses dari head queue
  - Eksekusi selama quantum time atau sampai selesai
  - Jika belum selesai, masukkan kembali ke tail queue
  - Ulangi sampai semua proses selesai}
*/
int main(void) {
    // Kamus Lokal
    const char *nim5 = "40166";
    int digits[5] = {4, 7, 1, 6, 6};
    // Algoritma
    printf("=== SIMULASI PENJADWALAN PROSES CPU - ROUND ROBIN ===\n");
    printf("NIM (5-digit terakhir): %s\n", nim5);
    printf("Quantum Time: %d satuan waktu\n\n", QUANTUM);

    printf("=== PEMBENTUKAN PROSES BERDASARKAN NIM ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Proses %c: BT = %d\n", 'A' + i, digits[i]);
    }
    printf("\n");

    tProses P[5];
    for (int i = 0; i < 5; i++) createProses(&P[i], 'A' + i, digits[i]);

    tqueue2 Q;
    createQueue2(&Q);

    printf("=== URUTAN KEDATANGAN PROSES ===\n");
    for (int i = 0; i < 5; i++) {
        printf("Proses %c masuk antrian (BT: %d)\n", P[i].idProses, P[i].burstTime);
        enqueue2(&Q, P[i]);
    }
    printf("\n");

    printf("=== ANTRIAN PROSES AWAL ===\n");
    viewQueue2(Q);
    printf("\n");

    int currentTime = 0;
    int execNo = 1;

    printf("=== SIMULASI EKSEKUSI DENGAN ROUND ROBIN ===\n");
    printf("Eksekusi | Proses | Waktu Mulai | Waktu Selesai | Burst Time Sisa\n");
    printf("--------:|:------:|:-----------:|:-------------:|:---------------:\n");

    while (!isEmptyQueue2(Q)) {
        tProses cur;
        dequeue2(&Q, &cur);

        if (cur.idProses == '@') break;
        if (cur.burstTime <= 0) continue;

        int start = currentTime;
        int dur = (cur.burstTime <= QUANTUM) ? cur.burstTime : QUANTUM;
        cur.burstTime -= dur;
        currentTime += dur;
        int finish = currentTime;

        printf("%7d |   %c    |     %3d     |      %3d      |       %3d\n",
               execNo, cur.idProses, start, finish, cur.burstTime);
        execNo++;

        if (cur.burstTime > 0) {
            enqueue2(&Q, cur);
        }
    }

    printf("\n=== SIMULASI SELESAI ===\n");
    printf("Total waktu eksekusi: %d satuan waktu\n", currentTime);
    printf("Semua proses telah selesai dieksekusi.\n");

    return 0;
}