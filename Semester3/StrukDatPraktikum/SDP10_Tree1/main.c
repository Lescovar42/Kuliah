/* File : pohon1.c */
/* Deskripsi : ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 27 November 2025 */

#include "pohon1.h"

int main()
{
    // Kamus
    bintree B, EmptyTree, Daun, LeftOnly, RightOnly;

    // Algoritma

    // Membuat pohon B
    B = Tree('T',
             Tree('I',
                  Tree('N',NIL,NIL),
                  Tree('F',
                       Tree('O',NIL,NIL),
                       NIL)),
             Tree('R',
                  Tree('M',
                       Tree('A',NIL,NIL),
                       Tree('T',NIL,NIL)),
                  Tree('I',
                       NIL,
                       Tree('K',
                            NIL,
                            Tree('A',NIL,NIL))))
            );

    printf("Pohon B (PrintPrefix): ");
    PrintPrefix(B);
    printf("\n\n");

    // Membuat pohon kosong
    EmptyTree = NIL;

    // Membuat pohon daun
    Daun = Tree('X', NIL, NIL);

    // Membuat pohon dengan anak kiri saja
    LeftOnly = Tree('L', Tree('C', NIL, NIL), NIL);

    // Membuat pohon dengan anak kanan saja
    RightOnly = Tree('R', NIL, Tree('C', NIL, NIL));

    // Test IsEmptyTree
    printf("IsEmptyTree(B): %s\n", IsEmptyTree(B) ? "true" : "false");
    printf("IsEmptyTree(EmptyTree): %s\n", IsEmptyTree(EmptyTree) ? "true" : "false");
    printf("IsEmptyTree(Daun): %s\n\n", IsEmptyTree(Daun) ? "true" : "false");

    // Test IsDaun
    printf("IsDaun(B): %s\n", IsDaun(B) ? "true" : "false");
    printf("IsDaun(Daun): %s\n", IsDaun(Daun) ? "true" : "false");
    printf("IsDaun(left(B)): %s (node 'I')\n\n", IsDaun(left(B)) ? "true" : "false");

    // Test IsBiner
    printf("IsBiner(B): %s\n", IsBiner(B) ? "true" : "false");
    printf("IsBiner(Daun): %s\n", IsBiner(Daun) ? "true" : "false");
    printf("IsBiner(left(B)): %s (node 'I')\n\n", IsBiner(left(B)) ? "true" : "false");

    // Test IsUnerLeft
    printf("IsUnerLeft(B): %s\n", IsUnerLeft(B) ? "true" : "false");
    printf("IsUnerLeft(LeftOnly): %s\n", IsUnerLeft(LeftOnly) ? "true" : "false");
    printf("IsUnerLeft(RightOnly): %s\n\n", IsUnerLeft(RightOnly) ? "true" : "false");

    // Test IsUnerRight
    printf("IsUnerRight(B): %s\n", IsUnerRight(B) ? "true" : "false");
    printf("IsUnerRight(LeftOnly): %s\n", IsUnerRight(LeftOnly) ? "true" : "false");
    printf("IsUnerRight(RightOnly): %s\n\n", IsUnerRight(RightOnly) ? "true" : "false");

    // Test GetLeft dan GetRight
    printf("Akar B: %c\n", akar(B));
    if (GetLeft(B) != NIL) {
        printf("GetLeft(B): %c\n", akar(GetLeft(B)));
    }
    if (GetRight(B) != NIL) {
        printf("GetRight(B): %c\n", akar(GetRight(B)));
    }
    printf("\n");

    // Test NbElm
    printf("NbElm(B): %d\n", NbElm(B));
    printf("NbElm(EmptyTree): %d\n", NbElm(EmptyTree));
    printf("NbElm(Daun): %d\n\n", NbElm(Daun));

    // Test NbDaun
    printf("NbDaun(B): %d\n", NbDaun(B));
    printf("NbDaun(EmptyTree): %d\n", NbDaun(EmptyTree));
    printf("NbDaun(Daun): %d\n\n", NbDaun(Daun));

    // Test max2
    printf("max2(5, 10): %d\n", max2(5, 10));
    printf("max2(15, 7): %d\n", max2(15, 7));
    printf("max2(8, 8): %d\n\n", max2(8, 8));

    // Test Tinggi
    printf("Tinggi(B): %d\n", Tinggi(B));
    printf("Tinggi(EmptyTree): %d\n", Tinggi(EmptyTree));
    printf("Tinggi(Daun): %d\n\n", Tinggi(Daun));

    // Test SearchX
    printf("SearchX(B, 'T'): %s\n", SearchX(B, 'T') ? "true" : "false");
    printf("SearchX(B, 'A'): %s\n", SearchX(B, 'A') ? "true" : "false");
    printf("SearchX(B, 'K'): %s\n", SearchX(B, 'K') ? "true" : "false");
    printf("SearchX(B, 'Z'): %s\n", SearchX(B, 'Z') ? "true" : "false");
    printf("SearchX(EmptyTree, 'X'): %s\n", SearchX(EmptyTree, 'X') ? "true" : "false");
    printf("SearchX(Daun, 'X'): %s\n", SearchX(Daun, 'X') ? "true" : "false");
    printf("SearchX(Daun, 'Y'): %s\n", SearchX(Daun, 'Y') ? "true" : "false");

        // Test UpdateX
    printf("Sebelum UpdateX (ganti 'I' menjadi 'Z'): ");
    PrintPrefix(B);
    printf("\n");
    UpdateX(&B, 'I', 'Z');
    printf("Sesudah UpdateX: ");
    PrintPrefix(B);
    printf("\n\n");

    // Test CountX
    printf("CountX(B, 'T'): %d\n", CountX(B, 'T'));
    printf("CountX(B, 'Z'): %d\n", CountX(B, 'Z'));
    printf("CountX(B, 'A'): %d\n\n", CountX(B, 'A'));

    // Test IsSkewLeft / Right
    printf("IsSkewLeft(B): %s\n", IsSkewLeft(B) ? "true" : "false");
    printf("IsSkewRight(B): %s\n", IsSkewRight(B) ? "true" : "false");
    printf("IsSkewLeft(LeftOnly): %s\n", IsSkewLeft(LeftOnly) ? "true" : "false");
    printf("IsSkewRight(RightOnly): %s\n\n", IsSkewRight(RightOnly) ? "true" : "false");

    // Test PrintPrefixRingkas
    printf("PrintPrefixRingkas(B): ");
    PrintPrefixRingkas(B);
    printf("\n\n");

    // Test LevelX
    printf("LevelX(B, 'T'): %d\n", LevelX(B, 'T'));
    printf("LevelX(B, 'M'): %d\n", LevelX(B, 'M'));
    printf("LevelX(B, 'A'): %d\n", LevelX(B, 'A'));
    printf("LevelX(B, 'Z'): %d\n\n", LevelX(B, 'Z'));

    // Test CountLevel
    printf("CountLevel(B, 1): %d\n", CountLevel(B, 1));
    printf("CountLevel(B, 2): %d\n", CountLevel(B, 2));
    printf("CountLevel(B, 3): %d\n", CountLevel(B, 3));
    printf("CountLevel(B, 4): %d\n", CountLevel(B, 4));
    printf("CountLevel(B, 5): %d\n\n", CountLevel(B, 5));

    // Test PrintLevel
    printf("PrintLevel(B, 1): ");
    PrintLevel(B, 1);
    printf("\n");

    printf("PrintLevel(B, 2): ");
    PrintLevel(B, 2);
    printf("\n");

    printf("PrintLevel(B, 3): ");
    PrintLevel(B, 3);
    printf("\n");

    printf("PrintLevel(B, 4): ");
    PrintLevel(B, 4);
    printf("\n\n");

    // Test GetDaunTerkiri
    printf("GetDaunTerkiri(B): %c\n", GetDaunTerkiri(B));
    printf("GetDaunTerkiri(Daun): %c\n", GetDaunTerkiri(Daun));
    printf("GetDaunTerkiri(EmptyTree): %c\n\n", GetDaunTerkiri(EmptyTree));

    // Test FrekuensiX
    printf("FrekuensiX(B, 'T'): %.2f\n", FrekuensiX(B, 'T'));
    printf("FrekuensiX(B, 'A'): %.2f\n", FrekuensiX(B, 'A'));
    printf("FrekuensiX(B, 'Z'): %.2f\n\n", FrekuensiX(B, 'Z'));

    // Test CountVocal / CountConsonant
    printf("CountVocal(B): %d\n", CountVocal(B));
    printf("CountConsonant(B): %d\n\n", CountConsonant(B));

    // Test PrintVocal / PrintConsonant
    printf("PrintVocal(B): ");
    PrintVocal(B);
    printf("\n");

    printf("PrintConsonant(B): ");
    PrintConsonant(B);
    printf("\n\n");

    // Test Modus
    printf("Modus(B): %c\n", Modus(B));

    return 0;
}
