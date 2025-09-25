#include <stdio.h>
#include <math.h>

int main() {
    int A,B,C;
    scanf("%d %d", &A, &B);

    C = A;
    A = B;
    B = C;

    printf("\nAfter swapping:\n");
    printf("Jar A: %d\n", A);
    printf("Jar B: %d\n", B);

    return 0;
}