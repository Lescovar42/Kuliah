/* File : main.c */
/* Deskripsi : Driver Program untuk menguji ADT Pohon Biner (pohon1 + pohon2) */
/* Author : Muhammad Farhan Abdul Azis */
/* Tanggal : 4 Desember 2025 */

#include <stdio.h>
#include "pohon2.h"

int main() {
    bintree P = NIL;
    bintree PBalanced = NIL;
    infotype X;

    printf("DEMO ADT POHON BINER\n");

    /* 1. KONSTRUKSI AWAL */
    printf("[1] MEMBANGUN POHON AWAL\n");
    P = Tree('A', 
            Tree('B', NIL, NIL), 
            Tree('C', 
                Tree('D', NIL, NIL), 
                Tree('E', NIL, NIL)
            )
        );
    
    printf("Tampilan Pohon Awal (Indentasi 2):\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 2. TEST PRINT LEVEL */
    printf("[2] TEST PRINT LEVEL\n");
    printf("Level 1 : "); PrintLevel(P, 1); printf("\n");
    printf("Level 2 : "); PrintLevel(P, 2); printf("\n");
    printf("Level 3 : "); PrintLevel(P, 3); printf("\n");
    printf("\n----------------------------------------------------------------\n");

    /* 3. TEST INSERT X */
    /* InsertX mengisi kosong terkiri secara rekursif */
    printf("[3] TEST INSERT X (Menambah 'F' dan 'G')\n");
    InsertX(&P, 'F'); // Seharusnya masuk ke anak kiri B (karena B daun)
    InsertX(&P, 'G'); // Seharusnya masuk ke anak kanan B
    
    printf("Hasil setelah InsertX 'F' dan 'G':\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 4. TEST ADD DAUN TERKIRI */
    printf("[4] TEST ADD DAUN TERKIRI (Menambah 'Z')\n");
    AddDaunTerkiri(&P, 'Z'); // Akan menelusuri kiri terus sampai ujung
    
    printf("Hasil setelah AddDaunTerkiri 'Z' (Z harus dipaling kiri bawah):\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 5. TEST ADD DAUN (Spesifik) */
    printf("[5] TEST ADD DAUN SPESIFIK\n");
    printf("Menambah 'K' sebagai anak Kanan dari 'E'...\n");
    AddDaun(&P, 'E', 'K', false); // false = kanan
    
    printf("Hasil setelah AddDaun 'K' di kanan 'E':\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 6. TEST UPDATE ALL X */
    printf("[6] TEST UPDATE ALL X\n");
    printf("Mengubah semua node bernilai 'B' menjadi 'X'...\n");
    UpdateAllX(&P, 'B', 'X');
    
    printf("Hasil setelah UpdateAllX (B -> X):\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* --- BAGIAN PENGHAPUSAN --- */

    /* 7. TEST DEL DAUN TERKIRI */
    printf("[7] TEST DEL DAUN TERKIRI\n");
    DelDaunTerkiri(&P, &X);
    printf("Daun terkiri yang dihapus adalah: %c\n", X);
    
    printf("Hasil Pohon setelah DelDaunTerkiri:\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 8. TEST DEL DAUN (Spesifik) */
    printf("[8] TEST DEL DAUN\n");
    printf("Menghapus daun bernilai 'K'...\n");
    DelDaun(&P, 'K');
    
    printf("Hasil Pohon setelah DelDaun 'K':\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 9. TEST DELETE X (Kasus Node dengan 2 Anak) */
    printf("[9] TEST DELETE X (NODE DG 2 ANAK)\n");
    printf("Menghapus node 'C' (memiliki anak D dan E)...\n");
    DeleteX(&P, 'C');
    
    printf("Hasil Pohon setelah DeleteX 'C':\n");
    PrintTreeInden(P, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 10. TEST DELETE X (Kasus Daun) */
    printf("[10] TEST DELETE X (DAUN)\n");
    printf("Menghapus node 'G'...\n");
    DeleteX(&P, 'G');

    printf("Hasil Pohon Akhir:\n");
    PrintTreeInden(P, 2);

    /* 11. TEST BuildBalanceTree */
    printf("\n[11] TEST BuildBalanceTree\n");
    printf("Kita akan membangun pohon seimbang dengan 3 node.\n");
    printf("Silakan masukkan 3 karakter (dipisah spasi/enter) saat diminta.\n");
    
    PBalanced = BuildBalanceTree(3);
    
    printf("\nHasil Tree yang dibangun (BuildBalanceTree):\n");
    PrintTreeInden(PBalanced, 2);
    printf("\n----------------------------------------------------------------\n");

    /* 12. TEST IsBalanceTree */
    printf("[12] TEST IsBalanceTree\n");
    
    printf("Cek Pohon P (Awal): \n");
    PrintTreeInden(P, 2);
    if (IsBalanceTree(P)) {
        printf("-> Status: SEIMBANG (Balanced)\n");
    } else {
        printf("-> Status: TIDAK SEIMBANG\n");
    }

    printf("\nCek Pohon PBalanced (Barusan dibuat): \n");
    PrintTreeInden(PBalanced, 2);
    if (IsBalanceTree(PBalanced)) {
        printf("-> Status: SEIMBANG (Balanced)\n");
    } else {
        printf("-> Status: TIDAK SEIMBANG\n");
    }
    printf("\n----------------------------------------------------------------\n");

    printf("[13] TEST minTree dan maxTree\n");
    
    /* Test pada Pohon P */
    printf("Analisis Pohon P:\n");
    PrintTreeInden(P, 2);
    printf("Nilai Minimum (minTree) : %c\n", minTree(P));
    printf("Nilai Maksimum (maxTree): %c\n", maxTree(P));
    
    /* Test pada Pohon Balanced */
    printf("\nAnalisis Pohon PBalanced:\n");
    PrintTreeInden(PBalanced, 2);
    printf("Nilai Minimum (minTree) : %c\n", minTree(PBalanced));
    printf("Nilai Maksimum (maxTree): %c\n", maxTree(PBalanced));

    return 0;
}