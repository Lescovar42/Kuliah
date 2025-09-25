/* Program   : mmatriks.c
 * Deskripsi : driver sederhana untuk menguji ADT Matriks
 * NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis
 * Tanggal   : 18 September 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

int main(void) {
    //Kamus Lokal
    Matriks M1, M2, M3, K;
    int row, col, count;
    int i,j,v;
    //Algoritma
    initMatriks(&M1);
    printf("1. initMatriks -> nbaris=%d, nkolom=%d\n", getNBaris(M1), getNKolom(M1));

    printf("\n2. Uji isEmpty / isFull\n");
    printf("   isEmpty(M1)=%s\n", isEmptyMatriks(M1) ? "true":"false");
    isiMatriksIdentitas(&M2, 10);
    printf("   isFull(M2)=%s\n", isFullMatriks(M2) ? "true":"false");

    printf("\n3. Uji addX / delX\n");
    initMatriks(&M1);
    addX(&M1, 99, 10, 10);
    printf("   Setelah addX(99,10,10): nbaris=%d, nkolom=%d\n", getNBaris(M1), getNKolom(M1));
    viewMatriks(M1);
    delX(&M1, 99);
    printf("   Setelah delX(99): nbaris=%d, nkolom=%d\n", getNBaris(M1), getNKolom(M1));
    viewMatriks(M1);

    printf("\n4. isiMatriksRandom(10x10)\n");
    isiMatriksRandom(&M1,10,10);
    printf("   Matriks random 10x10, nbaris=%d, nkolom=%d\n", getNBaris(M1), getNKolom(M1));

    printf("\n5. isiMatriksIdentitas(10)\n");
    isiMatriksIdentitas(&M2,10);
    viewMatriks(M2);

    printf("\n6. addMatriks identitas10 + identitas10\n");
    M3 = addMatriks(M2,M2);
    viewMatriks(M3);

    printf("\n7. subMatriks identitas10 - identitas10\n");
    M3 = subMatriks(M2,M2);
    viewMatriks(M3);

    printf("\n8. kaliSkalarMatriks identitas10 * 5\n");
    M3 = kaliSkalarMatriks(M2,5);
    viewMatriks(M3);

    printf("\n9. kaliMatriks identitas10 * identitas10\n");
    M3 = kaliMatriks(M2,M2);
    viewMatriks(M3);

    printf("\n10. transposeMatriks identitas10\n");
    transposeMatriks(&M2);
    viewMatriks(M2);

    printf("\n11. addPadding identitas8 dengan padding=1\n");
    isiMatriksIdentitas(&M1,8);
    M3 = addPadding(M1,1);
    printf("   nbaris=%d, nkolom=%d\n", getNBaris(M3), getNKolom(M3));

    printf("\n12. maxPooling / avgPooling 10x10 dengan size=2\n");
    v=1;
    initMatriks(&M1);
    for(i=1;i<=10;i++){
        for(j=1;j<=10;j++){
            addX(&M1, v++, i, j);
        }
    }
    M2 = maxPooling(M1,2);
    printMatriks(M2);
    M3 = avgPooling(M1,2);
    printMatriks(M3);

    printf("\n13. conv pada 10x10 dengan kernel 3x3\n");
    isiMatriksIdentitas(&K,3);
    M2 = conv(M1,K);
    printf("   Hasil konvolusi ukuran %dx%d\n", getNBaris(M2), getNKolom(M2));

    printf("\n14. searchX & countX pada matriks 10x10\n");
    searchX(M1,50,&row,&col);
    printf("   search 50: (%d,%d)\n",row,col);
    count = countX(M1,50);
    printf("   count 50: %d\n",count);

    printf("\n=== SELESAI ===\n");
    return 0;
}