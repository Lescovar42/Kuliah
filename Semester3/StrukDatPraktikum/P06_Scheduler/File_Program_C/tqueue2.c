/* Program   : tqueue2.c */
/* Deskripsi : file BODY modul queue karakter, model II: head bergeser/jelajah*/
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 11 Oktober 2025*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"
#include "tprocess.h"
#include <string.h>

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q)
{
    return (Q.head == 0 && Q.tail == 0);
}
 
/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q)
{
    return (Q.tail == 5);
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q)
{
    return (Q.head == Q.tail && Q.head != 0);
}

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi head dan tail dengan 0, elemen kosong='#'}*/ 
void createQueue2(tqueue2 *Q)
{
    // kamus lokal
    int i;
    // algoritma
    for (i=1;i<=5;i++)
    {
        (*Q).wadah[i].idProses='#';
        (*Q).wadah[i].burstTime=0;

    }
    (*Q).head=0;
    (*Q).tail=0;
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q)
{
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q)
{
    return Q.tail;
}

// /*Function InfoHead2(Q:Tqueue2) -> character
// {mengembalikan nilai elemen terdepan} */
// char infoHead2(tqueue2 Q)
// {
//     return Q.wadah[Q.head];
// }

// /*Function InfoTail2(Q:Tqueue2) -> character
// {mengembalikan nilai elemen terakhir} */
// char infoTail2(tqueue2 Q)
// {
//     return Q.wadah[Q.tail];
// }

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q)
{
    // Kamus Lokal
    int size;
    // ALgoritma
    return (Q.tail - Q.head + 1);
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q)
{
    // Kamus Lokal
    int i;
    // Algoritma
    for (int i = 1; i <= 5; i++)
    {
        printf("%c ", Q.wadah[i]);
    }
    printf("\n");
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q)
{
    // Kamus Lokal
    int i;
    // Algoritma
    if (!isEmptyQueue2(Q))
    {
        for (i = Q.head; i <= Q.tail; i++)
        {
            printf("%c ", Q.wadah[i], "\n");
        }
    }
    else
    {
        printf("Queue kosong\n");
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q)
{
    return (Q.tail == 5);
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q) {
    if (isTailStop(*Q) && Q->head > 1) {
        int j = 1;
        for (int i = Q->head; i <= Q->tail; i++) 
        {
            Q->wadah[j] = Q->wadah[i];
            j++;
        }
        for (int k = j; k <= 5; k++) 
        {
            Q->wadah[k].idProses = '#';
            Q->wadah[k].burstTime = 0;
        }
        Q->head = 1;
        Q->tail = j - 1;
    }
}

/*procedure enqueue2(input/output Q: tqueue2, input P: tProses)
{I.S.: Q dan P terdefinisi}
{F.S.: P ditambahkan ke queue jika belum penuh}
{Proses: 
  - Jika queue kosong, set head = 1 dan tail = 1
  - Jika tidak kosong dan masih ada ruang, increment tail
  - Masukkan P ke posisi tail}
*/
void enqueue2(tqueue2 *Q, tProses P) {
    if (isTailStop(*Q) && Q->head > 1) 
    {
        resetHead(Q);
    }
    if (isEmptyQueue2(*Q)) 
    {
        Q->head = 1;
        Q->tail = 1;
        Q->wadah[Q->tail] = P;
    } else if (!isFullQueue2(*Q))
    {
        Q->tail = Q->tail + 1;
        Q->wadah[Q->tail] = P;
    }
}
  
/*procedure dequeue2(input/output Q: tqueue2, output P: tProses)
{I.S.: Q terdefinisi}
{F.S.: elemen head dikeluarkan dari queue dan disimpan di P}
{Proses:
  - Jika queue tidak kosong, ambil elemen head
  - Jika tinggal 1 elemen, set head = 0 dan tail = 0
  - Selain itu, increment head
  - Jika queue kosong, set P dengan proses '@'}
*/
void dequeue2(tqueue2 *Q, tProses *P) 
{
    tProses kosong;
    kosong.idProses = '#';
    kosong.burstTime = 0;
    if (!isEmptyQueue2(*Q)) 
    {
        *P = Q->wadah[Q->head];
        Q->wadah[Q->head] = kosong;
        if (isOneElement2(*Q)) 
        {
            Q->head = 0;
            Q->tail = 0;
        } else 
        {
            Q->head = Q->head + 1;
        }
    } else 
    {
        P->idProses = '@';
        P->burstTime = 0;
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N)
{
    // Kamus Lokal
    char e;
    int i;
    // Algoritma
    if (N <= 5 - sizeQueue2(*Q))
    {
        for (i = 1; i <= N; i++)
        {
            printf("Masukkan elemen ke-%d: ", i);
            scanf(" %c", &e);
            enqueue2(Q, (tProses){e, 0});
        }
    }
    else
    {
        printf("Jumlah elemen melebihi kapasitas\n");
    }
}

/*EXTRA: kerjakan bila semua fungsi/prosedur di atas sudah well tested*/
/*Function isEqualQueue2(Q1:TQueue2,Q2:TQueue2) -> boolean
{mengembalikan true jika Q1 dan Q2 berisi elemen yang sama}
{ingat, kondisi head Q1 dan Q2 mungkin tidak sama} */
// boolean isEqualQueue2(tqueue2 Q1,tqueue2 Q2);
