import math

def no_digits(num):
    return math.floor(math.log10(abs(num)))

print(no_digits(5500005))