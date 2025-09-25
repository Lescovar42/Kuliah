#include <stdio.h>
#include <stdbool.h>

void BinSearch(int T[], int N, int X, bool *Found, int *IX) {
    int Atas = 0;
    int Bawah = N;
    int Tengah;

    *Found = false;

    while ((Atas <= Bawah) && !(*Found)) {
        Tengah = (Atas + Bawah) / 2;
        if (X == T[Tengah]) {
            *Found = true;
            *IX = Tengah;
        } else if (X < T[Tengah]) {
            Bawah = Tengah - 1;
        } else {
            Atas = Tengah + 1;
        }
    }
}

int main() {
    int T[] = {2, 4, 7, 10, 13, 18, 21};
    int N = sizeof(T) / sizeof(T[1]);
    int X = 13;
    bool Found;
    int IX;

    BinSearch(T, N, X, &Found, &IX);
    if (Found) {
        printf("Element %d found at index %d\n", X, IX);
    } else {
        printf("Element %d not found\n", X);
    }
}
