#include <stdio.h>

int main() {
    int row, col;

    // Pattern A
    for (row = 1; row <= 10; row++) {
        for (col = 1; col <= row; col++) {
            printf("%s", "*");
        }
        printf("\n");
    }

    printf("\n");

    // Pattern B
    for (row = 10; row >= 1; row--) {
        for (col = 1; col <= row; col++) {
            printf("%s", "*");
        }
        printf("\n");
    }

    printf("\n");

    // Pattern C
    for (row = 1; row <= 10; row++) {
        for (col = 1; col < row; col++) {
            printf(" ");
        }
        for (col = row; col <= 10; col++) {
            printf("%s", "*");
        }
        printf("\n");
    }

    printf("\n");

    // Pattern D
    for (row = 1; row <= 10; row++) {
        for (col = 10; col > row; col--) {
            printf(" ");
        }
        for (col = 1; col <= row; col++) {
            printf("%s", "*");
        }
        printf("\n");
    }

    return 0;
}
