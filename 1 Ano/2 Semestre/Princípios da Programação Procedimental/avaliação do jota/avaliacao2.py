import math

def serieLogaritmo(x,a,p):
    log=0
    n=1
    while abs((((-1)**(n-1))/(n*(a**n))) * ((x-a)**n) )>=p:
        log += ((-1)**(n-1))/(n*(a**n)) * ((x-a)**n)
        n+=1
    return log,n

print(serieLogaritmo(1.5,2,1e-6))





