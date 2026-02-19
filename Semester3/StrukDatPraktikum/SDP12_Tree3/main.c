/* File : main.c */
/* Deskripsi : Testing ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060124140166/Muhammad Farhan Abdul Azis */
/* Tanggal : 11 Desember 2025 */
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "list1.h"

int main() {
	//kamus
	bintree3 W;
	List1 L;
	
	//algoritma
W = Tree3(NIL, 'A', false, NIL, NIL);
        left(W) = Tree3(W, 'B', false, NIL, NIL);
            right(left(W)) = Tree3(left(W), 'D', false, NIL, NIL);
        right(W) = Tree3(W, 'C', false, NIL, NIL);
            left(right(W)) = Tree3(right(W), 'E', false, NIL, NIL);
            right(right(W)) = Tree3(right(W), 'F', false, NIL, NIL);

	printf("Test printDFS:\n");
	printf("   Output: ");
	printDFS(W);
	printf("\n\n");
	
	printf("Test IsEmptyTree:\n");
	printf("   IsEmptyTree(W) = %s\n", IsEmptyTree(W) ? "true" : "false");
	printf("   IsEmptyTree(NIL) = %s\n\n", IsEmptyTree(NIL) ? "true" : "false");
	
	printf("Test IsDaun:\n");
	printf("   IsDaun(W) = %s\n", IsDaun(W) ? "true" : "false");
	printf("   IsDaun(left(W)) = %s\n", IsDaun(left(W)) ? "true" : "false");
	printf("   IsDaun(right(left(W))) = %s\n\n", IsDaun(right(left(W))) ? "true" : "false");
	
	printf("Test IsBiner:\n");
	printf("   IsBiner(W) = %s\n", IsBiner(W) ? "true" : "false");
	printf("   IsBiner(left(W)) = %s\n\n", IsBiner(left(W)) ? "true" : "false");
	
	printf("Test IsUnerLeft:\n");
	printf("   IsUnerLeft(left(W)) = %s\n\n", IsUnerLeft(left(W)) ? "true" : "false");
	
	printf("Test IsUnerRight:\n");
	printf("   IsUnerRight(W) = %s\n\n", IsUnerRight(W) ? "true" : "false");
	
	printf("Test Tinggi:\n");
	printf("   Tinggi(W) = %d\n\n", Tinggi(W));
	
	printf("Test Max2:\n");
	printf("   Max2(5, 3) = %d\n\n", Max2(5, 3));
	
	printf("Test PrintLevel:\n");
	printf("   Level 0: ");
	PrintLevel(W, 0);
	printf("   Level 1: ");
	PrintLevel(W, 1);
	printf("   Level 2: ");
	PrintLevel(W, 2);
	printf("\n");
	
	printf("Test PrintBFS:\n");
	printf("   Output: ");
	PrintBFS(W);
	printf("\n\n");
		
	printf("Test resetVisited:\n");
	visited(W) = true;
	visited(left(W)) = true;
	printf("   Before resetVisited: visited(W) = %s\n", visited(W) ? "true" : "false");
	resetVisited(W);
	printf("   After resetVisited: visited(W) = %s\n\n", visited(W) ? "true" : "false");
	
	printf("Test printPathX (mencari 'D'):\n");
	printf("   Path: ");
	printPathX(W, 'D');
	printf("\n\n");
	
	printf("Test printPathDaunX (mencari daun 'D'):\n");
	printf("   Path: ");
	printPathDaunX(W, 'D');
	printf("\n\n");

	printf("Test NbElmTree:\n");
    printf("   Jumlah elemen pohon = %d\n\n", NbElmTree(W));

    printf("Test NbDaun:\n");
    printf("   Jumlah daun pohon = %d\n\n", NbDaun(W));

    printf("Test Level (Level suatu node):\n");
    printf("   Level Akar (A) = %d\n", Level(W));
    printf("   Level node B (Anak Kiri A) = %d\n", Level(left(W)));
    printf("   Level node D (Anak Kanan B) = %d\n\n", Level(right(left(W))));

    printf("Test CountLevelT (Jumlah node per level):\n");
    printf("   Jumlah node level 1 = %d\n", CountLevelT(W, 1));
    printf("   Jumlah node level 2 = %d\n", CountLevelT(W, 2));
    printf("   Jumlah node level 3 = %d\n\n", CountLevelT(W, 3));

	printf("Test LinearPrefix (PreOrder -> List):\n");
    L = LinearPrefix(W);
    printf("   List Prefix: ");
    PrintList(L);
    printf("\n");

    printf("Test LinearInfix (InOrder -> List):\n");
    L = LinearInfix(W);
    printf("   List Infix: ");
    PrintList(L);
    printf("\n");

    printf("Test LinearPosfix (PostOrder -> List):\n");
    L = LinearPosfix(W);
    printf("   List Posfix: ");
    PrintList(L);
    printf("\n");
	return 0;
}