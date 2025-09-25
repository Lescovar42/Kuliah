def WeightedSum(n1,n2,n3,n4,w1,w2,w3,w4):
    return (n1*w1)+(n2*w2)+(n3*w3)+(n4*w4)

def TotalWeight(w1,w2,w3,w4):
    return w1+w2+w3+w4

def Average(n1,n2,n3,n4,w1,w2,w3,w4):
    return WeightedSum(n1,n2,n3,n4,w1,w2,w3,w4)/TotalWeight(w1,w2,w3,w4)

print(Average(5,10.3,13,21,1,2,3,4))
