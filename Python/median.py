def max2(a,b):
     return ((a+b) + abs(a-b)) / 2
 
def min2(a,b):
     return ((a+b) - abs(a-b)) / 2

def max3(a,b,c):
     return ((c+max2(a,b)) + abs(max2(a,b)-c)) / 2

def min3(a,b,c):
     return ((c+min2(a,b)) - abs(min2(a,b)-c)) / 2    

def med(a,b,c):
     return (a+b+c - max3(a,b,c)-min3(a,b,c))

print(med(14,25.5,10))
