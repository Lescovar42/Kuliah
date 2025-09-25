#include <stdio.h>

int main() {
    int T[] = {5, 2, 9, 1, 7};
    int N = sizeof(T) / sizeof(T[0]);
    int i, pass, temp, IMax;

    for (pass = 0; pass < N - 1; pass++) {
        IMax = pass;
        for (i = pass + 1; i < N; i++) {
            if (T[IMax] < T[i]) {
                IMax = i;
            }
        }

        temp = T[IMax];
        T[IMax] = T[pass];
        T[pass] = temp;
    }

    printf("Sorted array (descending): ");
    for (i = 0; i < N; i++) {
        printf("%d ", T[i]);
    }
    printf("\n");

    return 0;
}
