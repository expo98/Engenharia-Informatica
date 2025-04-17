def factorial(n):
    for i in range (n-1,1,-1):
        n *= i
    return n



def obter_seno(parcelas,x):
    seno=0
    for i in range(parcelas):
        seno += (((-1)**i) * (x**((2*x)+1))) / factorial((2*i)+1)
    return seno


print(obter_seno(999999,3))
        

