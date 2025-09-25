/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060124140166/Muhammad Farhan Abdul Azis*/
/* Tanggal   : 18 September 2025*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M){
    int i,j;
    for (i=1;i<=10;i++){ /*baris ke-i: 1..10 valid */
        for (j=1;j<=10;j++){ /*kolom ke-j: 1..10 valid */
            M->cell[i][j]=-999; /*inisialisasi elemen matriks dengan -999*/
        }
    }
    M->nbaris=0;
    M->nkolom=0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M){
    return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M){
    return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M){
    return (M.nbaris == 0 && M.nkolom == 0);
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M){
    return (M.nbaris == 10 && M.nkolom == 10);
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col){
    /* NOTE: this function wasn't requested to be fully corrected here.
       Keeping the original structure but fix only the obvious assignment bug
       would be fine; however we keep minimal behavior: place X if cell is -999
       and update nbaris/nkolom simply. */
    if (row < 1 || row > 10 || col < 1 || col > 10) return;
    if (!isFullMatriks(*M) && M->cell[row][col] == -999) {
        M->cell[row][col] = X;
        if (row > M->nbaris) M->nbaris = row;
        if (col > M->nkolom) M->nkolom = col;
    }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X){
    int i,j;
    int delRow = -1, delCol = -1;
    for (i = 1; i <= M->nbaris && delRow == -1; i++) {
        for (j = 1; j <= M->nkolom; j++) {
            if (M->cell[i][j] == X) { delRow = i; delCol = j; break; }
        }
    }
    if (delRow != -1 && delCol != -1) {
        M->cell[delRow][delCol] = -999;

        /* recompute nbaris and nkolom conservatively:
           find highest row/index that still has any non -999 */
        int maxRow = 0, maxCol = 0;
        for (i = 1; i <= 10; i++) {
            for (j = 1; j <= 10; j++) {
                if (M->cell[i][j] != -999) {
                    if (i > maxRow) maxRow = i;
                    if (j > maxCol) maxCol = j;
                }
            }
        }
        M->nbaris = maxRow;
        M->nkolom = maxCol;
    }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y){
    int i,j;
    if (x < 1 || x > 10 || y < 1 || y > 10) return;
    for (i=1;i<=x;i++){
        for (j=1;j<=y;j++){
            M->cell[i][j]=rand()%100;
        }
    }
    M->nbaris=x;
    M->nkolom=y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n){
    int i,j;
    if (n < 1 || n > 10) return;
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            if (i==j){
                M->cell[i][j]=1;
            } else {
                M->cell[i][j]=0;
            }
        }
    }
    M->nbaris=n;
    M->nkolom=n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y){
    int i,j;
    if (x < 1 || x > 10 || y < 1 || y > 10) return;
    for (i=1;i<=x;i++){
        for (j=1;j<=y;j++){
            printf("Masukkan elemen baris %d kolom %d: ",i,j);
            scanf("%d",&M->cell[i][j]);
        }
    }
    M->nbaris=x;
    M->nkolom=y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M){
    int i,j;
    for (i=1;i<=M.nbaris;i++){
        for (j=1;j<=M.nkolom;j++){
            if (M.cell[i][j] != -999)
                printf("%d ",M.cell[i][j]);
            else
                printf("-   ");
        }
        printf("\n");
    }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M){
    int i,j;
    for (i=1;i<=M.nbaris;i++){
        for (j=1;j<=M.nkolom;j++){
            if (M.cell[i][j]!=-999){
                printf("%d ",M.cell[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2){
    int i, j;
    Matriks M3;
    initMatriks(&M3);

    /* determine output size: max of both matrices */
    int outRows = (M1.nbaris > M2.nbaris) ? M1.nbaris : M2.nbaris;
    int outCols = (M1.nkolom > M2.nkolom) ? M1.nkolom : M2.nkolom;
    if (outRows == 0 || outCols == 0) {
        /* both empty -> return empty initialized M3 */
        return M3;
    }

    for (i = 1; i <= outRows; i++) {
        for (j = 1; j <= outCols; j++) {
            int a = (i <= M1.nbaris && j <= M1.nkolom) ? M1.cell[i][j] : -999;
            int b = (i <= M2.nbaris && j <= M2.nkolom) ? M2.cell[i][j] : -999;

            if (a != -999 && b != -999) {
                M3.cell[i][j] = a + b;
            } else if (a != -999) {
                M3.cell[i][j] = a;
            } else if (b != -999) {
                M3.cell[i][j] = b;
            } else {
                M3.cell[i][j] = -999;
            }
        }
    }

    M3.nbaris = outRows;
    M3.nkolom = outCols;
    return M3;
}


/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2)
{
    int i, j;
    Matriks M3;
    initMatriks(&M3);

    int outRows = (M1.nbaris > M2.nbaris) ? M1.nbaris : M2.nbaris;
    int outCols = (M1.nkolom > M2.nkolom) ? M1.nkolom : M2.nkolom;
    if (outRows == 0 || outCols == 0) return M3;

    for (i = 1; i <= outRows; i++) {
        for (j = 1; j <= outCols; j++) {
            int a = (i <= M1.nbaris && j <= M1.nkolom) ? M1.cell[i][j] : -999;
            int b = (i <= M2.nbaris && j <= M2.nkolom) ? M2.cell[i][j] : -999;

            if (a != -999 && b != -999) {
                M3.cell[i][j] = a - b;
            } else if (a != -999) {
                M3.cell[i][j] = a;
            } else if (b != -999) {
                M3.cell[i][j] = -b;
            } else {
                M3.cell[i][j] = -999;
            }
        }
    }

    M3.nbaris = outRows;
    M3.nkolom = outCols;
    return M3;
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2)
{
    int i, j, k;
    Matriks M3;
    initMatriks(&M3);

    if (M1.nbaris == 0 || M1.nkolom == 0 || M2.nbaris == 0 || M2.nkolom == 0) {
        return M3;
    }
    if (M1.nkolom != M2.nbaris) {
        return M3;
    }

    M3.nbaris = M1.nbaris;
    M3.nkolom = M2.nkolom;

    for (i = 1; i <= M1.nbaris; i++) {
        for (j = 1; j <= M2.nkolom; j++) {
            int sum = 0;
            int any = 0;
            for (k = 1; k <= M1.nkolom; k++) {
                int a = M1.cell[i][k];
                int b = M2.cell[k][j];
                if (a != -999 && b != -999) {
                    sum += a * b;
                    any = 1;
                } else {
                }
            }
            if (any) {
                M3.cell[i][j] = sum;
            } else {
                M3.cell[i][j] = -999;
            }
        }
    }

    return M3;
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x)
{
    int i, j;
    Matriks M2;
    initMatriks(&M2);

    if (M1.nbaris == 0 || M1.nkolom == 0) return M2;

    for (i = 1; i <= M1.nbaris; i++)
    {
        for (j = 1; j <= M1.nkolom; j++)
        {
            if (M1.cell[i][j] != -999)
            {
                M2.cell[i][j] = M1.cell[i][j] * x;
            } else {
                M2.cell[i][j] = -999;
            }
        }
    }

    M2.nbaris = M1.nbaris;
    M2.nkolom = M1.nkolom;

    return M2;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M)
{
    int i, j, temp;
    int maxDim;

    if ((*M).nbaris > (*M).nkolom)
    {
        maxDim = (*M).nbaris;
    }
    else
    {
        maxDim = (*M).nkolom;
    }

    for (i = 1; i <= maxDim; i++)
    {
        for (j = i + 1; j <= maxDim; j++)
        {
            temp = (*M).cell[i][j];
            (*M).cell[i][j] = (*M).cell[j][i];
            (*M).cell[j][i] = temp;
        }
    }

    temp = (*M).nbaris;
    (*M).nbaris = (*M).nkolom;
    (*M).nkolom = temp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M)
{
    int i, j;
    Matriks MOut;
    initMatriks(&MOut);

    for (i = 1; i <= M.nbaris; i++)
    {
        for (j = 1; j <= M.nkolom; j++)
        {
            if (M.cell[i][j] != -999)
            {
                MOut.cell[j][i] = M.cell[i][j];
            }
        }
    }

    MOut.nbaris = M.nkolom;
    MOut.nkolom = M.nbaris;

    return MOut;
}

/* function addPadding(M: Matriks, input n:integer)
	{menghasilkan matriks baru dari M yang ditambahkan padding 0 sesuai dengan ukuran padding n */
Matriks addPadding(Matriks M, int n)
{
    int i, j;
    Matriks MPad;
    initMatriks(&MPad);
    if (n < 0) return M;
    if (!isFullMatriks(M) && M.nbaris + (2 * n) <= 10 && M.nkolom + (2 * n) <= 10)
    {
        for (i = 1; i <= M.nbaris; i++)
        {
            for (j = 1; j <= M.nkolom; j++)
            {
                MPad.cell[i + n][j + n] = M.cell[i][j];
            }
        }

        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= M.nkolom + (2 * n); j++)
            {
                MPad.cell[i][j] = 0;
                MPad.cell[M.nbaris + n + i][j] = 0;
            }
        }

        for (i = n + 1; i <= M.nbaris + n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                MPad.cell[i][j] = 0;
                MPad.cell[i][M.nkolom + n + j] = 0;
            }
        }

        MPad.nbaris = M.nbaris + (2 * n);
        MPad.nkolom = M.nkolom + (2 * n);
        return MPad;
    }
    else
    {
        return M;
    }
}

/* function maxPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil max pooling matriks M dengan pool size = size  */
Matriks maxPooling(Matriks M, int size)
{
    int i, j, m, n;
    int maxVal;
    Matriks MPool;
    initMatriks(&MPool);

    if (!isFullMatriks(M) && size > 0 && M.nbaris % size == 0 && M.nkolom % size == 0)
    {
        MPool.nbaris = M.nbaris / size;
        MPool.nkolom = M.nkolom / size;

        for (i = 1; i <= MPool.nbaris; i++)
        {
            for (j = 1; j <= MPool.nkolom; j++)
            {
                maxVal = -999;
                for (m = 1; m <= size; m++)
                {
                    for (n = 1; n <= size; n++)
                    {
                        int val = M.cell[(i - 1) * size + m][(j - 1) * size + n];
                        if (val != -999 && (maxVal == -999 || val > maxVal))
                        {
                            maxVal = val;
                        }
                    }
                }
                if (maxVal != -999) MPool.cell[i][j] = maxVal;
                else MPool.cell[i][j] = -999;
            }
        }
        return MPool;
    }
    else
    {
        return M;
    }
}

/* function avgPooling(M: Matriks, input size:integer)
	{menghasilkan matriks hasil average pooling matriks M dengan pool size = size  */
Matriks avgPooling(Matriks M, int size)
{
    int i, j, m, n;
    int sumVal;
    int count;
    Matriks MPool;
    initMatriks(&MPool);

    if (!isFullMatriks(M) && size > 0 && M.nbaris % size == 0 && M.nkolom % size == 0)
    {
        MPool.nbaris = M.nbaris / size;
        MPool.nkolom = M.nkolom / size;

        for (i = 1; i <= MPool.nbaris; i++)
        {
            for (j = 1; j <= MPool.nkolom; j++)
            {
                sumVal = 0;
                count = 0;
                for (m = 1; m <= size; m++)
                {
                    for (n = 1; n <= size; n++)
                    {
                        int val = M.cell[(i - 1) * size + m][(j - 1) * size + n];
                        if (val != -999) {
                            sumVal += val;
                            count++;
                        }
                    }
                }
                if (count > 0) MPool.cell[i][j] = sumVal / count;
                else MPool.cell[i][j] = -999;
            }
        }
        return MPool;
    }
    else
    {
        return M;
    }
}

/* function conv(M: Matriks, K:Matriks)
	{menghasilkan matriks hasil konvolusi matriks M dengan kernel K  */
Matriks conv(Matriks M, Matriks K)
{
    int i, j, m, n;
    int sumVal;
    Matriks MConv;
    initMatriks(&MConv);

    if (!isFullMatriks(M) && !isFullMatriks(K) && K.nbaris % 2 == 1 && K.nkolom % 2 == 1 && M.nbaris >= K.nbaris && M.nkolom >= K.nkolom)
    {
        MConv.nbaris = M.nbaris - K.nbaris + 1;
        MConv.nkolom = M.nkolom - K.nkolom + 1;

        for (i = 1; i <= MConv.nbaris; i++)
        {
            for (j = 1; j <= MConv.nkolom; j++)
            {
                sumVal = 0;
                for (m = 1; m <= K.nbaris; m++)
                {
                    for (n = 1; n <= K.nkolom; n++)
                    {
                        int a = M.cell[i + m - 1][j + n - 1];
                        int b = K.cell[m][n];
                        if (a != -999 && b != -999) {
                            sumVal += a * b;
                        } else {
                        }
                    }
                }
                MConv.cell[i][j] = sumVal;
            }
        }
        return MConv;
    }
    else
    {
        return M;
    }
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col){
    int i,j;
    *row = -999;
    *col = -999;
    for (i=1;i<=M.nbaris;i++){
        for (j=1;j<=M.nkolom;j++){
            if (M.cell[i][j]==X){
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X){
    int i,j;
    int count;
    count=0;
    for (i=1;i<=M.nbaris;i++){
        for (j=1;j<=M.nkolom;j++){
            if (M.cell[i][j]==X){
                count++;
            }
        }
    }
    return count;
}
