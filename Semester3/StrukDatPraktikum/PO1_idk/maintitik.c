/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 4 September 2025*/
/***********************************/
#include <stdio.h>
#include "titik.c"

int main() {
	//kamus main
	Titik T1;
	Titik T2;
	
	//algoritma
	printf("Halo, ini driver modul Titik \n");

	makeTitik(&T1,4,5);
	printf("\nNilai absis = %d",getAbsis(T1));
	printf("\nNilai ordinat = %d",getOrdinat(T1));

    setAbsis(&T1, 10);
    setOrdinat(&T1, 15);
    printf("\nSetelah diubah:");
    printf("\nNilai absis = %d",getAbsis(T1));
    printf("\nNilai ordinat = %d",getOrdinat(T1));

    geser(&T1, -3, 2);
    printf("\nSetelah digeser:");
    printf("\nNilai absis = %d",getAbsis(T1));
    printf("\nNilai ordinat = %d",getOrdinat(T1));

	refleksiX(&T1);
	printf("\nSetelah refleksi terhadap sumbu X:");
	printf("\nNilai absis = %d",getAbsis(T1));
	printf("\nNilai ordinat = %d",getOrdinat(T1));

	refleksiY(&T1);
	printf("\nSetelah refleksi terhadap sumbu Y:");
	printf("\nNilai absis = %d",getAbsis(T1));
	printf("\nNilai ordinat = %d",getOrdinat(T1));

	dilatasi(&T1, 2.0);
	printf("\nSetelah dilatasi:");
	printf("\nNilai absis = %d",getAbsis(T1));
	printf("\nNilai ordinat = %d",getOrdinat(T1));

	makeTitik(&T2,5,8);
	dilatasiX(&T1, T2, 0.5);
	printf("\nSetelah dilatasi terhadap titik T2:");
	printf("\nNilai absis = %d",getAbsis(T1));
	printf("\nNilai ordinat = %d",getOrdinat(T1));

	kuadran(T1);
	printf("\nTitik berada pada kuadran ke-%d", kuadran(T1));
	return 0;
}