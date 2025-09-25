/*Nama File   : cekBilAll.c*/
/*Deskripsi   : Mengecek apakah bilangan N merupakan bilangan Prima, Sempurna, atau Biasa*/
/*Pembuat     : 24060124140166 - Muhammad Farhan Abdul Azis*/
/*Tgl Pembuatan : 20-03-2025/20:00*/

#include <stdio.h>
#include <math.h> /*Header File*/

int main()
{
    /*Kamus*/
    int N, i, sum = 0;
    int isPrime = 1;

    /*Algoritma*/
    printf("Masukkan bilangan N (N > 0): ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Harus bilangan positif\n");
        return 0;
    }

    if (N == 1) {
        isPrime = 0;
    } else {
        for(i = 2; i <= sqrt(N); i++) {
            if(N % i == 0) {
                isPrime = 0;
                break;
            }
        }
    }
    
    if (isPrime) {
        printf("%d = Bilangan Prima\n", N);
    }
    else {
        sum = 0;
        for(i = 1; i < N; i++) {
            if(N % i == 0) {
                sum += i;
            }
        }
        if(sum == N) {
            printf("%d = Bilangan Sempurna\n", N);
        }
        else {
            printf("%d = Bilangan Biasa\n", N);
        }
    }
    
    return 0;
}
