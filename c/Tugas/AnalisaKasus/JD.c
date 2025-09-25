#include <stdio.h>

// Fungsi untuk menghitung jumlah digit suatu bilangan
int hitungJumlahDigit(int N) {
    int jumlah_digit = 0;
    
    while (N > 0) {
        jumlah_digit += N % 10; // Mengambil digit terakhir dan menambahkannya
        N /= 10;  // Menghapus digit terakhir
    }
    
    return jumlah_digit;
}

int main() {
    int N;
    
    // Input dari pengguna
    printf("Masukkan bilangan: ");
    scanf("%d", &N);
    
    // Pastikan N adalah bilangan positif
    if (N < 0) {
        printf("Masukkan harus bilangan positif!\n");
        return 1;
    }
    
    // Panggil fungsi dan tampilkan hasil
    printf("Jumlah digit: %d\n", hitungJumlahDigit(N));
    
    return 0;
}
