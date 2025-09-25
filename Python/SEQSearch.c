#include <stdio.h>
#include <stdbool.h>

void Search(int T[], int N, int X, int *IX, bool *Found) {
    int i = 0; 
    while (i < N && T[i] != X) {
        i++;
    }
    if (i < N) {
        *Found = true;
        *IX = i + 1;
    } else {
        *Found = false;
        *IX = 0;
    }
}

int main() {
    int T[] = {5, 10, 15, 20, 25};
    int N = sizeof(T) / sizeof(T[0]);
    int X = 15;
    int IX;
    bool Found;
    Search(T, N, X, &IX, &Found);
    if (Found) {
        printf("%d\n", IX);
    } else {
        printf("not found\n");
    }
    return 0;
}