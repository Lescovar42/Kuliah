// test_mtabel.c
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "tabel.h"

void test_createTable() {
	Tabel T;
	createTable(&T);
	assert(getSize(T) == 0);
	for (int i = 1; i <= 10; i++) assert(T.wadah[i] == ' ');
	printf("test_createTable passed\n");
}

void test_addXTable_and_getSize() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	assert(getSize(T) == 2);
	assert(T.wadah[1] == 'A' && T.wadah[2] == 'B');
	printf("test_addXTable_and_getSize passed\n");
}

void test_isEmptyTable_and_isFullTable() {
	Tabel T;
	createTable(&T);
	assert(isEmptyTable(T));
	for (int i = 0; i < 10; i++) addXTable(&T, 'A'+i);
	assert(isFullTable(T));
	printf("test_isEmptyTable_and_isFullTable passed\n");
}

void test_searchX() {
	Tabel T;
	int pos;
	createTable(&T);
	addXTable(&T, 'C');
	addXTable(&T, 'D');
	searchX(T, 'C', &pos);
	assert(pos == 1);
	searchX(T, 'Z', &pos);
	assert(pos == -999);
	printf("test_searchX passed\n");
}

void test_countX() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	addXTable(&T, 'A');
	assert(countX(T, 'A') == 2);
	assert(countX(T, 'B') == 1);
	printf("test_countX passed\n");
}

void test_countVocal() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	addXTable(&T, 'I');
	addXTable(&T, 'O');
	assert(countVocal(T) == 3);
	printf("test_countVocal passed\n");
}

void test_addUniqueXTable() {
	Tabel T;
	createTable(&T);
	addUniqueXTable(&T, 'A');
	addUniqueXTable(&T, 'A');
	addUniqueXTable(&T, 'B');
	assert(getSize(T) == 2);
	assert(T.wadah[1] == 'A' && T.wadah[2] == 'B');
	printf("test_addUniqueXTable passed\n");
}

void test_delXTable() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	delXTable(&T, 'A');
	assert(getSize(T) == 1 && T.wadah[1] == 'B');
	printf("test_delXTable passed\n");
}

void test_delTable() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	addXTable(&T, 'C');
	delTable(&T, 2);
	assert(getSize(T) == 2 && T.wadah[1] == 'A' && T.wadah[2] == 'C');
	printf("test_delTable passed\n");
}

void test_delAllXTable() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	addXTable(&T, 'A');
	delAllXTable(&T, 'A');
	assert(getSize(T) == 1 && T.wadah[1] == 'B');
	printf("test_delAllXTable passed\n");
}

void test_printTable_and_viewTable() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	printf("Should print all (A B):\n");
	printTable(T);
	printf("Should print filled (A B):\n");
	viewTable(T);
	printf("test_printTable_and_viewTable passed (visual check)\n");
}

void test_Modus() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	addXTable(&T, 'A');
	assert(Modus(T) == 'A');
	printf("test_Modus passed\n");
}

void test_isEqualTable() {
	Tabel T1, T2;
	createTable(&T1); createTable(&T2);
	addXTable(&T1, 'A'); addXTable(&T2, 'A');
	addXTable(&T1, 'B'); addXTable(&T2, 'B');
	assert(isEqualTable(T1, T2));
	addXTable(&T2, 'C');
	assert(!isEqualTable(T1, T2));
	printf("test_isEqualTable passed\n");
}

void test_getInverseTable_and_inverseTable() {
	Tabel T, Inv;
	createTable(&T);
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	addXTable(&T, 'C');
	Inv = getInverseTable(T);
	assert(Inv.wadah[1] == 'C' && Inv.wadah[2] == 'B' && Inv.wadah[3] == 'A');
	inverseTable(&T);
	assert(T.wadah[1] == 'C' && T.wadah[2] == 'B' && T.wadah[3] == 'A');
	printf("test_getInverseTable_and_inverseTable passed\n");
}

void test_sortAsc_and_sortDesc() {
	Tabel T;
	createTable(&T);
	addXTable(&T, 'C');
	addXTable(&T, 'A');
	addXTable(&T, 'B');
	sortAsc(&T);
	assert(T.wadah[1] == 'A' && T.wadah[2] == 'B' && T.wadah[3] == 'C');
	sortDesc(&T);
	assert(T.wadah[1] == 'C' && T.wadah[2] == 'B' && T.wadah[3] == 'A');
	printf("test_sortAsc_and_sortDesc passed\n");
}

int main() {
	test_createTable();
	test_addXTable_and_getSize();
	test_isEmptyTable_and_isFullTable();
	test_searchX();
	test_countX();
	test_countVocal();
	test_addUniqueXTable();
	test_delXTable();
	test_delTable();
	test_delAllXTable();
	test_printTable_and_viewTable();
	// Skipping test for populateTable (requires input)
	test_Modus();
	test_isEqualTable();
	test_getInverseTable_and_inverseTable();
	test_sortAsc_and_sortDesc();
	printf("All tests passed!\n");
	return 0;
}