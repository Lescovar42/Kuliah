/*Nama File 	: GameMaster.c*/
/*Deskripsi 	: Joker mengambil dua kartu secara
acak dari dek yang dimilikinya.Jika kartu yang ada di
tangan kanan(1st card) Joker memiliki peringkat lebih
tinggi dibandingkan kartu di tangan kirinya, dia akan
menyebutkan nama kartu yang ada di tangan kanannya.
Namun, jika kedua kartu tersebut memiliki peringkat yang
sama, dia akan menyebutkan kedua kartu tersebut.*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 5-03-2025/21:00*/

#include <stdio.h> /*header file*/

/*Fungsi untuk mencetak kartu*/
int printCard(int card) {
    /*Kamus*/
    int rank = card / 10;  
    int suit = card % 10; 
    char *suitName;
    /*Algoritma*/
    switch(suit) {
        case 1: suitName = "Diamond"; break;
        case 2: suitName = "Spade";   break;
        case 3: suitName = "Heart";   break;
        case 4: suitName = "Club";    break;
        default: suitName = "Unknown"; break;
    }

    if (rank == 11)
        printf("Jack of %s", suitName);
    else if (rank == 12)
        printf("Queen of %s", suitName);
    else if (rank == 13)
        printf("King of %s", suitName);
    else if (rank == 14)
        printf("Ace of %s", suitName);
    else
        printf("%d of %s", rank, suitName);
    
    return 0;
}

/*Program Utama*/
int main() {
    /*Kamus*/
    int card1, card2;
    /*Algoritma*/
    printf("Masukkan kartu (bilangan bulat) di tangan kanan (1st card): ");
    scanf("%d", &card1);
    printf("Masukkan kartu (bilangan bulat) di tangan kiri (2nd card): ");
    scanf("%d", &card2);

    int rank1 = card1 / 10;
    int rank2 = card2 / 10;
    
    if (rank1 > rank2) {
        printCard(card1);
    }

    else if (rank1 == rank2) {
        printCard(card1);
        printf(" dan ");
        printCard(card2);
    }

    else {
        printCard(card2);
    }
    
    printf("\n");
    return 0;
}
