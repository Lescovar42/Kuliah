/*Nama File 	: dekripsiCaesar.c*/
/*Deskripsi 	: Melakukan dekripsi pada string*/
/*Pembuat   	: 24060124130069-Muhammad Fikri*/
/*Tgl Pembuatan	: 4 April 2025 04.00*/

#include <stdio.h>
#include <string.h>

int hitungPanjang(const char *str)
{
    int panjang = 0;
    while (str[panjang] != '\0')
    {
        panjang++;
    }
    return panjang;
}

void dekripsiCaesar(char str[], int n)
{
    int len = hitungPanjang(str);

    for (int i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] - 'a' - n + 26) % 26) + 'a';
        }
    }

    printf("%s\n", str);
}

int main()
{
    int n;
    char str[105];

    scanf("%d", &n);
    scanf("%s", str);

    dekripsiCaesar(str, n);

    return 0;
}
