def MakePoint(x,y):
    return[x,y]

def absis(P):
    return P[0]

def ordinat(P):
    return P[1]

def IsOrigin(P):
    if absis(P) == 0 and ordinat(P) == 0:
        return True
    else:
        return False
    
print(absis(MakePoint(1,5)))