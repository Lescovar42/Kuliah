#ifndef tprocess_H
#define tprocess_H

/* Program   : tprocess.h */
/* Deskripsi : header file modul proses untuk penjadwalan CPU */
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 11 Oktober 2025*/
/***********************************/


/*Type tProses = <idProses: character, burstTime: integer>
{tproses sebagai representasi proses yang akan dikerjakan di cpu}
*/
typedef struct {
    char idProses;
    int burstTime;
} tProses;

/*procedure createProses(output P: tProses, input c: character, input n: integer)
{I.S.: c dan n terdefinisi}
{F.S.: P terdefinisi dengan idProses = c dan burstTime = n}
{Proses: mengisi struktur proses dengan ID dan burst time yang diberikan}
*/
void createProses(tProses *P, char id, int bt);

/*function idProses(P: tProses) → character
{I.S.: P terdefinisi}
{F.S.: mengembalikan nilai idProses dari P}
{Proses: mengakses field idProses dari struktur tProses}
*/
char idProses(tProses P);

/*function burstTime(P: tProses) → integer
{I.S.: P terdefinisi}
{F.S.: mengembalikan nilai burstTime dari P}
{Proses: mengakses field burstTime dari struktur tProses}
*/
int burstTime(tProses P);

/*procedure setBurstTime(output P: tProses, input bt: integer)
{I.S.: P terdefinisi, bt terdefinisi}
{F.S.: P.burstTime = bt, jika bt < 0 maka P.burstTime = 0}
{Proses: mengubah nilai burstTime dari struktur tProses}
*/
void setBurstTime(tProses *P, int bt);

/*function isFinished(P: tProses) -> boolean
{I.S.: P terdefinisi}
{F.S.: mengembalikan true jika burstTime(P) = 0, false jika tidak}
{Proses: memeriksa apakah proses telah selesai berdasarkan burstTime}
*/
int isFinished(tProses P);

/*procedure printProses(input P: tProses)
{I.S.: P terdefinisi}
{F.S.: mencetak idProses dan burstTime ke layar dalam format "idProses(burstTime)"}
{Proses: menampilkan informasi proses ke layar}
*/
void printProses(tProses P);

#endif
