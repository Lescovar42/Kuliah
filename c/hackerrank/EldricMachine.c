/*
Nama : Muhammad Farhan Abdul Azis
NIM  : 24060124140166
Deskripsi : Jika hari ini tanggal ganjil, ia akan mengetes kondisi akhir 
mesinnya dengan menekan semua saklar yang dimiliki masing masing tepat 
sekali, tetapi jika hari ini adalah tanggal genap, ia akan menekan saklar 
bernomor i yang mana i habis membagi N. Output menetukan kondisi mesin setelah eksperimen.*/

#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long N;
    int H;
    scanf("%llu %d", &N, &H);
    int On = 0;
    
    if (H % 2 == 1) {
        On = N % 2;
    } else {
        int count = 0;
        for (unsigned long long i = 1; i * i <= N; i++) {
            if (N % i == 0) {
                count++;
                if (i != N / i) {
                    count++;
                    }
                }
            }
        On = count % 2;
    }
    
    if (On) {
        printf("Mesin Menyala\n");
    } else {
        printf("Mesin Mati\n");
    }
    
    return 0;}