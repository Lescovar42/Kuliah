/*Nama File 	: BlackMagic.c*/
/*Deskripsi 	: Jack of Diamond sedang mengamati dua benda sihir, masing-masing memiliki
daya sihir yang berbeda: benda pertama memiliki daya sihir N, sementara benda
kedua memiliki daya sihir M.Dalam eksperimennya, Jack mencoba mereaksikan
kedua benda tersebut dengan tiga benda sihir lainnya. Ternyata, hasil reaksi
tersebut berbeda-beda tergantung pada benda sihir yang digunakan:
1. Jika benda-benda tersebut direaksikan dengan 'GoldenApple', maka daya sihir
yang dihasilkan adalah nilai yang lebih kecil antara N dan M.
2. Jika benda-benda tersebut direaksikan dengan 'GolfHat', maka daya sihir yang
dihasilkan adalah nilai yang lebih besar antara N dan M.
3. Jika kedua benda direaksikan dengan 'RottenRose', maka daya sihir yang
dihasilkan adalah rata-rata dari N dan M.Dengan eksperimen ini, Jack
mencoba menguji berbagai kombinasi untuk melihat bagaimana reaksi benda-
benda sihir tersebut mempengaruhi daya sihir yang dihasilkan.*/
/*Pembuat   	: 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan	: 27-02-2025/9:00*/

#include <stdio.h>
#include <math.h>
#include <string.h>

float min2(float a, float b) {
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

float max2(float a, float b) {
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}

int main() {
    float N, M;
    scanf("%f %f", &N, &M);
    char Input[100];
    scanf("%s", Input);

    if (strcmp(Input, "GoldenApple") == 0) {
        printf("%f\n", min2(N, M));
    } else if (strcmp(Input, "GolfHat") == 0) {
        printf("%f\n", max2(N, M));
    } else if (strcmp(Input, "RottenRose") == 0) {
        printf("%f\n", (N + M) / 2);
    }

    return 0;
}