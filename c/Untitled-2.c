#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float min2(float a, float b) {
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

int main() {
    //kamus
    int a, b, c, d;

    //algo
    scanf("%d %d %d %d", &a, &b, &c, &d);

    float rata2 = (a + b + c) / 3.0 * 0.7; 

    float nilaiA = fabs(a - rata2);
    float nilaiB = fabs(b - rata2);
    float nilaiC = fabs(c - rata2);

    float minimal = min2(nilaiA, min2(nilaiB, nilaiC));
    int winner;
    if (minimal == nilaiA) {
        winner = a;
    } else if (minimal == nilaiB) {
        winner = b;
    } else {
        winner = c;
    }

    printf("Pemain yang paling dekat dengan rata-rata adalah %d", &d);
    return 0;
}