## **Pengertian Dasar**

- **Permutasi**: Suatu susunan dari elemen-elemen yang berbeda, di mana urutan sangat diperhatikan.
- **Kombinasi**: Suatu pemilihan dari elemen-elemen yang berbeda, di mana urutan tidak diperhatikan.

---

## **Permutasi**

### **Rumus Permutasi**:

Permutasi dari *n* elemen diambil *r* elemen:

$\Huge P(n, r) = \frac{n!}{(n-r)!}$

Di mana:
- $(n)$ = jumlah elemen total
- $(r)$ = jumlah elemen yang dipilih
- $(n!)$ = faktorial dari n, yang didefinisikan sebagai $( n! = n \times (n-1) \times (n-2) \times ... \times 1)$

### **Permutasi dengan Pengulangan**:
Jika ada elemen yang sama di antara elemen yang dipilih, permutasi dengan pengulangan dapat digunakan:

 $\Huge P = \frac{n!}{k_1! \times k_2! \times ... \times k_m!}$

Di mana $( k_1, k_2, ..., k_m )$ adalah jumlah elemen yang sama.

### **Contoh**:
Misalkan kita memiliki 3 huruf ${A, B, C}$. Berapa banyak cara kita dapat menyusunnya?

Permutasi dari 3 elemen:

 $P(3, 3) = \frac{3!}{(3-3)!} = 6$

Jadi ada 6 permutasi: $ABC, ACB, BAC, BCA, CAB, CBA.$

---

## **Kombinasi**

### **Rumus Kombinasi**:

Kombinasi dari *n* elemen diambil *r* elemen:

 $\huge C(n, r) = \frac{n!}{r! (n-r)!}$

Di mana:
- $( C(n, r) )$ disebut juga **koefisien binomial**.

### **Kombinasi dengan Pengulangan**:
Jika elemen dapat dipilih lebih dari sekali:
\
$\huge C = \frac{(n+r-1)!}{r!(n-1)!}$

### **Contoh**:
Jika kita memiliki 5 orang, dan ingin memilih 3 orang untuk tim. Berapa banyak cara kita bisa memilih 3 orang dari 5 orang?

Kombinasi dari 5 elemen diambil 3:

$C(5, 3) = \frac{5!}{3! (5-3)!} = 10$

Jadi ada 10 kombinasi yang bisa dipilih.

---

## **Perbedaan antara Permutasi dan Kombinasi**

| **Permutasi**                   | **Kombinasi**                  |
| ------------------------------- | ------------------------------ |
| Urutan diperhatikan             | Urutan tidak diperhatikan      |
| Digunakan untuk menyusun elemen | Digunakan untuk memilih elemen |
| Contoh: Susunan huruf           | Contoh: Pemilihan tim          |

---

## **Aplikasi Permutasi dan Kombinasi**

1. **Permutasi**: Digunakan dalam masalah yang melibatkan pengurutan, seperti menyusun angka, huruf, atau benda.
2. **Kombinasi**: Digunakan dalam masalah yang melibatkan pemilihan, seperti memilih anggota tim, memilih kombinasi pakaian, dsb.

---

## **Referensi**
- Struktur Diskrit oleh Rosen
- Teori Kombinatorika