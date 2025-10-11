"""
Diberikan suatu angka, carilah jumlah penjumlahan digitnya menggunakan rekursi.

Examples: 
    Input: 12345
    Output: 15
    Explanation: 1 + 2 + 3 + 4 + 5 = 15

    Input: 45632
    Output: 20
"""
def jumlah_digit(n):
    if n == 0:
        return 0
    else:
        return n % 10 + jumlah_digit(n // 10)
    
    
"""
Diberikan suatu angka. Berapa kali digit d muncul pada n? 

Examples:
    Input: 12344321, 4
    Output: 2
    Explanation: Digit 4 muncul sebanyak 2 kali pada angka 12344321

    Input: 11111, 1
    Output: 5
"""
def hitung_digit(n, d):
    if n == 0:
        return 0
    else:
        if n % 10 == d:
            return 1 + hitung_digit(n // 10, d)
        else:
            return hitung_digit(n // 10, d)